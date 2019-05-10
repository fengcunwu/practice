#ifndef __COMMENT_CONVERT_H__
#define __COMMENT_CONVERT_H__

#include <stdio.h>
#include <stdlib.h>

//注释转换有四种状态,用枚举的形式定义
enum State
{
	NUL_STATE,//没有状态
	C_STATE,//c语言注释状态
	CPP_STATE,//c++注释状态
	END_STATE//文件结束EOF
};

void DoCommentConvert(FILE *pfin, FILE *pfout);
void Donulstate(FILE *pfin, FILE *pfout, enum State* ps);
void Docstate(FILE *pfin, FILE *pfout, enum State* ps);
void Docppstate(FILE *pfin, FILE *pfout, enum State* ps);
 
#endif //__COMMENT_CONVERT_H__