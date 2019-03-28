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
#define INF					2100000100			
#define llINF				10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int n, m, k;
int trees[105];
int col[105][105];
ll dp[105][105][105];

ll solve(int idx, int beauty, int lst)           //Watch out (OverFlow)
{
	if (beauty > k) return llINF;
	if (idx > n)
	{
		if (beauty < k) return llINF;
		return 0;
	}

	ll &ret = dp[idx][beauty][lst];
	if (~ret) return ret;

	ret = llINF;
	if (!trees[idx])
		for (int i = 1; i <= m; ++i)
			ret = min(ret, solve(idx + 1, (i == lst) ? beauty : beauty + 1, i) + col[idx][i]);
	else
		ret = min(ret, solve(idx + 1, (trees[idx] == lst) ? beauty : beauty + 1, trees[idx]));
	
	return ret;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	sc(n); sc(m); sc(k);
	for (int i = 1; i <= n; ++i) sc(trees[i]);
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) sc(col[i][j]);
	mem(dp, -1);

	ll ans = solve(1, 0, 0);

	printf("%lld", (ans >= llINF) ? -1 : ans);
	return 0;
}