#pragma once

#include <iostream>
#include <string>
#include <vector>

//һ����������
//��������
//1��1�գ�Ԫ��
//* 1�µĵ���������һ������·�¡��������
//* 2�µĵ���������һ����ͳ��
//* 5�µ����һ������һ��������ʿ������
//* 7��4�գ���������
//* 9�µĵ�һ������һ���Ͷ���
//* 11�µĵ��ĸ������ģ��ж���
//* 12��25�գ�ʥ����
#define FOR(i,n) for(i = 1; i < n; i++)

//�ж��Ƿ�������
bool IsLeapYear(int year);

//����ĳһ���һ��һ�������ڼ�
int ReturnWeedDay(int year);

//��ӡһ������
void PrintLine(int year, std::string& str1, std::string& str2);

//��ӡ����
void Print(int year, std::vector<int>& months, int WeedDay_CurYear);


//�ֽ�����(�ֽ�������)
bool IsPrime(int num);
void PrintPrime(int num);

//쳲�������β
void test3();
//�ַ�������
void Test4();
void Test4_KMP();