#include <iostream>

using namespace std;

class Base
{
public:
	void SetBaseData(int pub = 1, int pro = 2, int pri = 3)
	{
		_pro = pro;
		_pub = pub;
		_pri = pri;
	}
	void PrintData()
	{
		cout << _pub << endl;
		cout << _pro << endl;
		cout << _pri << endl;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

class Son : protected Base
{
public:
	void SetSonData(int pub = 4, int pro = 5, int pri = 6)
	{
		_pubs = pub;
		_pros = pro;
		_pris = pri;
		_pub = pub;
		_pro = pro;
		//_pri = pri;
	}
	void PrintSonData()
	{
		PrintData();
		cout << _pubs << endl;
		cout << _pros << endl;
		cout << _pris << endl;
	}
public:
	int _pubs;
protected:
	int _pros;
private:
	int _pris;
};

int main()
{
	cout << sizeof(Base) << endl;
	cout << sizeof(Son) << endl; 
	
	system("pause");
	return 0;
}
//#include <iostream>
//using namespace std;
//void test(int sb = 10)
//{
//	cout << sb << endl;
//}
//int main()
//{
//	test(31);
//	system("pause");
//	return 0;
//}