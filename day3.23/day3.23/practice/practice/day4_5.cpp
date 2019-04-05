#include "head.h"

using namespace std;

//求正数数组最小不可组成的和
int getFirstUnFormedNum(vector<int> arr, int len)
{
	if (len == 0)
		return 1;
	set<int> nums;
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		nums.insert(arr[i]);
		sum = arr[i];
		for (int j = i + 1; j < len; j++)
		{
			sum += arr[j];
			nums.insert(sum);
			nums.insert(arr[i] + arr[j]);
		}
			
	}
	/*for (auto &e : nums)
		cout << e << " ";
	cout << endl;*/
	/*set<int>::iterator it = nums.begin();
	for (; it != nums.end(); it++)
		cout << *it << " ";
	cout << endl;*/

	set<int>::iterator itbegin = nums.begin();
	set<int>::iterator itend = nums.end();
	int num = *(--itend);
	for (int k = *itbegin; k <= num; k++)
	{
		if (!nums.count(k))
			return k;
	}
	return num + 1;
}


//寻找假币，返回最快的称重次数
int FindMoney(int num)
{
	if (num == 0)
		return 0;
	else if (num == 1 || num == 2)
		return 1;
	else
	{
		if (num / 3 == 0)
			return FindMoney(num / 3) + 1;
		else
			return FindMoney(num / 3 + 1) + 1;
	}
}

///简单的密码解析
void ReturnRight(string & str)
{
	for (unsigned i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
			continue;
		else if (str[i] >= 'A' && str[i] <= 'E')
			str[i] = str[i] + 21;
		else
			str[i] -= 5;
	}
	cout << str << endl;
}