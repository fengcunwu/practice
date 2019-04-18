#include "Head.hpp"

//二进制插入
int binInsert(int n, int m, int j, int i)
{
	m = m << j;
	return n + m;
}
//牛客公共子串计算
size_t returnNum(string s1, string s2)
{
	int m = s1.length();
	int n = s2.length();
	int maxLen = 0;//保存最大长度
	vector<vector<int> >dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		if (s1[i - 1] == s2[j - 1])
		{
			dp[i][j] = dp[i - 1][j - 1] + 1;
			maxLen = max(maxLen, dp[i][j]);
		}
	}
	return maxLen;
}