#include "Hash.h"


void test()
{
	HashTable pHT;

	InitHashTable(&pHT);
	InsertHashTable(&pHT, 28);
	InsertHashTable(&pHT, 13);
	InsertHashTable(&pHT, 16);
	InsertHashTable(&pHT, 49);
	InsertHashTable(&pHT, 45);
	InsertHashTable(&pHT, 18);
	DeleteHashTable(&pHT, 18);
	if (FindHashTable(&pHT, 18) == -1)
		printf("�������ڹ�ϣ���ﲻ���ڣ�����\n");
	else
		printf("�����ݵ��±�Ϊ %d ", FindHashTable(&pHT, 18));
	printf("�ù�ϣ��Ĵ�СΪ %d \n", SizeHashTable(&pHT));
}

void testCapacity()
{
	HashTable pHT;

	InitHashTable_(&pHT, 10, DataToInt);

	InsertHashTable_(&pHT, 1);
	InsertHashTable_(&pHT, 12);
	InsertHashTable_(&pHT, 43);
	InsertHashTable_(&pHT, 64);
	InsertHashTable_(&pHT, 53);
	InsertHashTable_(&pHT, 75);
	InsertHashTable_(&pHT, 97);
	PrintHashTable(&pHT);
	InsertHashTable_(&pHT, 84);
	InsertHashTable_(&pHT, 36);
	DeleteHashTable_(&pHT, 43);
	PrintHashTable(&pHT);
	if (FindHashTable(&pHT, 43) != -1)
		printf("�ҵ��ˣ��±�Ϊ%d\n", FindHashTable(&pHT, 43));
	else
		printf("�Ҳ������������ڹ�ϣ���ﲻ����\n");
	printf("��ϣ��Ĵ�СΪ%d\n", SizeHashTable(&pHT));

}

void testHashBucket()
{
	HashBucket pHB;
	int ret = 0;

	InitHashBucket(&pHB);
	InsertHashBucket(&pHB, 64);
	InsertHashBucket(&pHB, 86);
	InsertHashBucket(&pHB, 24);
	InsertHashBucket(&pHB, 53);
	InsertHashBucket(&pHB, 82);
	InsertHashBucket(&pHB, 91);
	InsertHashBucket(&pHB, 14);
	PrintHashBucket(&pHB);
	DeleteHashBucket(&pHB, 64);
	DeleteHashBucket(&pHB, 91);
	printf("////////////////////////////////////\n");
	printf("ɾ������ 90 : ");
	DeleteHashBucket(&pHB, 90);
	//PrintHashBucket(&pHB);
	ret = FindHashBucket(&pHB, 90);
	if (ret >= 0)
		printf("�ҵ��ˣ������ݵ�Ͱ��Ϊ��%d\n", ret);
	else
		printf("û�ҵ��������ݲ������ڸù�ϣͰ����\n");

	DestoryHashBucket(&pHB);
	PrintHashBucket(&pHB);
}

int main()
{
	//test();//��ͨ��̬
	//testCapacity();
	testHashBucket();
	system("pause");
	return 0;
}