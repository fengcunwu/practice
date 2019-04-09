#include "Practice.hpp"

//ì³²¨ÄÇÆõ·ïÎ²
void test3()
{
	int n, i;
	int F[100001];
	F[0] = 1;
	F[1] = 1;
	FOR(i, 100000)
	{
		F[i + 1] = (F[i] + F[i - 1]) % 1000000;
	}
	while (std::cin >> n)
	{
		printf((n < 29 ? "%d\n" : "%06d\n"), F[n]);
	}
}