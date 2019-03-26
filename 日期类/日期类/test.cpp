#include <iostream>

using namespace std;

#if 0
class Test
{ 
public:
	Test()
	{
		cout << "Test(): " << this << endl;
	}

	Test(const Test& t)
	{
		cout << "Test(const Test& t): " << this << endl;
	}

	Test& operator=(const Test& t)
	{
		cout << this << "=" << &t << endl;
		return *this;
	}

	~Test()
	{
		cout << "~Test()" << this << endl;
	}
};

Test Testfun(Test t)
{
	Test t1;
	Test temp(t);
	t1 = temp;
	return t1;
}

void Testfun()
{
	Test t1, t2;
	t1 = Testfun(t2);
}

class Time
{
public:
	Time(int hour = 12, int mintue = 00, int second = 00)
		: _hour(hour)
		, _mintue(mintue)
		, _second(second)
	{

	}

private:
	int _hour;
	int _mintue;
	int _second;
};

class Date
{
public:
	Date(int year = 1998, int mouth = 1, int day = 1)
		: _year(year)
		, _mouth(mouth)
		, _day(day)
		/*, _ra(day)
		, _cb(10)*/
		, _t()
	{
		/*this->_year = year;
		this->_mouth = mouth;
		this->_day = day;*/
	}

	//explicit Date(int year)//��ֹ���ι��캯������ת��������
	//	: _year(year)
	//{                     

	//}

	Date(const Date& d1)
		: _year(d1._year)
		, _mouth(d1._mouth)
		, _day(d1._day)
		, _t(d1._t)
	{

	}
	
	/*ostream& operator<<(ostream& _cout)
	{
		_cout << this->_year << "-" << this->_mouth << "-" << this->_day;
		return _cout;
	}*/
private:
	int _year;
	int _mouth;
	int _day;
	/*int& _ra;
	const int _cb;*/
	Time _t;

	friend ostream& operator<<(ostream& _cout, const Date& d);
};

void test()
{
	Date d1;
	Date d2(d1);
	//d1 << cout;
	cout << d1 << endl;
}

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._mouth << "-" << d._day;
	return _cout;
}

int main()
{
	//Testfun();
	test();
	system("pause");
	return 0;
}


#endif

class Date
{
public:
	//����ȱʡ�����Ĺ��캯��
	Date(int year = 1998, int month = 9, int day = 18)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		if (!((year > 0) 
			&& ((month > 0) && (month <= 12))
			&& ((day > 0) && day <= GetDaysOfMonth(year, month))))
		{
			_year = 1998;
			_month = 9;
			_day = 18;
		}
	}

	//�������캯��
	Date(const Date& d1)
		: _year(d1._year)
		, _month(d1._month)
		, _day(d1._day)
	{}

	//�ж��ǲ�������
	bool IsLeapYear(int year)
	{
		if (0 == year % 4 && 0 != year % 100 || 0 == year % 400)
			return true;
		else
			return false;
	}

	//����һ����������һ����Ӧ���ж�����
	int GetDaysOfMonth(int year, int month)
	{
		int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if (month != 2)
			return days[month];
		else
		{
			if (IsLeapYear(year))
			{
				return days[month] + 1;
			}
			else
				return days[month];
		}
	}

	//��Ԫ�����������ӡ
	friend ostream& operator<<(ostream& _cout, const Date& d);

	//�Ƚ����������Ƿ���ͬһ��
	bool operator==(const Date& d)const
	{
		return (_year == d._year && _month == d._month && _day == d._day);
	}

	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}

	//�Ƚ��������ڵĴ�С��ϵ
	
	//С��
	bool operator<(const Date& d)const
	{
		if (d._year > _year)
			return true;
		else if (d._year == _year)
		{
			if (d._month > _month)
				return true;
			else if (d._month == _month)
			{
				if (d._day > _day)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}

	//С�ڵ���
	bool operator<=(const Date& d)const
	{
		return (*this < d || *this == d);
	}

	//����
	bool operator>(const Date& d)const
	{
		if (_year > d._year)
			return true;
		else if (_year == d._year)
		{
			if (_month > d._month)
				return true;
			else if (_month == d._month)
			{
				if (_day > d._day)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}

	//���ڵ���
	bool operator>=(const Date& d)const
	{
		return (*this > d || *this == d);
	}

	//��ֵ���������
	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		return *this;
	}

	//ǰ��++����һ�����ڼ�һ�죬Ȼ�󷵻��������
	Date& operator++()
	{
		_day += 1;
		if (_day > GetDaysOfMonth(_year, _month))
		{
			_month += 1;
			_day = 1;
			if (_month > 12)
			{
				_year += 1;
				_month = 1;
			}
		}
		return *this;
	}

	//����++
	Date operator++(int)
	{
		Date temp(*this);
		++(*this);

		return temp;
	}

	//ǰ��--
	Date& operator--()
	{
		_day -= 1;
		if (_day <= 0)
		{
			_month -= 1;
			if (_month <= 0)
			{
				_year -= 1;
				_month = 12;
				_day = GetDaysOfMonth(_year, _month);
			}
			else
				_day = GetDaysOfMonth(_year, _month);
		}
		return *this;
	}
	//����--
	Date operator--(int)
	{
		Date temp(*this);
		--(*this);

		return temp;
	}

	//�����������������һ����������
	int operator-(const Date& d)
	{
		Date mindate(*this);
		Date maxdate(d);
		int count = 0;

		if (maxdate < mindate)
		{
			maxdate = *this;
			mindate = d;
		}

		while (mindate != maxdate)
		{
			++count;
			++mindate;
		}
		return count;
	}

	//�����ڼ�һ������ֵ������һ�����ڶ���
	Date operator+(int days)
	{
		Date temp(*this);
		temp._day += days;

		int dayMonth = GetDaysOfMonth(temp._year, temp._month);
		while (temp._day > dayMonth)
		{
			temp._day -= dayMonth;
			temp._month += 1;
			if (temp._month > 12)
			{
				temp._year += 1;
				temp._month = 1;
			}
			dayMonth = GetDaysOfMonth(temp._year, temp._month);
		}

		return temp;
	}

	//��һ�����ڼ�һ�����ε���������һ������
	Date operator-(int days)
	{
		if (days < 0)
			return *this + (0 - days);

		Date temp(*this);

		temp._day -= days;
		//int dayMonth = GetDaysOfMonth(temp._year, temp._month);
		while (temp._day < 0)
		{
			temp._month -= 1;
			if (0 == temp._month)
			{
				temp._year -= 1;
				temp._month = 12;
			}
			temp._day += GetDaysOfMonth(temp._year, temp._month);
		}
		return temp;
	}


private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

void test()
{
	Date d1;
	Date d2(2018, 11, 4);
	Date d3(1600, 2, 21);
	Date d4(2019, 1, 1);
	//cout << d2 - d4 << endl;
	/*if (d3 >= d1)
		cout << "��ȷ" << endl;
	else
		cout << "����" << endl;*/

	cout << d4 << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}