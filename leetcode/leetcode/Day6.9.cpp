#include "PracticeHead.h"

// leetcode -- 66 加一
vector<int> plusOne(vector<int>& digits) 
{
	int len = digits.size();
	vector<int> result(len + 1, 0);
	if (len == 0)
		return result;

	int temp = 0;
	for (int i = len - 1; i >= 0; --i)
	{
		if (i == len - 1)
		{
			temp = (digits[i] + 1) / 10;
			result[i + 1] = (digits[i] + 1) % 10;
		}
		else
		{
			result[i + 1] = (digits[i] + temp) % 10;
			temp = (temp + digits[i]) / 10;
		}
	}
	if (temp)
		result[0] = temp;
	else
		result.erase(result.begin());

	return result;
}

//leetcode  67 -- 二进制求和
string addBinary(string a, string b) 
{
	if (a.size() == 0)
		return b;
	if (b.size() == 0)
		return a;
	string result;
	int sum = 0;//和
	int i = 0;
	int temp = 0;//进位

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int maxsize = a.size() > b.size() ? a.size() : b.size();
	if (a.size() < maxsize)
	{
		for (i = a.size(); i < maxsize; i++)
			a.push_back('0');
	}
	else
	{
		for (i = b.size(); i < maxsize; i++)
			b.push_back('0');
	}


	for (i = 0; i < maxsize; i++)//长短不一，先处理短的
	{
		sum = (a[i] - '0') + (b[i] - '0') + temp;
		temp = sum / 2;
		result.push_back((sum % 2) + '0');
	}
	if (temp)
		result.push_back(temp + '0');
	reverse(result.begin(), result.end());
	return result;
}