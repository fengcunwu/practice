#if 0
#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		if (n <= 2)
			cout << -1 << endl;
		else
		{
			if (n % 2 == 1)
				cout << 2 << endl;
			else if (n % 4 == 2)
				cout << 4 << endl;
			else if (n % 4 == 0)
				cout << 3 << endl;
		}
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
	string st1;
	string st2;
	while ((getline(cin, st1) && getline(cin, st2)))
	{
		vector<long long> arr1(0);
		vector<long long> arr2(0);
		int i = 0;
		int maxLength = st1.size() > st2.size() ? st1.size() : st2.size();
		for (i = 0; i < maxLength; i++)
		{
			if (i < maxLength - st1.size())
				arr1.push_back(0);
			else
				arr1.push_back(st1[i] - '0');
		}
		for (i = 0; i < maxLength; i++)
		{
			if (i < maxLength - st2.size())
				arr2.push_back(0);
			else
				arr2.push_back(st2[i - (maxLength - st2.size())] - '0');
		}
		string str;
		int jw = 0;//进位
		int jm = 0;//当前位
		int temp = 0;
		for (i = maxLength - 1; i >= 0; i--)
		{
			temp = arr1[i] + arr2[i] + jw;
			jm = temp % 10;
			jw = temp / 10;
			str.push_back(jm + '0');
		}
		if (jw != 0)
			str.push_back(jw + '0');
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
	/*char ch = '1';
	int i = ch - '0';
	cout << i << endl;*/
	system("pause");
	return 0;
}

# endif

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		int temp = 0, carry = 0;
		while (a.size()<b.size())
			a = "0" + a;
		while (a.size()>b.size())
			b = "0" + b;
		for (int i = a.size() - 1; i >= 0; i--)
		{

			temp = a[i] - '0' + b[i] - '0' + carry;
			a[i] = temp % 10 + '0';
			if (temp / 10)
				carry = 1;
			else
				carry = 0;
		}
		if (carry)
			a = "1" + a;
		cout << a << endl;
	}
	return 0;
}
