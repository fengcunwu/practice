#include "Stack.h"

void InitStack(Stack *s)
{
	assert(s);
	s->top = 0;
}

void PushStack(Stack *s, DataType data)
{
	assert(s);
	if (s->top < MAXSIZE)
	{
		s->array[s->top] = data;
		s->top++;
	}
	else
	{
		printf("ջ�������޷�ѹջ������");
		return;
	}
}

void PopStack(Stack *s)
{
	assert(s);
	if (s->top == 0)
	{
		printf("ջΪ�գ��޷�ɾ������");
		return;
	}
	s->top--;
}

DataType TopStack(Stack *s)
{
	assert(s);
	return s->array[s->top - 1];
}

int IsStackEmpty(Stack *s)
{
	assert(s);
	return 0 == s->top;
}

int SizeStack(Stack *s)
{
	assert(s);
	return s->top;
}

int IsBrackets(char ch)
{
	if (('(' == ch || ')' == ch) || ('[' == ch || ']' == ch) ||
		('{' == ch || '}' == ch))
		return 1;
	return 0;
}

//void MatchBrackets(const char* str)
//{
//	int i = 0;
//	int sz = 0;
//	Stack ps;
//
//	InitStack(&ps);
//
//	if (NULL == str)
//		return;
//	
//	sz = strlen(str);
//	for (i = 0; i < sz; i++)
//	{
//		if (IsBrackets(str[i]))
//		{
//			//�������ţ�Ȼ��ѹջ
//			if ('(' == str[i] || '[' == str[i] || '{' == str[i])
//			{
//				PushStack(&ps, str[i]);
//			}
//			else
//			{
//				char ch;
//				//���ұ����ţ�ȡջ��Ԫ�غ�������űȽϣ��Ƿ�ƥ��
//				if (IsStackEmpty(&ps))
//				{
//					printf("�ұ����ű�������Ŷ�\n");
//					return;
//				}
//				else
//				{
//					ch = TopStack(&ps);
//					if (!((str[i] == ')' && ch == '(')
//						|| (str[i] == ']' && ch == '[')
//						|| (str[i] == '}' && ch == '{')))
//					{
//						printf("����ƥ������������\n");
//						return;
//					}
//					PopStack(&ps);
//				}
//			}
//		}
//	}
//	if (IsStackEmpty(&ps))
//		printf("����ƥ����ȷ������\n");
//	else
//		printf("������ű��ұ����Ŷ࣡��\n");
//
//}

void InitMaze(MapMaze* map)
{
	int array[ROW][COL] = { { 0, 0, 0, 0, 0, 0, 0, 0 },
							{ 0, 0, 0, 1, 0, 0, 0, 0 },
							{ 0, 0, 0, 1, 0, 0, 1, 0 },
							{ 0, 1, 1, 1, 1, 1, 1, 0 },
							{ 0, 1, 0, 0, 1, 0, 1, 0 },
							{ 0, 1, 0, 0, 1, 0, 1, 1 },
							{ 0, 1, 0, 1, 1, 0, 0, 0 },
							{ 0, 1, 0, 0, 0, 0, 0, 0 }, };
	int i = 0, j = 0;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			map->maze[i][j] = array[i][j];
		}
	}
}

