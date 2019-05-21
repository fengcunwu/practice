#include "PracticeHead.h"

//z�����ַ���
//ʾ�� 2:
//
//���� : s = "LEETCODEISHIRING", numRows = 4
//��� : "LDREOEIIECIHNTSG"
// ���� :
//
//	L     D     R
//	E   O E   I I
//	E C   I H   N
//	T     S     G
string convert(string s, int numRows) {
	string result("");
	if (numRows == 1 || s.size() <= numRows)//�������Ϊ1���ߴ�����ַ���С��������ֱ�ӷ���
		return s;
	for (int rows = 0; rows < numRows; rows++){
		int first = rows;
		int second = 2 * numRows - 2 - rows;//���ǽ����ص㣬�ڶ��µ�һ����ʱ����Ҫ������ȷ�ĵڶ���
		for (; first < s.size();)
		{
			result += s[first];
			if (rows != 0 && rows != numRows - 1 && second < s.size()){
				result += s[second];
			}
			first += 2 * numRows - 2;
			second += 2 * numRows - 2;
		}
	}
	return result;
}


//myAtoi
int myAtoi(string str) {
	long result = 0;
	bool isUint = true;
	bool isStart = true;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '-' && isStart) {
			isStart = false;
			isUint = false;
		}
		else if ((str[i] < '0' || str[i] > '9')  && isStart) {
			continue;
		}
		else if (str[i] == '+' && isStart) {
			isStart = false;
			isUint = true;
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			isStart = false;
			result = result * 10 + (str[i] - '0');
			if (result != (int)result){
				if (isUint) {
					return INT_MAX;
				}
				else {
					return INT_MIN;
				}
			}
		}
		else {
			break;
		}
	}
	if (!isUint) {
		result = 0 - result;
	}

	return result;
}

//leetcode--9
//�ж�һ��int�͵����Ƿ��ǻ�����
bool isPalindrome(int x) {
	if (x < 0)
		return false;
	vector<short> arr;
	int i = 0;
	while (x)
	{
		arr.push_back(x % 10);
		x = x / 10;
	}
	for (i = 0; i < arr.size() / 2; i++)
	{
		if (arr[i] != arr[arr.size() - 1 - i])
			return false;
	}
	return true;
}