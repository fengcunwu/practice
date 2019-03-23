#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAXSIZE 100
#define ROW 8
#define COL 8

typedef struct Position//�Թ���ÿ��һ����λ��
{
	int x;//��
	int y;//��
}Position;

//typedef int DataType;
typedef Position DataType;

typedef enum 
{  
	ADD,
	SUB,
	MUL,
	DIV,
	DATA
}OPERATOR;

typedef struct Cell
{
	OPERATOR op;
	int data;
}Cell;

typedef struct Stack
{
	DataType array[MAXSIZE];
	int top;
}Stack;

typedef struct MapMaze//�Թ��ĵ�ͼ
{
	int maze[ROW][COL];
}MapMaze;

void InitStack(Stack *s);
void PushStack(Stack *s, DataType data);
void PopStack(Stack *s);
DataType TopStack(Stack *s);
int IsStackEmpty(Stack *s);
int SizeStack(Stack *s);

///////////////////////����ƥ������/////////////////////

void MatchBrackets(const char* str);
int IsBrackets(char ch);

//////////////////////���Թ�/////////////////////////

void InitMaze(MapMaze* map);
void PrintMaze(MapMaze map);
void MazeProblem(MapMaze* map, Position enter);
int IsNextPass(MapMaze* map, Position next);
int IsValidEnter(MapMaze* m, Position enter);
int IsExit(Position cur, Position enter);

/////////////////////��׺���ʽ/////////////////////////

int CalcRPN(Cell* RPN, int sz);

/////////////////////////�����Թ�///////////////////////

void InitCirleMaze(MapMaze* MapCirle);
void PrintCirleMaze(MapMaze MapCirle);
void HaveCirleMazeProblem(MapMaze* MapCirle, Position enter, Position pCur, Stack* ps, Stack* ShortPass);
int IsNextPassCirle(MapMaze* map, Position next, Position pCur);
void SaveShortPass(Stack* ps, Stack* ShortPass);


#endif __STACK_H__