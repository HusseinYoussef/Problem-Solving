#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef unsigned int uint;

int main()
{
	int n, sum = 0, cnt = 0;
//*****************************************
	cin >> n;

	if (n % 2 == 0)
	{
		cnt = n / 2;
		printf("%d\n", cnt);
		for (int i = 1; i <= n / 2; ++i)
		{
			printf("2 ");
		}
	}
	else
	{
		while (sum < n - 3)
		{
			sum += 2;
			++cnt;
		}
		printf("%d \n",cnt+1);
		for (int i = 0; i < cnt; ++i)
		{
			printf("2 ");
		}
		printf("3");
	}
	return 0;
}