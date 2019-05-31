#include "PracticeHead.h"

//leetcode ---986�����б�Ľ���
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
		max_begin = max(A[i][0], B[j][0]);//�ҳ������б��������ֵ,����[0,2]��[1, 5],������ֵΪ1��
		min_end = min(A[i][1], B[j][1]);//�ҳ������б��յ����Сֵ,����[0,2]��[1, 5],�յ���СֵΪ2��
		if (max_begin < min_end)//����жϺ���Ҫ��������ʾ�н�������������ʾ�޽�����
			//����[0,1]��[2,5],������2���յ���С1���յ���СֵС��������ֵ������û�н���
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

//����һ�仰�����һ�����ʵĳ���
int lengthOfLastWord(string s)
{
	if (s.empty()) return 0;
	int pos = s.rfind(' ');//Ѱ�ҵ����һ���ո�
	while (pos == s.length() - 1)//��ĩβ�Ŀո�ȫ��ɾ��
	{
		if (s.empty()) return 0;
		s.erase(pos);
		pos = s.rfind(' ');
	}
	int len = s.size();
	return s.length() - pos - 1;
}