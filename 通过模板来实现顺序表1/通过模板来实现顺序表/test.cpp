#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

using namespace std;

template<class T>
class Seqlist
{
public:
	Seqlist(size_t capacity = 10)
		: _size(0)
		, _capacity(capacity)
		, _pdata(new T[capacity])
	{}

	~Seqlist();

	void PushBack(const T& data)//尾查一个元素，尾插的时候不需要改变元素本身，所以用const修饰
	{
		if (_size == _capacity)//检测空间是否够用
			CheckCapacity();//开辟空间

		_pdata[_size++] = data;//赋值
	}

	void PopBack()
	{
		--_size;
	}

	size_t Size()
	{
		return _size;
	}

	T& operator[](size_t pos)//下标访问符重载,支持随机访问
	{
		assert(pos < _size);
			
		return _pdata[pos];
	}

	T& Fount()
	{
		assert(_size);

		return _pdata[0];
	}

	T& Back()
	{
		assert(_size);

		return _pdata[size - 1];
	}

	void Insert(size_t pos, const T& data)
	{
		size_t i = 0;
		assert(pos <= _size);

		for (i = _size; i > pos; i--)
		{
			_pdata[i] = _pdata[i - 1];
		}
		_pdata[pos] = data;
		_size++;
	}

	void Delete(size_t pos)
	{
		size_t i = 0;
		assert(pos <= _size);

		for (i = pos; i < _size - 1; i++)
			_pdata[i] = _pdata[i + 1];
		
		_size--;
	}

	void CheckCapacity()
	{
		int newcapacity = _capacity << 1;

		T* temp = new T[newcapacity];

		memcpy(temp, _pdata, _capacity * sizeof(T));

		delete[] _pdata;
		_pdata = temp;
		_capacity = newcapacity;
	}

	void PrintSeqlist()
	{
		for (size_t i = 0; i < _size; i++)
			cout << _pdata[i] << ' ';

		cout << endl;
	}

private:
	T* _pdata;
	size_t _size;
	size_t _capacity;
};

template<class T>
Seqlist<T>::~Seqlist()
{
	delete[] _pdata;
	_pdata = nullptr;

	_size = 0;
	_capacity = 0;
}

void test()
{
	Seqlist<int> s;
	for (int i = 0; i < 12; i++)
		s.PushBack(i);
	s.PopBack();
	s.PrintSeqlist();
	s.Insert(s.Size(), 88);
	s.Delete(s.Size());
	s.PrintSeqlist();
	cout << endl;
	
}

int main()
{
	test();
	system("pause");
	return 0;
}