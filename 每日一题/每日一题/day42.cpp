#include "Head.hpp"

//牛客网-----解读密码
void retPassWord()
{
	string str;
	while (getline(cin, str))
	{
		string result;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
				result.push_back(str[i]);
		}
		cout << result << endl;
	}
}

//leetcode---最长回文子串
string longestPalindrome(string s) {
	int m = 0, flag = 0;
	for (int i = 0; i<s.size(); ++i) {
		int j = 0, tmp1 = 0;
		while (i - j >= 0 && i + j + 1<s.size() && s[i - j] == s[i + j + 1]) {
			tmp1 += 2;
			++j;
		}
		int tmp2 = 1;
		j = 0;
		while (i - j - 1 >= 0 && i + j + 1<s.size() && s[i - j - 1] == s[i + j + 1]) {
			tmp2 += 2;
			++j;
		}
		tmp1 = max(tmp1, tmp2);
		if (tmp1>m) {
			m = tmp1;
			flag = i;
		}
	}
	int start = flag - (m - 1) / 2;
	string result;
	for (int i = 0; i<m; ++i) {
		result += s[start + i];
	}
	return result;
}