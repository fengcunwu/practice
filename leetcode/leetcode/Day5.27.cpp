#include "PracticeHead.h"
using namespace std;

string longestCommonPrefix_aux(string& first, string& second)
{
	string::iterator it1 = first.begin();
	string::iterator it2 = second.begin();
	while (it1 != first.end() || it2 != second.end())
	{
		if (*it1 != *it2)
			break;
		++it1;
		++it2;
	}
	return string(first.begin(), it1);
}

//leetcode -- 14 最长公共前缀
string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() == 0)
		return "";
	if (strs.size() == 1)
		return strs[0];
	string res = strs[0];
	for (int i = 1; i < strs.size(); ++i)
		res = longestCommonPrefix_aux(res, strs[i]);
	return res;
}




//leetcode --- 7 整数翻转
//自己解法可以实现简单的翻转，但是没有处理溢出问题，
int reverse(int x)
{
	bool flag = true;
	if (x < 0)
	{
		flag = false;
		x = 0 - x;
	}

	string result;
	int temp = 0;
	while (x)
	{
		temp = x % 10;
		result += (temp + '0');
		x = x / 10;
	}
	temp = 0;
	for (int i = 0; i < result.size(); i++)
	{
		temp = (temp * 10) + (result[i] - '0');
	}
	if (false == flag)
		temp = 0 - temp;

	return temp;
}

