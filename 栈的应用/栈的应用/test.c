#include "Stack.h"

//void teststack()//栈的实现接口
//{
//	Stack s;
//	InitStack(&s);
//	PushStack(&s, 1);//压栈
//	PushStack(&s, 10);
//	PushStack(&s, 100);
//	PushStack(&s, 11111);
//	PopStack(&s);//出栈
//	TopStack(&s);//获取栈顶元素
//	IsStackEmpty(&s);//判断栈是否为空 返回1为空
//	SizeStack(&s);//返回栈的大小，栈里元素个数
//	printf("栈顶元素为：%d\n", TopStack(&s));
//	//printf("%d", IsStackEmpty(&s));
//	//printf("%d\n", SizeStack(&s));
//}

void testmaze()//迷宫实现
{
	
	MapMaze map;
	InitMaze(&map);
	PrintMaze(map);

	Position enter;//入口
	enter.x = 7;
	enter.y = 1;

	MazeProblem(&map, enter);
	PrintMaze(map);
}

//testRPN()
//{
//	Cell RPN[] = { { DATA, 12 }, { DATA, 3 }, { DATA, 4 }, { ADD, 0 },
//	{ MUL, 0 }, { DATA, 6 }, { SUB, 0 }, { DATA, 8 }, { DATA, 2 }, { DIV, 0 }, { ADD, 0 } };
//
//	printf("计算结果为 %d\n", CalcRPN(RPN, sizeof(RPN) / sizeof(RPN[0])));
//}
//
//testbracket()
//{
//	char a[] = "(())abc{[(])}";//左右括号次序匹配不正确
//	char b[] = "(()))abc{[]}";//右括号多于左括号
//	char c[] = "(()()bcb{[]}";//左边括号多于右边括号
//	char d[] = "(())djfos{[]()}";//左右括号匹配正确
//	char e[] = "(()() [)(] )";
//
//	MatchBrackets(a);
//	MatchBrackets(b);
//	MatchBrackets(c);
//	MatchBrackets(d);
//	MatchBrackets(e);
//}

testHaveCirleMaze()
{
	MapMaze MapCirle;
	Position enter;//入口
	Stack ps;//回退需要的栈
	Stack ShortPass;//最短路径
	
	InitCirleMaze(&MapCirle);

	InitStack(&ps);
	InitStack(&ShortPass);

	PrintCirleMaze(MapCirle);
	printf("走迷宫：\n");

	enter.x = 7;
	enter.y = 1;

	if (!IsValidEnter(&MapCirle, enter))
	{
		printf("迷宫入口非法！！！\n");
		return;
	}

	HaveCirleMazeProblem(&MapCirle, enter, enter, &ps, &ShortPass);
	PrintCirleMaze(MapCirle);
	printf("最短路径为：");
	printf("%d ", SizeStack(&ShortPass));
}

int main()
{
	//teststack();//栈的基本操作
	//testmaze();//简单迷宫
	//testbracket();//括号匹配问题
	//testRPN();
	testHaveCirleMaze();
	system("pause");
	return 0;
}