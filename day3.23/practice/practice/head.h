#pragma once

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;
//��̬�滮�����ս�������������Ϸ��ߵ���������·����ó�·��֮�͵����ֵ
int getMost(vector<vector<int>>& board);

//���������λ��ȫ����������ż��λ��ȫ��ż��
void oddInOddEvenInEven(vector<int>& arr, int len);
void oddInOddEvenInEven_LL(vector<int>& arr, int len);

//���ӷ�������
void Monkey_peach();

