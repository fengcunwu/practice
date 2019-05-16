#include"Head.hpp"

//��ת�ַ���
void ReverseStr()
{
	string str;
	while (getline(cin, str))
	{
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
}

//��ת�ַ���-----����ָ�뽻������
void ReverseStrSwap()
{
	string str;
	while (getline(cin, str))
	{
		int left = 0;
		int right = str.size() - 1;
		char ch;
		while (left < right)
		{
			ch = str[left];
			str[left] = str[right];
			str[right] = ch;

			left++;
			right--;
		}
		cout << str << endl;
	}
}

//�������һ��ż�����������������
void FindPrime()
{
	int num = 0;
	while (cin >> num)
	{
		int i = 0;
		int temp = num / 2;
		for (i = temp; i < num; i++)
		{
			if (IsPrime(i) && IsPrime(num - i))
				break;
		}
		cout << num - i << endl << i << endl;
	}
}
//�ж��Ƿ�������
bool IsPrime(int num)
{
	int temp = sqrt(num);
	for (int i = 2; i <= temp; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}