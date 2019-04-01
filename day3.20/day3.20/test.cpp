// 找到完美数或者完备数
//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		int count = 0;
//		int temp = 0;
//		for (int i = 1; i <= num; i++)
//		{
//			temp = 0;
//			for (int j = 1; j <= i; j++)
//			{
//				if (i % j == 0)
//					temp += j;
//			}
//			if (temp - i == i)
//				count++;
//		}
//		cout << count << endl;
//	}
//	system("pause");
//	return 0;
//}


#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		int pos = str.find('-');
		if (pos == str.npos)
		{
			cout << "输入格式有误" << endl;
			continue;
		}

	}
	return 0;
}
#endif

//打印根数24 ---- 2 + 4               39 ----3 + 9  = 12 --- 1 + 2 = 3 
#include <iostream>
#include <string>

using namespace std;

int get_root(int sum)
{
	if (sum < 10)
		return sum;
	int num = 0;
	while (sum)
	{
		num += sum % 10;
		sum /= 10;
	}
	return get_root(num);
}
int main()
{
	long temp = 0;
	string str;
	while (cin >> str)
	{
		int sum = 0;
		for (auto &s : str)
		{
			sum = sum + (s - '0');
		}
		cout << get_root(sum) << endl;
	}
	return 0;
}