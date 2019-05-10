#include "Comment_Convert.h"

void Donulstate(FILE *pfin, FILE *pfout, enum State* ps)
{
	int first = fgetc(pfin);
	switch (first)//����״̬������״̬��
	{
	case '/'://��һ������'/'
	{
	 	int second = fgetc(pfin);
		switch (second) 
		{
		case '/'://�ڶ�������'/'
			fputc(first, pfout);
			fputc(second, pfout);
			*ps = CPP_STATE;
			break;
		case '*'://�ڶ�������'*'
			fputc(first, pfout);
			fputc('/', pfout);
			*ps = C_STATE;
			break;
		default://�ڶ������������ַ�
			fputc(first, pfout);
			fputc(second, pfout);
			break;
		}
	}
		break;
	case EOF://��һ�������ļ�������־
		*ps = END_STATE;
		break;
	default ://��һ�����������ַ�
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
		case NUL_STATE://��״̬���
			Donulstate(pfin, pfout, &state);
			break;
		case C_STATE://c����ע��״̬�����
			Docstate(pfin, pfout, &state);
			break;
		case CPP_STATE://c++����ע��״̬�����
			Docppstate(pfin, pfout, &state);
			break;
	    }
	}
	return;
}