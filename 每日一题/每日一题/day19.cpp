#include "Head.hpp"

//牛客网----汽水瓶
int calculateNum(int num)
{
	int sum = 0;
	int result = 0;
	int index = 0;
	while (num > 1)
	{
		result = num / 3;
		index = num % 3;
		sum += result;
		num = result + index;
		if (num == 2)
		{
			sum++;
			break;
		}
	}
	return sum;
}

//查找两个字符串a，b的最长公共子串
void printStr()
{
		string str1, str2;
		while (cin >> str1 >> str2)
		{
			//以最短的字符串作为s1
			if (str1.size() > str2.size())
				swap(str1, str2);
			int len1 = str1.size(), len2 = str2.size();
			int i, j, start = 0, max = 0;
			vector<vector<int>> MCS(len1 + 1, vector<int>(len2 + 1, 0));
			for (i = 1; i <= len1; i++)
			for (j = 1; j <= len2; j++)
			{
				if (str1[i - 1] == str2[j - 1])
					MCS[i][j] = MCS[i - 1][j - 1] + 1;
				//如果有更长的公共子串，更新长度
				if (MCS[i][j] > max)
				{
					max = MCS[i][j];
					//以i结尾的最大长度为max, 则子串的起始位置为i - max
					start = i - max;
				}
			}
			cout << str1.substr(start, max) << endl;
		}
}