#pragma once
#include "Common.hpp"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <utility>

using namespace std;

struct KeyOfValue;
template <class ValueType, class KOFV, class KTOINT>
class HashTable;

template<class ValueType>
struct HashTableNode
{
	HashTableNode(const ValueType& data)
		: _pNext(nullptr)
		, _data(data)
	{}
	HashTableNode<ValueType>* _pNext;
	ValueType _data;
};

template <class ValueType, class KOFV, class KTOINT>
class HashTable;

template <class ValueType, class KOFV, class KTOINT>
class HashTableIterator
{
	typedef HashTableNode<ValueType> HTNode;
	typedef HTNode* pHTNode;
	typedef HashTableIterator<ValueType, KOFV, KTOINT> Self;
	typedef HashTable<ValueType, KOFV, KTOINT> HashTable;
public:
	HashTableIterator(HashTable* pHT, pHTNode pNode = nullptr)
		: _pNode(pNode)
		, _table(pHT)
	{}

	HashTableIterator(const Self& s)
		: _pNode(s._pNode)
		, _table(s._table)
	{}

	ValueType& operator*()//�����÷���ֵ���data
	{
		return _pNode->_data;
	}

	ValueType* operator->()//����data�е�����
	{
		return &(operator*());
	}

	Self& operator++()//ǰ��++
	{
		Next();
		return *this;
	}

	Self operator++(int)
	{
		Self temp(*this);
		Next();
		return temp;
	}

	bool operator==(const Self& s) const
	{
		return (_pNode == s._pNode) && (_table == s._table);
	}

	bool operator!=(const Self& s) const
	{
		return !(*this == s);
	}

private:
	void Next()
	{
		if (_pNode->_pNext)
			_pNode = _pNode->_pNext;
		else
		{
			size_t bucketNo = _table->HashFunc(_pNode->_data) + 1;
			for (; bucketNo < _table->_table.capacity(); bucketNo++)
			{
				_pNode = _table->_table[bucketNo];
				if (_pNode)
					return;
			}
			_pNode = nullptr;
		}
	}

private:
	pHTNode _pNode;//��ǰ������������Ľڵ�
	HashTable* _table;
};

template <class ValueType, class KOFV, class KTOINT>
class HashTable;

template <class ValueType, class KOFV, class KTOINT>
class HashTable
{
	friend class KeyToInt<ValueType>;
	friend class HashTableIterator<ValueType, KOFV, KTOINT>;//�������������ǹ�ϣ�������Ԫ��--��ʾ����������Է��ʹ�ϣ�����˽�г�Ա
	typedef HashTableNode<ValueType> HTNode;
	typedef HTNode* pHTNode;
	typedef HashTableIterator<ValueType, KOFV, KTOINT> Iterator;
	typedef HashTable<ValueType, KOFV, KTOINT> Self;
public:
	HashTable(size_t capacity = 11)
		: _table(capacity)
		, _size(0)
	{}

	//����Ψһ
	//emplace �� insert������insert�ڲ���Ĺ����д�������������emplace�Ĳ����ǲ����ģ����������ֻ����һ������
	std::pair<Iterator, bool> InsertUnique(const ValueType& data)
	{
		//1, �������
		CheckCapacity();
		//2�������ϣ��ַ----�ù�ϣ����
		size_t bucketNo = HashFunc(data);
		//3, ���������Ƿ�����ڹ�ϣͰ��
		pHTNode pCur = _table[bucketNo];

		while (pCur)
		{
			if (KOFV()(data) == KOFV()(pCur->_data))
			{
				return make_pair(Iterator(this, pCur), false);
			}
			pCur = pCur->_pNext;
		}
		//�ߵ���һ��˵�����Բ��������
		
		//��ͷ�壬O(1);
		pCur = new HTNode(data);
		pCur->_pNext = _table[bucketNo];
		_table[bucketNo] = pCur;
		++_size;
		return make_pair(Iterator(this, pCur), true);
	}

	//ɾ��Ψһ
	size_t EraseUnique(const ValueType& data)
	{
		//�������������һ����ϣͰ
		size_t bucketNo = HashFunc(data);
		//���Ҹ������Ƿ�����ڸù�ϣͰ��
		pHTNode pCur = _table[bucketNo];
		pHTNode pPre = nullptr;
		while (pCur)
		{
			if (KOFV()(data) == KOFV()(pCur->_data))
			{
				//�ҵ���---ɾ��
				if (pPre == nullptr)
				{
					//ɾ����һ���ڵ�
					_table[bucketNo] = pCur->_pNext;
				}
				else
				{
					//ɾ���Ĳ��ǵ�һ���ڵ�
					pPre->_pNext = pCur->_pNext;
				}
				delete pCur;
				--_size;
				return 1;
			}
			pPre = pCur;
			pCur = pCur->_pNext;
		}
		return 0;
	}

