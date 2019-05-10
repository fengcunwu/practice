#define _CRT_SECURE_NO_WARNINGS 1
#include "Comment_Convert.h"


int main()
{
	//打开一个文件,读取其中的字符
	FILE* pfin = NULL;//定义一个文件指针,用于读取文件
	FILE* pfout = NULL;//定义一个文件指针,用于写入这个文件

	pfin = fopen("input.c", "r");
	if (pfin == NULL)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	pfout = fopen("output.c", "w");
	if (pfout == NULL)
	{
		fclose(pfin);
		perror("open file for write");
		exit(EXIT_FAILURE);
	}
	//注释转换
	//.....
	DoCommentConvert(pfin, pfout);

	//转换成功,关闭文件
	fclose(pfin);
	pfin = NULL;
	fclose(pfout);
	pfout = NULL;

	printf("转换成功\n");
	system("pause");
	return 0;
}