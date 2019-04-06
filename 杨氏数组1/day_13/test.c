//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define NUM 10
//void change(int arr[NUM], int num)
//{
//	int left = 0;
//	int right = num - 1;
//	while (left < right)
//	{
//		while ((left < right) && arr[left] % 2 != 0)
//			left++;
//		while ((left < right) && arr[right] % 2 == 0)
//			right--;
//		if (((arr[left] % 2) == 0) && (arr[right] % 2) != 0)
//		{
//			int temp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = temp;
//		}
//	}
//}
//void Fuzhi(int arr[NUM], int num)
//{
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		arr[i] = rand() % 100;
//	}
//}
//void show(int arr[NUM], int num)
//{
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	srand(time(NULL));
//	int arr[NUM] = { 0 };
//	Fuzhi(arr, NUM);
//	show(arr, NUM);
//	printf("\n");
//	change(arr, NUM);
//	show(arr, NUM);
//	printf("\n");
//	system("pause");
//	return 0;
//}
#include <stdio.h>
#include <stdlib.h>
#define N 5
//在杨氏数组中查找
void show(int arr[N][N], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		printf("\n");
		for (j = 0; j < col; j++)
		{
			printf("%2d  ", arr[i][j]);
		}
	}
}
int find(int arr[N][N], int *row, int *col, int num)
{
	*row = 0;
	*col = N - 1;
	if (num < arr[0][0] && num > arr[N - 1][N - 1])
	{
		return 0;
	}
	else
	{
		while ((*row < N) && (*col >= 0))
		{
			if (num < arr[*row][*col])
			{
				(*col)--;
			}
			else if (num > arr[*row][*col])
			{
				(*row)++;
			}
			else
			{
                return 1;
			}	
		}
		return 0;
	}
}
int main()
{
	int num = 0;
	int row = 0;
	int col = 0;
	int arr[N][N] = { { 1, 3, 5, 7, 9 },
	{ 2, 4, 6, 8, 10 },
	{ 11, 13, 15, 17, 19 },
	{ 12, 14, 16, 18, 20 },
	{ 21, 23, 25, 27, 29 } };
	/*show(arr, N, N);
	printf("\n");
	printf("请输入你要查找的数字:");
	scanf_s("%d ", &num);*/
	int ret = find(arr, &row, &col, 6);
	if (ret == 1)
	{
		printf("找到了!!!\n");
		printf("row=%d col=%d\n", row, col);
	}
	else
	{
		printf("找不到!!!数组中没有这个数字!!!\n");
	}
	system("pause");
	return 0;
}
