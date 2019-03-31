#include "HashBucketCapacity.h"

void testHashBC()
{
	HashBC pHBC;

	InitHashBC(&pHBC, 10/*DataToInt*/);
	InsertHashBC(&pHBC, 11);
	InsertHashBC(&pHBC, 54);
	InsertHashBC(&pHBC, 22);
	InsertHashBC(&pHBC, 24);
	InsertHashBC(&pHBC, 76);
	InsertHashBC(&pHBC, 19);
	InsertHashBC(&pHBC, 53);
	InsertHashBC(&pHBC, 37);
	InsertHashBC(&pHBC, 96);
	InsertHashBC(&pHBC, 73);
	InsertHashBC(&pHBC, 85);
	InsertHashBC(&pHBC, 63);
	InsertHashBC(&pHBC, 47);
	PrintHashBC(&pHBC);
}

int main()
{
	testHashBC();
	system("pause");
	return 0;
}