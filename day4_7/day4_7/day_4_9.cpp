#include "Practice.hpp"
using namespace std;
//斐波那契凤尾
void test3()
{
	int n, i;
	int F[100001];
	F[0] = 1;
	F[1] = 1;
	FOR(i, 100000)
	{
		F[i + 1] = (F[i] + F[i - 1]) % 1000000;
	}
	while (std::cin >> n)
	{
		printf((n < 29 ? "%d\n" : "%06d\n"), F[n]);
	}
}
//字符串查找
//方式一:调用string接口
void Test4()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		int index = 0;
		int count = 0;
		while ((index = str1.find(str2, index)) != str1.npos)
		{
			index += str2.size();
			count++;
		}
		cout << count << endl;
	}
}

string s;
string t;
int nxt[1005];


void cal_next() {
	nxt[0] = -1;
	int n = t.size();
	int i = 1, j = 0;
	while (i < n) {
		if (j == -1 || t[i] == t[j]) {
			j++;
			i++;
			if (t[i] == t[j]) {
				nxt[i] = nxt[j];
			}
			else {
				nxt[i] = j;
			}
		}
		else {
			j = nxt[j];
		}
	}
}


void Test4_KMP()
{
	while (cin >> s >> t) {
		int count = 0;
		cal_next();
		int i, j;
		int n = s.size();
		int m = t.size();
		i = j = 0;
		while (i < n) {
			if (j == -1 || s[i] == t[j]) {
				i++;
				j++;
				if (j == m) {
					j = 0;
					count++;
				}
			}
			else {
				j = nxt[j];
			}
		}
		cout << count << endl;

	}

}