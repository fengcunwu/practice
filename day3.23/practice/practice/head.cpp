#include "head.h"

using namespace std;

//动态规划，年终奖，从数组的左上方走到数组的右下方，得出路径之和的最大值

int getMost(vector<vector<int>> & board)
{
	// write code here
	int row = board.size();
	int col = board[0].size();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == 0 && j == 0)
				continue;
			else if (i == 0)
				board[i][j] += board[i][j - 1];
			else if (j == 0)
				board[i][j] += board[i - 1][j];
			else
			{
				board[i][j] += max(board[i - 1][j], board[i][j - 1]);
			}
		}
	}
	return board[row - 1][col - 1];
}

//奇数位上都是奇数或者偶数位上都是偶数
void oddInOddEvenInEven(vector<int>& arr, int len) {
	int begin = 0;
	int end = len - 1;
	while (begin < end)
	{
		if ((begin % 2 == 0 && arr[begin] % 2 == 0) || (begin % 2 == 1 && arr[begin] % 2 == 1))
			begin++;
		else
		{
			if ((end % 2 == 0 && arr[end] % 2 == 0) || (end % 2 == 1 && arr[end] % 2 == 1))
				end--;
			else
			{
				swap(arr[begin], arr[end]);
			}
		}
	}
}

void oddInOddEvenInEven_LL(vector<int>& arr, int len) {
	int i = 0, j = 1;
	while (i < len && j < len){
		while (i < len && (arr[i] % 2) == 0) i += 2;
		while (j < len && (arr[j] % 2) == 1) j += 2;
		if (i < len && j < len) swap(arr[i], arr[j]);
	}
}

void Monkey_peach()
{
	int temp = 0;
	vector<int> arr;
	while (cin >> temp)
	{
		if (temp != 0)
			arr.push_back(temp);
		else
			break;
	}
	for (auto i = 0; i < arr.size(); i++)
	{
		double num = pow(5, arr[i]);
		cout << num - 4 << " ";
		double old = pow(4, arr[i]) + arr[i] - 4;
		cout << old << endl;;
	}
}