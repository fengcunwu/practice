#ifndef __COMMENT_CONVERT_H__
#define __COMMENT_CONVERT_H__

#include <stdio.h>
#include <stdlib.h>

//ע��ת��������״̬,��ö�ٵ���ʽ����
enum State
{
	NUL_STATE,//û��״̬
	C_STATE,//c����ע��״̬
	CPP_STATE,//c++ע��״̬
	END_STATE//�ļ�����EOF
};

void DoCommentConvert(FILE *pfin, FILE *pfout);
void Donulstate(FILE *pfin, FILE *pfout, enum State* ps);
void Docstate(FILE *pfin, FILE *pfout, enum State* ps);
void Docppstate(FILE *pfin, FILE *pfout, enum State* ps);
 
#endif //__COMMENT_CONVERT_H__