void PrintMaze(MapMaze map)
{
	int i = 0, j = 0;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf(" %d ", map.maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int IsNextPass(MapMaze* map, Position next)
{
	if (next.x >= 0 && next.x < COL && next.y < ROW && next.x >= 0)
	{
		if (map->maze[next.x][next.y] == 1)
			return 1;
	}

	return 0;
}

int IsValidEnter(MapMaze* m, Position enter)
{
	assert(m);
	//�ж��Ƿ��ڱ߽�
	if (enter.x == 0 || enter.x == COL - 1 || enter.y == 0 || enter.y == ROW - 1)
	{
		if (m->maze[enter.x][enter.y] == 1)//�жϸ�λ�õ���ֵ�Ƿ�Ϊ1
			return 1;
	}
	return 0;
}

int IsExit(Position cur, Position enter)
{
	if (cur.x == 0 || cur.x == COL - 1 || cur.y == 0 || cur.y == ROW - 1)
	{
		if (cur.x != enter.x || cur.y != enter.y)
		{
			return 1;
		}
	}
		
	return 0;
}


void MazeProblem(MapMaze* map, Position enter)
{
	Stack ps;
	Position cur, next;
	assert(map);
	InitStack(&ps);

	if (!IsValidEnter(map, enter))
	{
		printf("�Թ���ڷǷ�������\n");
		return;
	}
	PushStack(&ps, enter);

	while (!IsStackEmpty(&ps))
	{

		//ȡջ��Ԫ��
		cur = TopStack(&ps);
		map->maze[cur.x][cur.y] = 2;

		//ÿ��һ������Ƿ�Ϊ����
		if (IsExit(cur, enter))
			return;

		//������
		next = cur;
		next.y -= 1;
		if (IsNextPass(map, next))
		{
			PushStack(&ps, next);
			continue;
		}

		//������
		next = cur;
		next.x -= 1;
		if (IsNextPass(map, next))
		{
			PushStack(&ps, next);
			continue;
		}

		//������
		next = cur;
		next.x += 1;
		if (IsNextPass(map, next))
		{
			PushStack(&ps, next);
			continue;
		}

		//������
		next = cur;
		next.y += 1;
		if (IsNextPass(map, next))
		{
			PushStack(&ps, next);
			continue;
		}

		//����·���߲�ͨ
		map->maze[cur.x][cur.y] = 9;
		PopStack(&ps);
	}
}

//int CalcRPN(Cell* RPN, int sz)
//{
//	int i = 0;
//	Stack ps;
//	InitStack(&ps);
//	for (i = 0; i < sz; i++)
//	{
//		if (RPN[i].op == DATA)
//		{
//			PushStack(&ps, RPN[i].data);
//		}
//		else
//		{
//			int left = 0, right = 0;
//			right = TopStack(&ps);
//			PopStack(&ps);
//			left = TopStack(&ps);
//			PopStack(&ps);
//			switch (RPN[i].op)
//			{
//			case ADD:
//				PushStack(&ps, left + right);
//				break;
//			case SUB:
//				PushStack(&ps, left - right);
//				break;
//			case MUL:
//				PushStack(&ps, left * right);
//				break;
//			case DIV:
//				if (0 == right)
//				{
//					printf("����Ϊ0,�����Ƿ�");
//					return 0;
//				}
//				PushStack(&ps, left / right);
//				break;
//			}
//		}
//	}
//	return TopStack(&ps);
//}

void InitCirleMaze(MapMaze* MapCirle)
{
	int array[ROW][COL] = { { 0, 0, 0, 0, 0, 0, 0, 0 },
							{ 0, 0, 0, 0, 0, 0, 0, 0 },
							{ 0, 1, 1, 1, 1, 0, 0, 0 },
							{ 0, 1, 0, 0, 1, 0, 0, 0 },
							{ 0, 1, 0, 0, 1, 0, 0, 0 },
							{ 0, 1, 0, 0, 1, 0, 0, 0 },
							{ 0, 1, 1, 1, 1, 1, 1, 1 },
							{ 0, 1, 0, 0, 0, 0, 0, 0 }, };
	int i = 0, j = 0;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			MapCirle->maze[i][j] = array[i][j];
		}
	}
}

void PrintCirleMaze(MapMaze MapCirle)
{
	int i = 0, j = 0;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf(" %d ", MapCirle.maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int IsNextPassCirle(MapMaze* map, Position next, Position pCur)
{
	if ((next.x == 0 || next.x < ROW) && (next.y == 0 || next.y < COL))
	{
		if (map->maze[next.x][next.y] == 1 ||
			map->maze[next.x][next.y] > map->maze[pCur.x][pCur.y])
		{
			return 1;
		}
	}
	return 0;
}

void SaveShortPass(Stack* ps, Stack* ShortPass)
{
	int i = 0;
	for (i = 0; i < SizeStack(ps); i++)
	{
		ShortPass->array[i] = ps->array[i];
	}
	ShortPass->top = SizeStack(ps);
}

void HaveCirleMazeProblem(MapMaze* MapCirle, Position enter, Position pCur, Stack* ps, Stack* ShortPass)
{
	Position next;
	assert(MapCirle);

	if (IsExit(pCur, enter))
	{
		PushStack(ps, pCur);
		if (IsStackEmpty(ShortPass) || (SizeStack(ps) < SizeStack(ShortPass)))
		{
			SaveShortPass(ps, ShortPass);
		}
		PopStack(ps);
		return;
	}

	if (IsStackEmpty(ps))
		MapCirle->maze[pCur.x][pCur.y] = 2;
	PushStack(ps, pCur);



	//��
	next = pCur;
	next.x -= 1;
	if (IsNextPassCirle(MapCirle, next, pCur))
	{
		MapCirle->maze[next.x][next.y] = MapCirle->maze[pCur.x][pCur.y] + 1;
		HaveCirleMazeProblem(MapCirle, enter, next, ps, ShortPass);
	}

	//��

	next = pCur;
	next.y -= 1;
	if (IsNextPassCirle(MapCirle, next, pCur))
	{
		MapCirle->maze[next.x][next.y] = MapCirle->maze[pCur.x][pCur.y] + 1;
		HaveCirleMazeProblem(MapCirle, enter, next, ps, ShortPass);
	}

	//��

	next = pCur;
	next.y += 1;
	if (IsNextPassCirle(MapCirle, next, pCur))
	{
		MapCirle->maze[next.x][next.y] = MapCirle->maze[pCur.x][pCur.y] + 1;
		HaveCirleMazeProblem(MapCirle, enter, next, ps, ShortPass);
	}

	//��

	next = pCur;
	next.x += 1;
	if (IsNextPassCirle(MapCirle, next, pCur))
	{
		MapCirle->maze[next.x][next.y] = MapCirle->maze[pCur.x][pCur.y] + 1;
		HaveCirleMazeProblem(MapCirle, enter, next, ps, ShortPass);
	}

	PopStack(&ps);
}