	//�����ظ�������
	Iterator InsertEqual(const ValueType& data)
	{
		//1, �������
		CheckCapacity();
		//2�������ϣ��ַ----�ù�ϣ����
		size_t bucketNo = HashFunc(data);
		//3, ����ͬ�����ݲ���һ�𣬲��ҳ�������
		pHTNode pCur = _table[bucketNo];
		pHTNode pNewNode = new HTNode(data);
		while (pCur)
		{
			if (KOFV()(data) == KOFV()(pCur->_data))
			{
				break;
			}
			else
			{
				pCur = pCur->_pNext;
			}
		}
		if (pCur == nullptr)
		{
			pNewNode->_pNext = _table[bucketNo];
			_table[bucketNo] = pNewNode;
		}
		else
		{
			pNewNode->_pNext = pCur->_pNext;
			pCur->_pNext = pNewNode;
		}
		++_size;
		return Iterator(this, pNewNode);
	}

	//ɾ���ظ�������
	size_t EraseEqual(const ValueType& data)
	{
		//ȷ��Ͱ��
		size_t bucketNo = HashFunc(data);
		size_t old_size = _size;

		//����ɾ���Ľڵ�
		pHTNode pCur = _table[bucketNo];
		pHTNode pPre = nullptr;
		while (pCur)
		{
			if (KOFV()(data) == KOFV()(pCur->_data))
			{
				if (pPre == nullptr)
				{
					//ɾ����һ���ڵ�
					_table[bucketNo] = pCur->_pNext;
					delete pCur;
					pCur = _table[bucketNo];
				}
				else
				{
					//ɾ���м�ڵ�
					pPre->_pNext = pCur->_pNext;
					delete pCur;
					pCur = pPre->_pNext;
				}
				--_size;
			}
			else
			{
				pPre = pCur;
				pCur = pCur->_pNext;
			}
		}
		return old_size - _size;
	}

	Iterator Begin()
	{
		for (size_t bucketNo = 0; bucketNo < _table.capacity(); bucketNo++)
		{
			if (_table[bucketNo])
				return Iterator(this, _table[bucketNo]);
		}
		return End();
	}

	Iterator End()
	{
		return Iterator(this, nullptr);
	}

	size_t Empty() const
	{
		return 0 == _size;//�շ���1
	}

	size_t Size() const
	{
		return _size;
	}

	//����
	Iterator Find(const ValueType& data)
	{
		size_t bucketNo = HashFunc(data);
		pHTNode pCur = _table[bucketNo];
		while (pCur)
		{
			if (KOFV()(data) == KOFV()(pCur->_data))
				return Iterator(this, pCur);

			pCur = pCur->_pNext;
		}

		return End();
	}

	//����һ�������ڹ�ϣ��Ͱ�еĸ���
	size_t Count(const ValueType& data)
	{
		size_t bucketNo = HashFunc(data);
		size_t count = 0;
		pHTNode pCur = _table[bucketNo];
		while (pCur)
		{
			if (KOFV()(data) == KOFV()(pCur->_data))
				count++;

			pCur = pCur->_pNext;
		}

		return count;
	}

	//��չ�ϣ��
	void Clear()
	{
		//����ÿһ��Ͱ��Ȼ��ͷɾ
		for (size_t i = 0; i < _table.capacity(); i++)
		{
			pHTNode pCur = _table[i];
			while (pCur)
			{
				_table[i] = pCur->_pNext;
				delete pCur;
				pCur = _table[i];
			}
		}
		_size = 0;
	}

	//��������
	void Swap(HashTable<ValueType, KOFV, KTOINT>& ht)
	{
		_table.swap(ht._table);
		swap(_size, ht._size);
	}
	
	//����Ͱ�ĸ���
	size_t BucketCount()const
	{
		return _table.capacity();
	}

	//����ָ��Ͱ�е����ݸ���
	size_t BucketSize(size_t num)const
	{
		pHTNode pCur = _table[num];
		size_t count = 0;
		while (pCur)
		{
			++count;
			pCur = pCur->_pNext;
		}
		return count;
	}

