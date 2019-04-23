#include"Head.hpp"

//Å£¿ÍÍø----ÂæÍÕÃüÃû·¨
void retStr()
{
	string str;
	while (cin >> str)
	{
		string result;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '_')
				result.push_back(str[++i] - 32);
			else
				result.push_back(str[i]);
		}
		cout << result << endl;
	}
}

//Å£¿ÍÍø---µ¥´Êµ¹ÅÅ
void str_To_rts()
{
	string str;
	string nums = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (getline(cin, str))
	{
		string result;
		string temp = "";
		for (int i = str.size() - 1; i >= 0; i--)
		{
			if (nums.find(str[i]) != string::npos)
				temp.push_back(str[i]);
			else
			{
				reverse(temp.begin(), temp.end());
				result += (temp + ' ');
				temp.clear();
			}
		}
		reverse(temp.begin(), temp.end());
		result += temp;
		cout << result << endl;
	}
}