//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//char *my_strcpy(char *dest, const char * str)//字符串拷贝
//{
//	char *ret = dest;
//	assert(dest);
//	assert(str);
//	while (*dest++ = *str++)
//	{
//		;
//	}
//	return ret;
//}
//char *my_strcat(char *dest, const char * str)//字符串拼接
//{
//	char * ret = dest;
//	assert(dest);
//	assert(str);
//	while (*dest)
//	{
//		dest++;
//	}
//	while (*dest++ = *str++)
//	{
//		;
//	}
//	return ret;
//}
//char * my_strstr(const char *str1, const char *str2)//字符串寻找字串
//{
//	assert(str1);
//	assert(str2);
//
//	char *cp = (char *)str1;//原来的字符串
//	char *substr = (char *)str2;//需要查找的字符串
//	char *s1 = NULL;
//
//	if (*substr == '\0')
//		return NULL;
//
//	while (*cp)
//	{
//		s1 = cp;
//		substr = str2;
//		while (*s1 && *substr && (*s1 == *substr))
//		{
//			s1++;
//			substr++;
//		}
//		if (*substr == '\0')
//			return cp;
//		cp++;
//	}
//}
//void * my_memcpy(void * dest, const void * str, size_t count)
//{
//	void * ret = dest;
//
//	assert(dest);
//	assert(dest);
//
//	while(count)
//	{
//		*(char *)dest = *(char *)str;
//		/*++(char *)dest;
//		++(char *)str;*/
//		dest = (char *)dest + 1;
//		str = (char *)str + 1;
//		count--;
//	}
//	return ret;
//}
//void * my_memmove(void * dest, const void * str, size_t count)
//{
//	void * ret = dest;
//
//	assert(dest);
//	assert(str);
//
//	if (dest < str)
//	{
//		//前->后
//		while (count)
//		{
//			*(char *)dest = *(char *)str;
//			dest = (char *)dest + 1;
//			str = (char *)str + 1;
//			count--;
//		}
//	}
//	else
//	{
//		//后->前
//		while (count--)
//		{
//			*((char *)dest + count) = *((char *)str + count);
//		}
//	}
//	return ret;
//}
//int my_strcmp(const char * str1, const char * str2)
//{
//	assert(str1);
//	assert(str2);
//
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;
//}
//int my_strcmp(const char * str1, const char * str2)
//{
//	int ret = 0;
//
//	while (!(ret = *(unsigned char *)str1 - *(unsigned char *)str2)
//		&& *str1)
//	{
//		++str1;
//		++str2;
//	}
//	if (ret < 0)
//		return -1;
//	else if (ret > 0)
//		return 1;
//
//	return ret;
//}
//char * my_strchr(char * str, char set)
//{
//	assert(str);
//
//	while (*str != '\0' && *str != set)
//	{
//		str++;
//	}
//	return *str == set ? str : NULL;
//}
//int main()
//{
	/*char buf1[10] = {0};
	char buf2[10] = "abcdefg";*/
	/*char *ret = my_strcpy(buf1, buf2);*/
	/*char buf1[10] = "hello ";
	char buf2[10] = "world !";*/
	/*char *ret = my_strcat(buf1, buf2);*/
	/*char buf1[10] = "abbbcdef";
	char buf2[10] = "bbc";
	char* ret = my_strstr(buf1, buf2);*/
	/*printf("%s\n", ret);*/
	/*char arr1[10] = {'0'};
	char arr2[] = "12345678";
	void * ret = my_memcpy(arr1, arr2, 8);
	printf("%s ", ret);*/
	/*int i = 0;
	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
		printf("%c ", arr1[i]);
	}*/
	/*int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    my_memmove(arr + 2, arr + 5, 16);
	int i = 0;
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}*/
	/*char * p = "hello !";
	char * q = "hello !";
	int ret = my_strcmp(p, q);
	if (ret == 0)
		printf("相同 !\n");
	else
		printf("不相同 !!!\n");*/
	/*char *p = "hello world !!!";
	char *ret = my_strchr(p, 'o');
	printf("%s\n", ret);
	system("pause");
	return 0;
}*/
#include <stdio.h>
#include <string.h>
#include <assert.h>
	int my_strncmp(const char* dest, const char* src, size_t sz)
	{
		assert(dest);
		assert(src);

		while ((*dest == *src) && sz)
		{
			if (*dest == '\0')
				return 0;
			dest++;
			src++;
			sz--;
		}
		return *dest - *src;
	}

	int main()
	{
		char* str = "wf";
		int i = 0;
		printf("looking for wfc astromech droids...\n");
		if (my_strncmp(str, "wfc", strlen("wfc")) == 0)
		{
			printf("Found  %s\n", str);
		}
		else
		{
			printf("Not Found\n");
		}
		system("pause");
		return 0;
	}