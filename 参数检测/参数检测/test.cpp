#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		vector<string> arr;
		int flag = 0;
		string temp;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '"' && flag == 0)
			{
				flag = 1;
				continue;
			}
			if (flag == 0)
			{
				if (str[i] != ' ')
					temp.push_back(str[i]);
				if (str[i] == ' ')
				{
					arr.push_back(temp);
					temp.clear();
				}
			}
			else
			{
				temp.push_back(str[i]);
			}
			if (str[i] == '"' && flag == 1)
			{
				flag = 0;
				continue;
			}
		}
		arr.push_back(temp);
		cout << arr.size() << endl;
		for (auto & e : arr)
		{
			cout << e << endl;
		}

	}
}
