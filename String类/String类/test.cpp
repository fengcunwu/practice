#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <string>

using namespace std;

class String
{
public:

	//��������ǹ��캯��
	String()
		: _str("")
		, _size(0)
		, _capacity(0)
	{
		//(*pCount)++;
	}

	String(const char* s = "")
	{
		//assert(s);

		if (NULL == s)
			s = "";
	
		_size = strlen(s);
		_capacity = _size + 1;
		_str = new char[_capacity];
		strcpy(_str, s);
		//delete[] temp;
		//(*pCount)++;
	}

	String(size_t n, char c)
		: _size(n)
		, _capacity(n + 1)
	{
		_str = new char[n];
		memset(_str, c, n*sizeof(char));
		_str[n] = 0;
	}

	String(const String& s)
		: _size(s.size())
		, _capacity(s.size() + 1)
		, _str(new char[s.size() + 1])
	{
		strcpy(_str, s._str);
	}

	String(const String& s, size_t n)
	{
		char* ptr = s._str;
		char* partstr = new char[n + 1];

		for (size_t i = 0; i < n; ++i)
		{
			partstr[i] = ptr[i];
		}

		partstr[n] = 0;

		_str = partstr;
		_size = n;
		_capacity = n + 1;
	}

	//��������
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = NULL;
		}
	}

	size_t size()const
	{
		return _size;
	}

	size_t capacity()const
	{
		return _capacity;
	}

	bool Empty()const//����trueΪ�գ�����false����
	{
		return _size == 0;
	}

	void Clear()
	{
		_size = 0;
	}
	//��ֵ����������أ����ֻ����ǳ������������ڴ�й©�����ͷſռ��ʱ�򣬻ᵼ��
	//һ���ڴ�ռ䱻�ͷŶ�Σ�ʹ�������
	String& operator=(const String& s)
	{
		if (&s != this)
		{
			char* newstr = new char[s._size + 1];
			delete[] _str;
			strcpy(newstr, s._str);

			_str = newstr;
			_size = s._size;
			_capacity = s._capacity;
		}
		
		return *this;
	}

	void resize(size_t n, char c = '0')
	{
		if (n >= _size)
		{
			char* newstr = new char[n + 1];

			strcpy(newstr, _str);
			for (size_t i = _size; i < n; ++i)
			{
				newstr[i] = c;
			}
			newstr[n] = 0;
			_str = newstr;
			_capacity = n + 1;
			_size = n;
		}
		else
		{
			_str[n] = 0;
			_size = n;
			_capacity = n + 1;
		}
	}

	//�±����������
	char& operator[](size_t pos)
	{
		assert(pos < _size);
		//assert(pos >= _size);
		//char* newstr = new char[_capacity];

		//strcpy(newstr, _str);

		//return newstr[pos];

		return _str[pos];
	}


	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		//assert(pos >= _size);
		//char* newstr = new char[_capacity];

		//strcpy(newstr, _str);

		return _str[pos];
	}

	//���ַ�������β��һ���ַ�c
	void PushBack(char c)
	{
		if ((_size + 1) >= _capacity)
			ExtendCapacity();

		_str[_size] = c;
		_str[_size + 1] = 0;
		_size++;
	}

	void ExtendCapacity(const char* ptr = "")
	{
		size_t newcapacity = 2 * _capacity + strlen(ptr);
		char* newstr = new char[newcapacity];
		strcpy(newstr, _str);
		delete[] _str;
		_str = newstr;
		_capacity = newcapacity;
	}

	//���ַ�����׷��һ���ַ���
	String& append(const char* ptr)
	{
		assert(ptr);
		
		size_t temp = _size + strlen(ptr) + 1;

		if (temp > _capacity)
			ExtendCapacity(ptr);

		for (size_t i = 0; i < strlen(ptr); ++i)
			PushBack(ptr[i]);

		_str[temp] = 0;

		_size = temp - 1;

		return *this;
	}

	//�ַ�������׷���ַ���
	String& operator+=(const String& ptr)
	{
		size_t temp = _size + ptr._size + 1;

		if (temp > _capacity)
			ExtendCapacity(ptr._str);

		return append(ptr._str);
	}

	//����C���Ը�ʽ���ַ���
	const char* c_str()const
	{
		return _str;
	}

private:
	//����������������
	friend ostream& operator<<(ostream& _cout, const String& s)
	{
		/*char* newstr = s._str;
		for (size_t i = 0; i < s._size; ++i)
			cout << newstr[i] << ' ';*/
		cout << s._str;
		return _cout;
	}

private:
	char* _str;//�ַ���
	//int* pCount;//��¼�������ٶ�����ʵ��дʱ����
	size_t _size;//��¼�ַ�������Ч�ַ�����
	size_t _capacity;//��¼�ַ�����������С
};

void test()
{
	String s1("hello LeBron James");
	//s1.resize(30);
	String s2("play basketball  ");
	s2 += s1;
	cout << s1.size() << endl;
	s1.resize(10);
	cout << s1 << endl;
	cout << s1.size() << endl;
	s1.PushBack('#');
	cout << s1 << endl;
	//String s2 = s1;
	//cout << s1.size() << endl;
	//cout << s1.capacity() << endl;
	cout << s1.append("welcome home") << endl;
	cout << s1.size() << endl;

	cout << s2.c_str << endl;
}

int main()
{
	test();
	//cout << " ffafasd" << endl;
	/*string s1("fadfsaf");
	cout << s1.size() << endl;
	s1.resize(5);
	cout << s1 << endl;*/
	system("pause");
	return 0;
}