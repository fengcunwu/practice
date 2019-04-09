#include "Practice.hpp"

using namespace std;

//�ж��Ƿ�������
bool IsLeapYear(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	return false;
}

//����ĳһ���һ��һ�������ڼ�
int ReturnWeedDay(int year)
{
	int WeedDay_2000_1_1 = 6;//2000���һ��һ����������
	int daySum = 0;
	int yearSum = year - 2000;
	if (yearSum)
	{
		for (int j = 2000; j < year; j++)
		{
			if (IsLeapYear(j))
				daySum += 366;
			else
				daySum += 365;
		}
		int mod = daySum % 7;
		return (WeedDay_2000_1_1 + mod) % 7;
	}
	return WeedDay_2000_1_1;
}

//��ӡһ������
void PrintLine(int year, std::string& str1, std::string& str2)
{
	cout << year << "-" << str1 << "-" << str2 << endl;
	str1.clear();
	str2.clear();
}

//��ӡ����
void Print(int year, std::vector<int>& months, int WeedDay_CurYear)
{
	//��ӡԪ��
	string str1 = "01";
	string str2 = "01";
	PrintLine(year, str1, str2);
	//��ӡ��
	str1 = "01";
	int day = (8 - WeedDay_CurYear + 15);
	str2.push_back((day / 10) + '0');
	str2.push_back((day % 10) + '0');
	PrintLine(year, str1, str2);
	
	//��ӡ��ͳ����
	str1 = "02";
	day = (8 - (WeedDay_CurYear + months[1]) % 7 + 15);
	str2.push_back((day / 10) + '0');
	str2.push_back((day % 10) + '0');
	PrintLine(year, str1, str2);

	//��ӡ��ʿ������
	str1 = "05";
	int temp = (WeedDay_CurYear + months[1] + months[2] + months[3] + months[4] + months[5]) % 7;
	if (temp == 0)
		temp = 7;
	day = months[5] - (temp - 2);
	str2.push_back((day / 10) + '0');
	str2.push_back((day % 10) + '0');
	PrintLine(year, str1, str2);

	//��ӡ��������
	str1 = "07";
	str2 = "04";
	PrintLine(year, str1, str2);

	//��ӡ�Ͷ���
	str1 = "09";
	temp = (temp + months[6] + months[7] + months[8]) % 7;
	if (temp == 0)
		temp = 7;
	day = 7 - temp + 2;
	day = day % 7;
	str2.push_back((day / 10) + '0');
	str2.push_back((day % 10) + '0');
	PrintLine(year, str1, str2);

	//��ӡ�ж���
	str1 = "11";
	temp = (temp + months[9] + months[10]) % 7;
	if (temp == 0)
		temp = 7;
	if (temp <= 4)
		day = 22 - (4 - temp);
	else
		day = 29 - (temp - 4);
	str2.push_back((day / 10) + '0');
	str2.push_back((day % 10) + '0');
	PrintLine(year, str1, str2);

	//��ӡʥ����
	str1 = "12";
	str2 = "25";
	PrintLine(year, str1, str2);
}

bool IsPrime(int num)
{
	if (num < 2)
		return false;
	if (num == 2)
		return true;
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

void PrintPrime(int num)
{
	for (int i = 2; i <= num; i++)
	{
		if (IsPrime(i))
			cout << i << " ";
	}
	cout << endl;
}