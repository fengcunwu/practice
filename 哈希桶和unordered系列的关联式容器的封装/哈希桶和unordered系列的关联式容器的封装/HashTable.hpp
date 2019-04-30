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

	ValueType& operator*()//介引用返回值域的data
	{
		return _pNode->_data;
	}

	ValueType* operator->()//访问data中的内容
	{
		return &(operator*());
	}

	Self& operator++()//前置++
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
	pHTNode _pNode;//当前迭代器所管理的节点
	HashTable* _table;
};

template <class ValueType, class KOFV, class KTOINT>
class HashTable;

template <class ValueType, class KOFV, class KTOINT>
class HashTable
{
	friend class KeyToInt<ValueType>;
	friend class HashTableIterator<ValueType, KOFV, KTOINT>;//声明迭代器类是哈希表类的友元类--表示迭代器类可以访问哈希表类的私有成员
	typedef HashTableNode<ValueType> HTNode;
	typedef HTNode* pHTNode;
	typedef HashTableIterator<ValueType, KOFV, KTOINT> Iterator;
	typedef HashTable<ValueType, KOFV, KTOINT> Self;
public:
	HashTable(size_t capacity = 11)
		: _table(capacity)
		, _size(0)
	{}

	//插入唯一
	//emplace 和 insert的区别，insert在插入的过程中创建了两个对象，emplace的参数是不定的，插入过程中只创建一个对象
	std::pair<Iterator, bool> InsertUnique(const ValueType& data)
	{
		//1, 检测容量
		CheckCapacity();
		//2，计算哈希地址----用哈希函数
		size_t bucketNo = HashFunc(data);
		//3, 检测该数据是否存在于哈希桶中
		pHTNode pCur = _table[bucketNo];

		while (pCur)
		{
			if (KOFV()(data) == KOFV()(pCur->_data))
			{
				return make_pair(Iterator(this, pCur), false);
			}
			pCur = pCur->_pNext;
		}
		//走到这一步说明可以插入该数据
		
		//用头插，O(1);
		pCur = new HTNode(data);
		pCur->_pNext = _table[bucketNo];
		_table[bucketNo] = pCur;
		++_size;
		return make_pair(Iterator(this, pCur), true);
	}

	//删除唯一
	size_t EraseUnique(const ValueType& data)
	{
		//计算该数据在哪一个哈希桶
		size_t bucketNo = HashFunc(data);
		//查找该数据是否存在于该哈希桶中
		pHTNode pCur = _table[bucketNo];
		pHTNode pPre = nullptr;
		while (pCur)
		{
			if (KOFV()(data) == KOFV()(pCur->_data))
			{
				//找到了---删除
				if (pPre == nullptr)
				{
					//删除第一个节点
					_table[bucketNo] = pCur->_pNext;
				}
				else
				{
					//删除的不是第一个节点
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

	//插入重复的数据
	Iterator InsertEqual(const ValueType& data)
	{
		//1, 检测容量
		CheckCapacity();
		//2，计算哈希地址----用哈希函数
		size_t bucketNo = HashFunc(data);
		//3, 让相同的数据插在一起，查找出入数据
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

	//删除重复的数据
	size_t EraseEqual(const ValueType& data)
	{
		//确定桶号
		size_t bucketNo = HashFunc(data);
		size_t old_size = _size;

		//查找删除的节点
		pHTNode pCur = _table[bucketNo];
		pHTNode pPre = nullptr;
		while (pCur)
		{
			if (KOFV()(data) == KOFV()(pCur->_data))
			{
				if (pPre == nullptr)
				{
					//删除第一个节点
					_table[bucketNo] = pCur->_pNext;
					delete pCur;
					pCur = _table[bucketNo];
				}
				else
				{
					//删除中间节点
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
		return 0 == _size;//空返回1
	}

	size_t Size() const
	{
		return _size;
	}

	//查找
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

	//返回一个数据在哈希表桶中的个数
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

	//清空哈希表
	void Clear()
	{
		//遍历每一个桶，然后头删
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

	//交换函数
	void Swap(HashTable<ValueType, KOFV, KTOINT>& ht)
	{
		_table.swap(ht._table);
		swap(_size, ht._size);
	}
	
	//返回桶的个数
	size_t BucketCount()const
	{
		return _table.capacity();
	}

	//返回指定桶中的数据个数
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
			std::cout << "这是第" << i << "号桶: ";
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
			//方式一:
			/*for (size_t i = 0; i < _table.capacity(); i++)
			{
				pHTNode pCur = _table[i];
				while (pCur)
				{
					NewHashTable.InsertEqual(pCur->_data);//多创建了一份节点，浪费空间
					pCur = pCur->_pNext;
				}
			}
			this->Swap(newHashTable);*/
			//缺点: 遍历每个桶，然后在插入，等于是吧哈希表中的节点翻倍了，少量的节点可以，大量的节点效率很低

			for (size_t i = 0; i < _table.capacity(); i++)
			{
				//找到i号桶
				pHTNode pCur = _table[i];
				while (pCur)
				{
					_table[i] = pCur->_pNext;//将pCur插入到新的哈希表中，

					//判断这个节点在新哈希桶的哪一个桶
					size_t bucketNo = NewHashTable.HashFunc(pCur->_data);
					//判断这个节点在桶的哪一个位置
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
						//没找到或者说这个桶里无数据，直接头插
						pCur->_pNext = NewHashTable._table[bucketNo];
						NewHashTable._table[bucketNo] = pCur;
					}
					else
					{
						//找到了，就插在该位置的后面
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
	//测试插入唯一
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
	cout << "4号桶的大小为 : " << ht.BucketSize(4) << endl;
	ht.EraseUnique(4);
	std::cout << "-------------------------------------" << std::endl;
	ht.PrintHashTable();
	cout << "桶的个数 : " << ht.BucketCount() << endl;
	cout << "4号桶的大小为 : " << ht.BucketSize(4) << endl;
#endif
#if 0
	//测试插入重复
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
	cout << "4号桶的大小为 : " << ht.BucketSize(4) << endl;
	ht.EraseEqual(4);
	std::cout << "-------------------------------------" << std::endl;
	ht.PrintHashTable();
	cout << "桶的个数 : " << ht.BucketCount() << endl;
	cout << "4号桶的大小为 : " << ht.BucketSize(4) << endl;
#endif
}