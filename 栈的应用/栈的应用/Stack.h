#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAXSIZE 100
#define ROW 8
#define COL 8

typedef struct Position//迷宫中每走一步的位置
{
	int x;//行
	int y;//列
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

typedef struct MapMaze//迷宫的地图
{
	int maze[ROW][COL];
}MapMaze;

void InitStack(Stack *s);
void PushStack(Stack *s, DataType data);
void PopStack(Stack *s);
DataType TopStack(Stack *s);
int IsStackEmpty(Stack *s);
int SizeStack(Stack *s);

///////////////////////括号匹配问题/////////////////////

void MatchBrackets(const char* str);
int IsBrackets(char ch);

//////////////////////简单迷宫/////////////////////////

void InitMaze(MapMaze* map);
void PrintMaze(MapMaze map);
void MazeProblem(MapMaze* map, Position enter);
int IsNextPass(MapMaze* map, Position next);
int IsValidEnter(MapMaze* m, Position enter);
int IsExit(Position cur, Position enter);

/////////////////////中缀表达式/////////////////////////

int CalcRPN(Cell* RPN, int sz);

/////////////////////////带环迷宫///////////////////////

void InitCirleMaze(MapMaze* MapCirle);
void PrintCirleMaze(MapMaze MapCirle);
void HaveCirleMazeProblem(MapMaze* MapCirle, Position enter, Position pCur, Stack* ps, Stack* ShortPass);
int IsNextPassCirle(MapMaze* map, Position next, Position pCur);
void SaveShortPass(Stack* ps, Stack* ShortPass);


#endif __STACK_H__