#include "Head.hpp"

//牛客网---统计每个月兔子的总数
int RetTheNumber(int month)
{
	int first = 1;//出生一个月的兔子
	int second = 1;//出生两个月的兔子，下一个月可以产兔子
	int result = 0;
	for (int i = 3; i <= month; i++)
	{
		result = first + second;//结果就是两个月的兔子加一个月的兔子
		first = second;//经过一个月之后，出生两个月的兔子会生产这么多兔子
		second = result;//经过一个月后，可以生产兔子的兔子数
	}
	return result;
}

//牛客网----字符串通配符
//方式一: 递归
bool match(const char* pattern, const char *str)
{
	if (*pattern == '\0' && *str == '\0')
		return true;
	if (*pattern == '\0' || *str == '\0')
		return false;

	if (*pattern == '?')
	{
		return match(pattern + 1, str + 1);
	}
	else if (*pattern == '*')
	{
		// 匹配0个1个或多个
		return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1);
	}
	else if (*pattern == *str)
	{
		return match(pattern + 1, str + 1);
	}
	return false;
}

//方式二: 动态规划
bool match_dp(string str, string str1)
{
	int l1 = str.size();
	int l2 = str1.size();
	vector<vector<bool> > dp(l1 + 1, vector<bool>(l2 + 1, false));
	dp[0][0] = true;
	for (int i = 1; i<l1 + 1; i++)
	{
		if (str[i - 1] == '*') 
			dp[i][0] = dp[i - 1][0];
	}
	for (int i = 1; i<l1 + 1; i++)
	{
		for (int j = 1; j<l2 + 1; j++)
		{
			if (str[i - 1] == '*')//能匹配多个
			{
				dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i - 1][j - 1];
			}
			else if (str[i - 1] == '?' || str[i - 1] == str1[j - 1])//？和两个相同的字符差不多
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}
}