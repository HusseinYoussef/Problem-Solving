#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef unsigned int uint;

int main()
{
	short n_contests;
	short best, worst, amazings = 0;

	scanf(" %hd%hd", &n_contests, &best);
	worst = best;

	for (int i = 0; i < n_contests - 1; ++i)
	{
		short temp;
		scanf(" %hd", &temp);

		if (temp > best)
		{
			best = temp;
			++amazings;
		}
		else if (temp < worst)
		{
			worst = temp;
			++amazings;
		}
	}
	printf("%hd", amazings);
	return 0;
}