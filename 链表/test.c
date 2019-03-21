#include "Linklist.h"

void test()
{
	pList plist;
	pList pNew = NULL;
	int i = 0;
	Initlinklist(&plist);
	for (i = 0; i < 5; i++)
	{
        Pushback(&plist, i);
	}
	DestroyLinkList(&plist);
	Printflinklist(plist);
	/*for (i = 0; i < 5; i++)
	{
		Pushfront(&plist, i);
	}
	Printflinklist(plist);
	Popfront(&plist);
	Popfront(&plist);*/
    pNew = Find(plist, 0);
	/*printf("%d\n", pCur->data);*/
	Insert(&plist, pNew, 29);
	Printflinklist(plist);
}

void testremove()
{
	pList plist;
	pList pNew = NULL;
	int i = 0;
	int ret = 0;
	Initlinklist(&plist);
	for (i = 0; i < 8; i++)
	{
		Pushback(&plist, i + 1);
	}
	Pushback(&plist, 2);
	Printflinklist(plist);
	pNew = Find(plist, 2);
	/*Erase(&plist, pNew);*/
	/*Remove(&plist, 8);*/
	/*RemoveAll(&plist, 2);*/
	/*ret = GetListLength(plist);
	printf("%d\n", ret);*/
	EraseNotTailNode(pNew);
	Printflinklist(plist);
}

int main()
{
	/*test();*/
	testremove();
	system("pause");
	return 0;
}