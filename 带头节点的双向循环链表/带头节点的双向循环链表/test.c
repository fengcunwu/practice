#include "DList.h"

void test()
{
	DList* pHead;
	DList* pos = NULL;
	InitDList(&pHead);//已经有头结点
	/*PushBackDList(pHead, 1);
	PushBackDList(pHead, 2);
	PushBackDList(pHead, 3);
	PushBackDList(pHead, 4);
	PushBackDList(pHead, 5);
	PushBackDList(pHead, 6);
	PopBackDList(pHead);*/
	PushFrontDList(pHead, 1);
	PushFrontDList(pHead, 2);
	PushFrontDList(pHead, 3);
	PushFrontDList(pHead, 4);
	PushFrontDList(pHead, 5);
	PushFrontDList(pHead, 6);

	PopFrontDList(pHead);
	/*pos = FindDList(pHead, 2);
	InsertDList(pos, 10);*/
	PrintDList(pHead);
	/*DestroyDList(&pHead);
	PrintDList(pHead);*/
}

int main()
{
	test();
	system("pause");
	return 0;
}