#include "Comment_Convert.h"

void Donulstate(FILE *pfin, FILE *pfout, enum State* ps)
{
	int first = fgetc(pfin);
	switch (first)//从无状态到其他状态，
	{
	case '/'://第一个遇到'/'
	{
	 	int second = fgetc(pfin);
		switch (second) 
		{
		case '/'://第二个遇到'/'
			fputc(first, pfout);
			fputc(second, pfout);
			*ps = CPP_STATE;
			break;
		case '*'://第二个遇到'*'
			fputc(first, pfout);
			fputc('/', pfout);
			*ps = C_STATE;
			break;
		default://第二个遇到正常字符
			fputc(first, pfout);
			fputc(second, pfout);
			break;
		}
	}
		break;
	case EOF://第一个遇到文件结束标志
		*ps = END_STATE;
		break;
	default ://第一个遇到正常字符
		fputc(first, pfout);
		break;
	}

}

void Docstate(FILE *pfin, FILE *pfout, enum State* ps)
{
	int first = fgetc(pfin);
	switch (first)
	{
	case '*':
	{
		int second = fgetc(pfin);
		switch (second)
		{
		case '/' :
			*ps = NUL_STATE;
			break;
		case '*':
			ungetc('*', pfin);
			*ps = C_STATE;
			break;
		default :
			fputc(second, pfout);
			break;
		}
	}
		break;
	case '\\':
	{
		int second = fgetc(pfin);
		switch (second)
		{
		case 'n':
			fputc(first, pfout);
			fputc(second, pfout);
			fputc('/', pfout);
			fputc('/', pfout);
			break;
		default :
			fputc(first, pfout);
			fputc(second, pfout);
			break;
		}
	}
		break;
	default :
		fputc(first, pfout);
		break;
	}
}

void Docppstate(FILE *pfin, FILE *pfout, enum State* ps)
{
	int first = fgetc(pfin);
	switch (first)
	{
	case '/' :
	{
		int second = fgetc(pfin);
		switch (second)
		{
		case 'n':
		{
			fputc(first, pfout);
			fputc(second, pfout);
			*ps = NUL_STATE;
		}
			break;
		default:
			fputc(first, pfout);
			fputc(second, pfout);
			break;
		}
	}
		break;
	case EOF:
		*ps = END_STATE;
		break;
	default:
		fputc(first, pfout);
		break;
	}
}

void DoCommentConvert(FILE *pfin, FILE *pfout)
{
	enum State state = NUL_STATE;

	while(state != END_STATE)
	{
		switch (state)
		{
		case NUL_STATE://无状态情况
			Donulstate(pfin, pfout, &state);
			break;
		case C_STATE://c语言注释状态的情况
			Docstate(pfin, pfout, &state);
			break;
		case CPP_STATE://c++语言注释状态的情况
			Docppstate(pfin, pfout, &state);
			break;
	    }
	}
	return;
}