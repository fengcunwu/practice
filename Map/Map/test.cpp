#include <iostream>
#include <map>
#include <stdlib.h>
#include <string>
#include <set>

using namespace std;

#if 0
int main()
{
	map<string, string> m1;//构建空的
	map<string, string> m2{ {"apple", "苹果"}, {"orange", "橙子"}, {"banana", "香蕉"} };
	m2.insert(pair<string, string>("peach", "桃子"));
	m2.insert(make_pair("pear", "梨"));
	cout << m2["apple"] << endl;
	cout << m2.size() << endl;

	m2["red_apple"] = "红苹果";
	cout << m2.size() << endl;

	auto it = m2.begin();

	while (it != m2.end())
	{
		cout << it->first << "---->" << it->second << endl;
		it++;
	}

	for (auto & m : m2)
	{
		cout << m.first << "---->" <<  m.second << endl;
	}
	system("pause");
	return 0;
}

#endif

int main()
{
	int array[] = { 0, 0, 1, 1, 2, 3, 2, 3, 4, 4, 3, 5, 6, 7, 8, 9, 9, 8, 7, 6, 5, 0 };
	set<int> s1;
	for (auto & a : array)
		s1.insert(a);
	cout << s1.size() << endl;
	for (auto &s : s1)
	{
		cout << s << " ";
	}
	cout << endl;
	
	cout << s1.count(1) << endl;
	cout << s1.count(20) << endl;

	multiset<int> s2;
	for (auto &a : array)
	{
		s2.insert(a);
	}
	for (auto &s : s2)
	{
		cout << s << " ";
	}
	cout << endl;

	cout << s2.count(2) << endl;
	cout << s2.count(0) << endl;
	cout << s2.count(10) << endl;
	system("pause");
	return 0;
}