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

int n, m;
string arr[55];
int dp[55][55][55][55];      // Also possible to make bool dp[55][2][2][2]
							 // Cuz i want to know if he chose char/dig/sym or not   How many of each isn't needed

int solve(int idx, int dig, int sym, int cha)
{
	if (idx == n)
	{
		if (!(dig&&sym&&cha)) return INF;
		return 0;
	}

	int &ret = dp[idx][dig][sym][cha];
	if (~ret) return ret;

	ret = INF;
	for (int i = 0; i < m; ++i)
	{
		if (arr[idx][i] == '#' || arr[idx][i] == '&' || arr[idx][i] == '*')
			ret = min(ret, solve(idx + 1, dig, sym + 1, cha) + min(i, m - i));
		else if (arr[idx][i] >= 'a' && arr[idx][i] <= 'z')
			ret = min(ret, solve(idx + 1, dig, sym, cha + 1) + min(i, m - i));
		else
			ret = min(ret, solve(idx + 1, dig + 1, sym, cha) + min(i, m - i));
	}
	return ret;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	sc(n); sc(m);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	mem(dp, -1);

	int ans = solve(0, 0, 0, 0);
	printf("%d", ans);

	return 0;
}