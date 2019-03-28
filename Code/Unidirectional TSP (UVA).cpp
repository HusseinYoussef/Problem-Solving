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
#define INF					2001000100			
#define llINF				20000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int m, n;
int grid[12][105];
int dp[12][105];
vector<int>path;

int rec(int row, int column)
{
	if (column > n) return 0;

	int &ret = dp[row][column];
	if (~ret) return ret;

	ret = INF;
	return ret = min(rec(row, column + 1), min(rec((row == 1) ? m : row - 1, column + 1), rec((row == m) ? 1 : row + 1, column + 1))) + grid[row][column];
}

void getpath(int row, int col, int cst)
{
	if (col > n) return;

	for (int i = 1; i <= m; ++i)
	{
		if (dp[i][col] == cst && (i == row || i == row + 1 || i == row - 1 || (i == m && row == 1) || (i == 1 && row == m)))
		{
			path.pb(i);
			getpath(i, col + 1, cst - grid[i][col]);
			break;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	while (scanf("%d%d", &m, &n) != EOF)
	{
		for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) sc(grid[i][j]);
		mem(dp, -1);
		path.clear();

		int ans = INF;
		for (int i = 1; i <= m; ++i)
			ans = min(ans, rec(i, 1));

		for (int i = 1; i <= m; ++i)
		{
			if (dp[i][1] == ans)
			{
				path.pb(i);
				getpath(i, 2, ans - grid[i][1]);
				break;
			}
		}
		
		for (int i = 0; i < sz(path); ++i)
		{			
			printf("%d", path[i]); 
			if (i < sz(path) - 1) printf(" ");
		}
		printf("\n%d\n", ans);
	}


	return 0;
}