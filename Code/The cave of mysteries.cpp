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
ll grid[1010][1010];
bool vis[1010][1010];
int R, C, X, Y;
ll mid;

bool valid(int x, int y)
{
	return x >= 0 && y >= 0 && y < m && x < n && grid[x][y] > mid;
}

void DFS(int x, int y)
{
	vis[x][y] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (valid(nx, ny) && !vis[nx][ny])
		{
			DFS(nx, ny);
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	sc(n); sc(m);
	sc(R); sc(C); sc(X); sc(Y);
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) scl(grid[i][j]);
	--R, --C, --X, --Y;

	ll l = 0, r = min(grid[R][C], grid[X][Y]) - 1;
	while (l < r)
	{
		mid = l + (r - l+1) / 2;
		DFS(R, C);
		if (vis[X][Y])
			l = mid;
		else
			r = mid - 1;
		mem(vis, 0);
	}
	printf("%lld", l);
	return 0;
}