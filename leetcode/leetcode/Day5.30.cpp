#include "PracticeHead.h"

//leetcode ---986区间列表的交集
//A = [[0, 2], [5, 10], [13, 23], [24, 25]], B = [[1, 5], [8, 12], [15, 24], [25, 26]]
//[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B)
{
	int i = 0;
	int j = 0;
	int max_begin;
	int min_end;
	vector<vector<int>> result;
	vector<int> temp;
	while (i < A.size() && j < B.size())
	{
		max_begin = max(A[i][0], B[j][0]);//找出两个列表起点的最大值,比如[0,2]和[1, 5],起点最大值为1，
		min_end = min(A[i][1], B[j][1]);//找出两个列表终点的最小值,比如[0,2]和[1, 5],终点最小值为2，
		if (max_begin < min_end)//这个判断很重要，成立表示有交集，不成立表示无交集，
			//比如[0,1]和[2,5],起点最大2，终点最小1，终点最小值小于起点最大值，所有没有交集
		{
			temp.clear();
			temp.push_back(max_begin);
			temp.push_back(min_end);
			result.push_back(temp);
		}

		if (A[i][1] <= B[j][1])
			i++;
		else
			j++;
	}
	return result;
}

//返回一句话的最后一个单词的长度
int lengthOfLastWord(string s)
{
	if (s.empty()) return 0;
	int pos = s.rfind(' ');//寻找到最后一个空格
	while (pos == s.length() - 1)//将末尾的空格全部删除
	{
		if (s.empty()) return 0;
		s.erase(pos);
		pos = s.rfind(' ');
	}
	int len = s.size();
	return s.length() - pos - 1;
}