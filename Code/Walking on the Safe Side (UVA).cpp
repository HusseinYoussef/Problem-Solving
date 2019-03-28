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

int W, N;
bool grid[105][105];
int dp[106][106];

ll rec(int r, int c)
{
	if (r == W && c == N) return 1;
	if (r > W || c > N || grid[r][c]) return 0;

	int &ret = dp[r][c];
	if (~ret) return ret;

	return ret = rec(r + 1, c) + rec(r, c + 1);
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
		sc(W); sc(N);
		cin.ignore();
		mem(dp, -1);
		mem(grid, 0);
		for (int i = 1; i <= W; ++i)
		{
			string s;stringstream ss;
			int x,y, w;
			getline(cin, s);
			ss << s;
			ss >> x;
			while (ss >> y)grid[x][y] = 1;
		}
		ll ans = rec(1, 1);
		printf("%lld\n", ans);
		if(t) printf("\n");
	}

	return 0;
}