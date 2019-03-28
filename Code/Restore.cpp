#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <numeric>
#include <iomanip>
#include <iterator>

using namespace std;

typedef long long ll;
typedef unsigned int uint;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	ll arr[102][102],sum = 0,temp = 0,all = 0;
//***********************************************************

	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		temp = 0;
		for (int j = 0; j < n; ++j)
		{
			scanf("%lld", &arr[i][j]);
			temp += arr[i][j];
		}
		all += temp;
		arr[i][n] = temp;
	}
	sum = all / (n - 1);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
				printf("%lld ", sum - arr[i][n]);
			
			else
				printf("%lld ", arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}