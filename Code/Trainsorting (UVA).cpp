#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <functional>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <numeric>
#include <bitset>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
#define sc(x)              scanf("%d",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define EPS                           1e-9
#define pb					push_back
#define MP					make_pair
#define INF					1000000100			
#define llINF				10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int n;
int arr[2005];
int dpi[2005][2005];       // Dp array for the Increasing
int dpl[2005][2005];       // Dp array for the Decreasing

int LIS(int idx,int prev)
{
	if (idx == n) return 0;

	int &ret = dpi[idx][prev];
	if (~ret) return ret;

	int maxi = 0,ans = 0;
	for (int i = idx; i < n-maxi; ++i)
	{
		if (arr[i] > arr[prev])
		{
			ret = LIS(i + 1, i) + 1;
			ans = max(ans, ret);
		}
		maxi = max(ans, maxi);
	}
	
	return ret = maxi;
}

int LDS(int idx, int prev)
{
	if (idx == n) return 0;

	int &ret = dpl[idx][prev];
	if (~ret) return ret;

	int ans = 0, maxi = 0;
	for (int i = idx; i < n-maxi; ++i)
	{
		if (arr[i] < arr[prev])
		{
			ret = LDS(i + 1, i) + 1;
			ans = max(ans, ret);
		}
		maxi = max(ans, maxi);
	}

	return ret = ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	int t;
	sc(t);
	while (t--)
	{
		sc(n);
		for (int i = 0; i < n; ++i) sc(arr[i]);
		mem(dpi, -1);
		mem(dpl, -1);
		int size = 0;
		for (int i = 0; i < n-size; ++i)
		{
			size = max(LIS(i + 1, i) + 1 + LDS(i + 1, i), size);
		}
		
		printf("%d\n", (!n)? 0:size);
	}
	return 0;
}