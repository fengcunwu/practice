#include <iostream>
#include <stdlib.h>
using namespace std;

#if 0
typedef struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val_ = 0, ListNode* next_ = NULL)
		: val(val_)
		, next(next_)
	{}
}ListNode;

class Solution
{
public:
	ListNode* addSum(ListNode* L1, ListNode* L2)
	{
		if (L1 == NULL)
			return L2;
		if (L2 == NULL)
			return L1;
		ListNode* NewNode = new ListNode(0);
		ListNode* p1 = L1;
		ListNode* p2 = L2;
		ListNode* pc = NewNode->next;
		int x = 0, y = 0;
		int jw = 0, temp = 0;
		while (p1 != NULL || p2 != NULL)
		{
			x = p1 != NULL ? p1->val : 0;
			y = p2 != NULL ? p2->val : 0;

			temp = x + y + jw;
			jw = temp / 10;
			pc = new ListNode(temp % 10);
			pc = pc->next;
			p1 = p1->next;
			p2 = p2->next;
		}
		if (jw)
		{
			pc = new ListNode(1);
		}

		return NewNode->next;
	}
};

int main()
{

	system("pause");
	return 0;
}

#endif 

#if 0
//最小公倍数
int main()
{
	int i = 0;
	int j = 0;
	int temp = 0;
	while (cin >> i && cin >> j)
	{
		if (i != 0 && 0 != j)
		{
			while (i % j)
			{
				temp = i % j;
				i = j;
				j = temp;
			}
			cout << j << endl;
		}
		else
			cout << "输入参数有误" << endl;
		
	}
	
	
	system("pause");
	return  0;
}
#endif

#if 0
#include <vector>
//小易的升级之路
int MinNumber(int &a, int &b)
{
	int tmp = 0;
	while (a % b)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return b;
}

int main()
{
	int num = 0;//多少个怪物
	int power = 0;//初始能力
	while (cin >> num && cin >> power)
	{
		vector<int> arr;
		int temp = 0;
		for (int i = 0; i < num; i++)
		{
			cin >> temp;
			arr.push_back(temp);
		}
		/*for (auto &e : arr)
			cout << e << " ";
		cout << endl;*/
		int c = power;
		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[j] <= c)
				c += arr[j];
			else
			{
				int tm = c;
				c += MinNumber(arr[j], tm);
			}
		}
		cout << c << " ";
	}
	system("pause");
	return 0;
}

#endif

//找出字符串中第一个出现一次的字符
#include <string>
//解法一
# if 0
int main()
{
	string str;
	while (cin >> str)
	{
		bool flag = false;
		int arr[255] = { 0 };
		for (int i = 0; i < str.size(); i++)
		{
			arr[str[i]]++;
		}

		for (int j = 0; j < 255; j++)
		{
			if (arr[str[j]] == 1)
			{
				cout << str[j] << endl;
				flag = true;
				break;
			}
		}
		if (flag == false)
			cout << -1 << endl;
	}

	system("psuse");
	return 0;
}

#endif

int main()
{
	string str;
	while (cin >> str)
	{
		int flag = false;
		for (int i = 0; i < str.size(); i++)
		{
			if (str.find(str[i]) == str.rfind(str[i]))
			{
				flag = true;
				cout << str[i] << endl;
				break;
			}
		}
		if (flag == false)
			cout << -1 << endl;
	}
	system("pause");
	return 0;
}