	void PrintHashTable()
	{
		for (size_t i = 0; i < _table.capacity(); i++)
		{
			std::cout << "���ǵ�" << i << "��Ͱ: ";
			pHTNode pCur = _table[i];
			while (pCur)
			{
				std::cout << pCur->_data << "-->";
				pCur = pCur->_pNext;
			}
			std::cout << "NULL" <<  std::endl;
		}
	}
private:
	size_t HashFunc(const ValueType& data)
	{
		return KTOINT()(KOFV()(data)) % _table.capacity();
	}

	void CheckCapacity()
	{
		if (_size == _table.capacity())
		{
			Self NewHashTable(GetNextPrime(_table.capacity()));
			//��ʽһ:
			/*for (size_t i = 0; i < _table.capacity(); i++)
			{
				pHTNode pCur = _table[i];
				while (pCur)
				{
					NewHashTable.InsertEqual(pCur->_data);//�ഴ����һ�ݽڵ㣬�˷ѿռ�
					pCur = pCur->_pNext;
				}
			}
			this->Swap(newHashTable);*/
			//ȱ��: ����ÿ��Ͱ��Ȼ���ڲ��룬�����ǰɹ�ϣ���еĽڵ㷭���ˣ������Ľڵ���ԣ������Ľڵ�Ч�ʺܵ�

			for (size_t i = 0; i < _table.capacity(); i++)
			{
				//�ҵ�i��Ͱ
				pHTNode pCur = _table[i];
				while (pCur)
				{
					_table[i] = pCur->_pNext;//��pCur���뵽�µĹ�ϣ���У�

					//�ж�����ڵ����¹�ϣͰ����һ��Ͱ
					size_t bucketNo = NewHashTable.HashFunc(pCur->_data);
					//�ж�����ڵ���Ͱ����һ��λ��
					pHTNode pPos = NewHashTable._table[bucketNo];
					while (pPos)
					{
						if (KOFV()(pCur->_data) == KOFV()(pPos->_data))
						{
							break;
						}
						pPos = pPos->_pNext;
					}
					if (pPos == nullptr)
					{
						//û�ҵ�����˵���Ͱ�������ݣ�ֱ��ͷ��
						pCur->_pNext = NewHashTable._table[bucketNo];
						NewHashTable._table[bucketNo] = pCur;
					}
					else
					{
						//�ҵ��ˣ��Ͳ��ڸ�λ�õĺ���
						pCur->_pNext = pPos->_pNext;
						pPos->_pNext = pCur;
					}

					pCur = _table[i];
				}
			}
			this->Swap(NewHashTable);
		}
	}
private:
	std::vector<pHTNode> _table;
	size_t _size;
};

struct KeyOfValue
{
	int operator()(int data)
	{
		return data;
	}
};

void TestHashTable()
{
#if 0
	//���Բ���Ψһ
	int array[] = { 1, 3, 4, 5, 2, 13, 31, 25, 75, 87, 1,65, 76, 17, 4};
	HashTable<int, KeyOfValue, KeyToInt<int>> ht;
	for (auto &e : array)
	{
		ht.InsertUnique(e);
	}
	ht.PrintHashTable();
	std::cout << "-------------------------------------" << std::endl;
	HashTableIterator<int, KeyOfValue, KeyToInt<int>> it = ht.Begin();
	while (it != ht.End())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	cout << "4��Ͱ�Ĵ�СΪ : " << ht.BucketSize(4) << endl;
	ht.EraseUnique(4);
	std::cout << "-------------------------------------" << std::endl;
	ht.PrintHashTable();
	cout << "Ͱ�ĸ��� : " << ht.BucketCount() << endl;
	cout << "4��Ͱ�Ĵ�СΪ : " << ht.BucketSize(4) << endl;
#endif
#if 0
	//���Բ����ظ�
	int array[] = { 1, 3, 4, 5, 2, 13, 31, 25, 75, 87, 1, 65, 76, 17, 4 };
	HashTable<int, KeyOfValue, KeyToInt<int>> ht;
	for (auto &e : array)
	{
		ht.InsertEqual(e);
	}
	ht.PrintHashTable();
	std::cout << "-------------------------------------" << std::endl;
	HashTableIterator<int, KeyOfValue, KeyToInt<int>> it = ht.Begin();
	while (it != ht.End())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	cout << "4��Ͱ�Ĵ�СΪ : " << ht.BucketSize(4) << endl;
	ht.EraseEqual(4);
	std::cout << "-------------------------------------" << std::endl;
	ht.PrintHashTable();
	cout << "Ͱ�ĸ��� : " << ht.BucketCount() << endl;
	cout << "4��Ͱ�Ĵ�СΪ : " << ht.BucketSize(4) << endl;
#endif
}