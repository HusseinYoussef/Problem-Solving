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
#define INF					2000000100
#define llINF				20000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int n, m, x, y;
char grid[1005][1005];
int dts[1005];
int dp[1005][1005][2];

int rec(int idx, int len, bool op)
{
	if (idx == m)
	{
		if (len >= x && len <= y) return 0;
		return INF;
	}

	int &ret = dp[idx][len][op];
	if (~ret) return ret;

	ret = INF;
	if (!idx || (op == 0 && len < y) || (op == 1 && len >= x))
		ret = rec(idx + 1, (op == 1) ? 1 : len + 1, 0) + (n - dts[idx]);
	if (!idx || (op == 1 && len < y) || (op == 0 && len >= x))
		ret = min(ret, rec(idx + 1, (op == 0) ? 1 : len + 1, 1) + dts[idx]);

	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	sc(n); sc(m); sc(x); sc(y);
	for (int i = 0; i<n; ++i) for (int j = 0; j<m; ++j) cin >> grid[i][j];
	mem(dp, -1);
	for (int i = 0; i<m; ++i)
	{
		int sum = 0;
		for (int j = 0; j<n; ++j)
			if (grid[j][i] == '.')
				++sum;
		dts[i] = sum;
	}

	int ans = rec(0, 0, 0);
	printf("%d", ans);

	return 0;
}