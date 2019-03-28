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
int arr[10010];
int solve(int s)
{
	int maxi = 0;
	for (int i = 0; i < n; ++i)
	{
		s += arr[i];
		if (s < 0) s = 0;
		maxi = max(s, maxi);
	}
	return maxi;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	while (scanf("%d", &n), n)
	{
		for (int i = 0; i < n; ++i) sc(arr[i]);
		int ans = solve(0);

		(ans > 0) ? printf("The maximum winning streak is %d.\n", ans) : printf("Losing streak.\n");
	}

	return 0;
}