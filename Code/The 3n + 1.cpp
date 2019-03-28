#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned int uint;

int i, j;   // Interval
int maxy = 0, sum = 0;

void cycle(int val, int sum)
{
	++sum;

	if (val == 1)
	{
		if (sum > maxy)
			maxy = sum;
		return;
	}
	else if (val % 2 == 0)
		val /= 2;
	else
		val = (3 * val) + 1;
	
	cycle(val, sum);
}
int main()
{
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
	while (cin >> i)
	{
		scanf(" %d", &j);
		maxy = 0;
		for (int k = min(i, j); k <= max(i, j); ++k)
		{
			cycle(k, 0);
			sum = 0;
		}
		printf("%d %d %d\n", i, j, maxy);
	}
	return 0;
}