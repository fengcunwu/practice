#define _CRT_SECURE_NO_WARNINGS 1
#include "Comment_Convert.h"


int main()
{
	//��һ���ļ�,��ȡ���е��ַ�
	FILE* pfin = NULL;//����һ���ļ�ָ��,���ڶ�ȡ�ļ�
	FILE* pfout = NULL;//����һ���ļ�ָ��,����д������ļ�

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
	//ע��ת��
	//.....
	DoCommentConvert(pfin, pfout);

	//ת���ɹ�,�ر��ļ�
	fclose(pfin);
	pfin = NULL;
	fclose(pfout);
	pfout = NULL;

	printf("ת���ɹ�\n");
	system("pause");
	return 0;
}