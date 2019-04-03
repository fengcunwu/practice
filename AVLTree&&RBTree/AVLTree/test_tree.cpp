//#include "AVLTree.h"
#include "RBTree.h"

#if 0
void TestAVLTree()
{
	//int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int> avl;
	for (auto &e : arr)
	{
		avl.Insert(e);
	}
	avl.InOrder();
	cout << endl;
	if (avl.IsAVLTree())
		cout << "yes" << endl;
	else
		cout << "no" << endl;

}

#endif

void TestRBTree()
{
	//int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	RBTree<int> rbt;
	for (auto &e : arr)
	{
		rbt.Insert(e);
	}
	rbt.InOrder();
	cout << rbt.Size() << endl;
	if (rbt.IsRBTree())
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}

int main()
{
	//TestAVLTree();
	TestRBTree();
	system("pause");
	return 0;
}

