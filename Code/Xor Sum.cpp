#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <numeric>
#include <iomanip>
#include <iterator>

using namespace std;

typedef long long LL;
typedef unsigned int uint;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, ans = 0;
//*********************************************************
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int num;
		scanf("%d", &num);
		ans ^= num;
	}
	printf("%d", ans);
	return 0;
}