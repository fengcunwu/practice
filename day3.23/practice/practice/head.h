#pragma once

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;
//动态规划，年终奖，从数组的左上方走到数组的右下方，得出路径之和的最大值
int getMost(vector<vector<int>>& board);

//数组的奇数位上全是奇数或者偶数位上全是偶数
void oddInOddEvenInEven(vector<int>& arr, int len);
void oddInOddEvenInEven_LL(vector<int>& arr, int len);

//猴子分桃问题
void Monkey_peach();

