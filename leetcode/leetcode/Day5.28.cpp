#include "PracticeHead.h"

//leetcode 7 整数翻转
//解法二，处理了溢出问题
int reverse_op(int x)
{
	int res = 0;
	int MAX_INT = ((1 << 31) - 1) / 10;
	while (x != 0){
		int s = x % 10;
		x /= 10;
		if (abs(res)>MAX_INT)
			return 0;
		else
			res = res * 10 + s;
	}
	return res;
}

vector<string> Solve(string& digits, vector<string>& strs, vector<string>& result, int i)
{
	if (i >= digits.size())
		return result;

	vector<string> tmp;
	for (int j = 0; j < strs[digits[i] - '0'].size(); j++){
		if (result.empty()){
			string word(1, strs[digits[i] - '0'][j]);
			tmp.push_back(word);
		}
		else{
			for (int k = 0; k < result.size(); k++){
				string word(1, strs[digits[i] - '0'][j]);
				tmp.push_back(result[k] + word);
			}
		}
	}
	return Solve(digits, strs, tmp, i + 1);
}
//leetcode---17电话号码的字母组合
vector<string> letterCombinations(string digits) 
{
	int len = digits.size();
	vector<string> result;
	if (len == 0)
		return result;
	vector<string> strs = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	return Solve(digits, strs, result, 0);
}

bool IsTrue(char a, char b)
{
	return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
}
//leetcode---20有效的括号
bool isValid(string s) {
	int len = s.size();
	if (len % 2 == 1)
		return false;
	set<char> left = { '(', '{', '[' };
	set<char> right = { '}', ']', ')' };
	stack<char> st;
	for (int i = 0; i < len; i++)
	{
		if (left.count(s[i]))
			st.push(s[i]);

		if (right.count(s[i]))
		{
			if (st.empty())
				return false;
			else
			{
				if (IsTrue(st.top(), s[i]))
				{
					st.pop();
					continue;
				}
					
				else
					return false;
			}
		}
	}
	if (st.empty())
		return true;
	return false;
}

