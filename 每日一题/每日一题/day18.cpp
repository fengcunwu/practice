#include "Head.hpp"

//ţ����---ͳ��ÿ�������ӵ�����
int RetTheNumber(int month)
{
	int first = 1;//����һ���µ�����
	int second = 1;//���������µ����ӣ���һ���¿��Բ�����
	int result = 0;
	for (int i = 3; i <= month; i++)
	{
		result = first + second;//������������µ����Ӽ�һ���µ�����
		first = second;//����һ����֮�󣬳��������µ����ӻ�������ô������
		second = result;//����һ���º󣬿����������ӵ�������
	}
	return result;
}

//ţ����----�ַ���ͨ���
//��ʽһ: �ݹ�
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
		// ƥ��0��1������
		return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1);
	}
	else if (*pattern == *str)
	{
		return match(pattern + 1, str + 1);
	}
	return false;
}

//��ʽ��: ��̬�滮
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
			if (str[i - 1] == '*')//��ƥ����
			{
				dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i - 1][j - 1];
			}
			else if (str[i - 1] == '?' || str[i - 1] == str1[j - 1])//����������ͬ���ַ����
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}
}