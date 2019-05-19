#if 0
#include <iostream>
#include <stdlib.h>
#include <list>
#include <vector>

using namespace std;

template<class T>
void PrintList(const list<T>& List)
{
	for (auto& e : List)
	{
		cout << e << " ";
	}
	cout << endl;
}

class A
{
public:
	A(int _a, int _b)
		: a(_a)
		, b(_b)
	{
		cout << "A:���캯��" << endl;
	}

	A(const A& sp)
		: a(sp.a)
		, b(sp.b)
	{
		cout << "A:�������캯��" << endl;
	}

private:
	int a;
	int b;
};

int main()
{
	/*list<int> ls;
	list<int> ls1(10, 1);
	vector<int> arr = { 1, 2, 3, 4, 5, 6 };
	list<int> ls2(arr.begin(), arr.end());
	ls1.push_back(2);
	ls1.push_front(3);
	PrintList(ls1);
	ls2.assign(10, 3);
	PrintList(ls2);*/

	list<int> lis = { 1, 3,};
	PrintList(lis);
	list<int>::iterator it = lis.begin();
	cout << *it << endl;
	lis.insert(it, 13);
	PrintList(lis);
	it = lis.erase(it);//erase����ֵ�Ǻ�һ������
	PrintList(lis);
	//cout << *it << endl;//ɾ��ĳ��λ�õ����ݵ��µ�����ʧЧ
	cout << *it << endl;
	//list<A> ls;
	//ls.push_back(A(1,2));//�������ʱ�������캯����������ʱ����
	//ls.emplace_back(1, 3);//ֻ����ù��캯�����Ѷ�����������Ȼ�����
	system("pause");
	return 0;
}

# endif

#include"List.hpp"

using namespace std;

template<class T>
void PrintList(const List<T>& lt)
{
	auto it = lt.CBegin();
	//*it = 10;//const���ܸı�������
	while (it != lt.CEnd())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	List<int> lt;
	for (int i = 0; i < 5; i++)
		lt.PushFront(i);
	lt.PopFront();
	PrintList(lt);
	List<int>::iterator it = lt.Begin();
	++it;
	//lt.Insert(it, 1);
	PrintList(lt);
	List<int> lts(lt);
	List<int> lts2 = lts;
	PrintList(lts);
	PrintList(lts2);
	system("pause");
	return 0;
}