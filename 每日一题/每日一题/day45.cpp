#include "Head.hpp"

//Å£¿ÍÍø----Æ¹ÅÒÇò¿ğ
void retHasPingPang()
{
	vector<size_t> arr1(26);
	vector<size_t> arr2(26);
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int maxlength = str1.size() > str2.size() ? str1.size() : str2.size();
		for (int i = 0; i < maxlength; i++)
		{
			if (i < str1.size())
				arr1[str1[i] - 'A']++;
			if (i < str2.size())
				arr2[str2[i] - 'A']++;
		}
		int flag = 1;
		for (int j = 0; j < 26; j++)
		{
			if (arr1[j] < arr2[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}