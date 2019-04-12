#include "PracticeEveryDay.hpp"

using namespace std;

//牛客网---收件人列表
void Test_Day4_11_1()
{
	int num = 0;
	while (cin >> num)
	{
		vector<string> arr;
		string temp;
		getline(cin, temp);
		for (int i = 0; i < num; i++)
		{
			temp.clear();
			getline(cin, temp);
			arr.push_back(temp);
		}
		string retstr;
		for (int j = 0; j < num; j++)
		{
			if (arr[j].find(' ') != string::npos || arr[j].find(',') != string::npos)
			{
				retstr += ('"' + arr[j] + '"');
				retstr.push_back(',');
				retstr.push_back(' ');
			}
			else
			{
				retstr += arr[j];
				retstr.push_back(',');
				retstr.push_back(' ');
			}
		}
		retstr.erase(retstr.rfind(','));
		cout << retstr << endl;
	} 
}


//牛客网养兔子
vector<long long> arr(90, 0);

void Test_Day4_11_2()
{
	arr[0] = 1;
	arr[1] = 2;
	int temp = 0;
	for (int i = 2; i < 90; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	int num = 0;
	while (cin >> num)
	{
		if (num >= 1 && num <= 90)
			cout << arr[num - 1] << endl;
	}
}