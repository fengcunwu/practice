////冒泡排序法排列多个字符串
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	char ch;
//	ch = getchar();
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}
//	system("pause");
//	return 0;
//}
//使用main函数参数,实现计算器
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }

int(*pf)(int, int) = NULL;
char opc = 0;

struct operation {
	char name[5]; // 命令名 
	int(*pfun)(int, int); // 函数指针
	char c;
} ops[] = {
	{ "add", add, '+' },
	{ "sub", sub, '-' },
	{ "mul", mul, '*' }
};

void do_math(int argc, char *argv[])
{
	int i;
	for (i = 0; i< sizeof(ops) / sizeof(ops[0]); i++) {
		if (strcmp(ops[i].name, argv[0]) == 0) {
			pf = ops[i].pfun;
			opc = ops[i].c;
			break;
		}
	}

	int left = atoi(argv[1]);
	int right = atoi(argv[2]);
	printf("%s%c%s=%d\n", argv[1], opc, argv[2], pf(left, right));
}

void do_parse(char *buf)
{
	int argc = 0;
	char *argv[8] = {0};

	int i;
	int stats = 0;
	for (i = 0; buf[i] != '\0'; i++) {
		if (stats == 0 && !isspace(buf[i])) {
			stats = 1;
			argv[argc++] = buf + i;
		}
		else if (isspace(buf[i])) {
			stats = 0;
			buf[i] = '\0';
		}
	}
	argv[argc] = NULL;
	do_math(argc, argv);
}

int main(void)
{
	char buf[100] = {0};
	while (1) {
		printf("> ");
		memset(buf, 0x00, sizeof(buf));
		scanf_s("%[^\n]%*c", buf);
		if (strcmp(buf, "exit") == 0) break;
		do_parse(buf);
	}
}