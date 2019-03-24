#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef int DateType;
typedef struct seqlist
{
	DateType data[MAX];
	int sz;
}seqlist, *pSeqlist;

void Initseqlist(pSeqlist pSeq);
void Printflist(pSeqlist pSeq);
void Pushback(pSeqlist pSeq, DateType num);
void Popfount(pSeqlist pSeq);
int find(pSeqlist pSeq, DateType num);
void Insert(pSeqlist pSeq, int pos, DateType num);
void Erase(pSeqlist pSeq, int pos);
void Remove(pSeqlist pSeq, DateType num);
void RemoveALL(pSeqlist pSeq, DateType num);
void RemoveALL_OP(pSeqlist pSeq, DateType num);
int Size(pSeqlist pSeq);
int Empty(pSeqlist pSeq);
void Bubblesort(pSeqlist pSeq);
void Swap(DateType* pSeq1, DateType* pSeq2);
void Bubblesort(pSeqlist pSeq);
void Selectsort(pSeqlist pSeq);
int Binarysearch(pSeqlist pSeq, DateType num);
int Binarysearch_R(pSeqlist pSeq, int left, int right, DateType num);

#endif //__SEQLIST_H__