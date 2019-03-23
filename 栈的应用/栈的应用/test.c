#include "Stack.h"

//void teststack()//ջ��ʵ�ֽӿ�
//{
//	Stack s;
//	InitStack(&s);
//	PushStack(&s, 1);//ѹջ
//	PushStack(&s, 10);
//	PushStack(&s, 100);
//	PushStack(&s, 11111);
//	PopStack(&s);//��ջ
//	TopStack(&s);//��ȡջ��Ԫ��
//	IsStackEmpty(&s);//�ж�ջ�Ƿ�Ϊ�� ����1Ϊ��
//	SizeStack(&s);//����ջ�Ĵ�С��ջ��Ԫ�ظ���
//	printf("ջ��Ԫ��Ϊ��%d\n", TopStack(&s));
//	//printf("%d", IsStackEmpty(&s));
//	//printf("%d\n", SizeStack(&s));
//}

void testmaze()//�Թ�ʵ��
{
	
	MapMaze map;
	InitMaze(&map);
	PrintMaze(map);

	Position enter;//���
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
//	printf("������Ϊ %d\n", CalcRPN(RPN, sizeof(RPN) / sizeof(RPN[0])));
//}
//
//testbracket()
//{
//	char a[] = "(())abc{[(])}";//�������Ŵ���ƥ�䲻��ȷ
//	char b[] = "(()))abc{[]}";//�����Ŷ���������
//	char c[] = "(()()bcb{[]}";//������Ŷ����ұ�����
//	char d[] = "(())djfos{[]()}";//��������ƥ����ȷ
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
	Position enter;//���
	Stack ps;//������Ҫ��ջ
	Stack ShortPass;//���·��
	
	InitCirleMaze(&MapCirle);

	InitStack(&ps);
	InitStack(&ShortPass);

	PrintCirleMaze(MapCirle);
	printf("���Թ���\n");

	enter.x = 7;
	enter.y = 1;

	if (!IsValidEnter(&MapCirle, enter))
	{
		printf("�Թ���ڷǷ�������\n");
		return;
	}

	HaveCirleMazeProblem(&MapCirle, enter, enter, &ps, &ShortPass);
	PrintCirleMaze(MapCirle);
	printf("���·��Ϊ��");
	printf("%d ", SizeStack(&ShortPass));
}

int main()
{
	//teststack();//ջ�Ļ�������
	//testmaze();//���Թ�
	//testbracket();//����ƥ������
	//testRPN();
	testHaveCirleMaze();
	system("pause");
	return 0;
}