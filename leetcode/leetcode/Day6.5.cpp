#include "PracticeHead.h"

// 10 ----- 13211311123113112211
//leetcode 38 -- 报数
string countAndSay(int n) 
{
	int i = 1, j = 0;
	string result = "1";
	string temp = "";
	while (i < n)
	{
		int count = 1;
		char ch = result[0];
		temp.clear();
		for (j = 1; j < result.size(); j++)
		{
			if (ch == result[j])
				++count;
			else
			{
				temp += (count + '0');
				temp += ch;
				count = 1;
				ch = result[j];
			}
		}
		temp += (count + '0');
		temp += ch;
		++i;
		result = temp;
	}
	return result;
}

//leetcode 53 --- 最大子序和
int maxSubArray_dp(vector<int>& nums) 
{
	if (nums.size() == 0)
		return NULL;
	int res = INT_MIN;
	int sum = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum = max(nums[i], sum + nums[i]);
		res = max(sum, res);
	}
	return res;
}


//leetcode 53 --- 最大子序和
int maxSubArray(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	int max = nums[0];
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum = 0;
		for (int j = i; j < nums.size(); j++)
		{
			sum += nums[j];
			if (sum > max)
				max = sum;
		}
	}
	return max;
}