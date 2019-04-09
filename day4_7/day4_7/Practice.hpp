#pragma once

#include <iostream>
#include <string>
#include <vector>

//一，美国节日
//美国节日
//1月1日：元旦
//* 1月的第三个星期一：马丁·路德·金纪念日
//* 2月的第三个星期一：总统节
//* 5月的最后一个星期一：阵亡将士纪念日
//* 7月4日：美国国庆
//* 9月的第一个星期一：劳动节
//* 11月的第四个星期四：感恩节
//* 12月25日：圣诞节
#define FOR(i,n) for(i = 1; i < n; i++)

//判断是否是闰年
bool IsLeapYear(int year);

//返回某一年的一月一号是星期几
int ReturnWeedDay(int year);

//打印一行日期
void PrintLine(int year, std::string& str1, std::string& str2);

//打印节日
void Print(int year, std::vector<int>& months, int WeedDay_CurYear);


//分解因数(分解素因数)
bool IsPrime(int num);
void PrintPrime(int num);

//斐波那契凤尾
void test3();
//字符串查找
void Test4();
void Test4_KMP();