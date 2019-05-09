////返回值
//#include <stdio.h>
//#include <stdlib.h>
//unsigned  int reverse_bit(unsigned int value)
//{
//	int ret = 0;
//	unsigned int len = sizeof(unsigned int)* 8;
//	int i;
//	for (i = 0; i<len; i++)
//	{
//		int r = value & 0x01;
//		ret |= r << (len - i - 1);
//		value >>= 1;
//	}
//	return ret;
//}
//int main()
//{
//	int num = 0;
//	printf("请输入一个数字:>");
//	scanf_s("%u", &num);
//	printf("%u\n", reverse_bit(num));
//	system("pause");
//	return 0;
//}
//位运算找出不同的数字
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int arr[5] = { 1, 2, 3, 1, 2 };
//	int ret = 0;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ret = ret^arr[i];
//	}
//	printf("%d ", ret);
//	system("pause");
//	return 0;
//}
//以单词为单位逆序
//#include <stdio.h>
//#include <stdlib.h>
//
//void jiaohuan(char *a, char *b)
//{
//		while (a < b)
//		{
//			char t = *a;
//			*a = *b;
//			*b = t;
//			a++;
//			b--;
//		}
//}
//int length(char *s)
//{
//		int i = 0;
//		while (s[i] != '\0')
//			i++;
//		return i;
//}
//
//int main()
//{
//	char buf[] = "student  a am i";
//
//	jiaohuan(buf, buf + length(buf) - 1);
//	printf("buf=%s\n", buf);
//
//	int i;
//	char *p = buf;
//	char *q = buf;
//
//	int status = 0;
//	for (i = 0; buf[i] != '\0'; i++)
//	{
//		if ((status == 0) && (buf[i] != ' '))
//		{
//			p = buf + i;
//			status = 1;
//		}
//		else if (buf[i] == ' ' && status == 1)
//		{
//			q = buf + i - 1;
//			status = 0;
//			jiaohuan(p, q);
//		}
//	}
//	jiaohuan(p, buf + i - 1);
//	printf("buf=[%s]\n", buf); 
//	system("pause");
//	return 0;
//
//}
#include <stdio.h> 
#include <stdlib.h>
int main()
{
	int num = 0;
	printf("请输入一个数字:");
	scanf_s("%d", &num);
	printf("%d", num);
	system("pause");
	return 0;
}