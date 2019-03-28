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
#include <ctime>
#include <numeric>
#include <bitset>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
#define sc(x)               scanf("%d",&x)
#define scl(x)              scanf("%lld",&x)
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

int X;
int grid[12][1005];
int dp[12][1002];

int rec(int idx, int alt)
{
	if (idx == X)
	{
		if (alt == 0) return 0;
		return INF;
	}

	int &ret = dp[alt][idx];
	if (~ret) return ret;

	ret = INF;
	
	ret = rec(idx + 1, alt) + 30 - grid[alt][idx];
	if (alt > 0) ret = min(ret,rec(idx + 1, alt - 1) + 20 - grid[alt][idx]);
	if (alt < 9) ret = min(ret,rec(idx + 1, alt + 1) + 60 - grid[alt][idx]);
	
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int T;
	sc(T);
	while (T--)
	{
		sc(X);
		X /= 100;
		for (int i = 9; i >= 0; --i) for (int j = 0; j < X; ++j) sc(grid[i][j]);
		mem(dp, -1);

		int ans = rec(0, 0);
		printf("%d\n\n", ans);
	}
	return 0;
}