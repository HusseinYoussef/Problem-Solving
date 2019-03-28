#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
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

int M, N, X, Y;
char grid[25][25];
bool vis[25][25];
int cnt = 0;
char land;

bool valid(int x,int y)
{
	return (x >= 0 && x < M && grid[x][y] == land && !vis[x][y]);
}

void DFS(int x, int y)
{
	vis[x][y] = 1;
	++cnt;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (ny == N) ny = 0;
		else if (ny == -1)ny = N - 1;
		if (valid(nx, ny))
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
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	while (scanf("%d%d", &M, &N) == 2)
	{
		for (int i = 0; i < M; ++i) for (int j = 0; j < N; ++j) cin >> grid[i][j];
		sc(X); sc(Y);
		land = grid[X][Y];
		DFS(X, Y);

		int maxi = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cnt = 0;
				if (valid(i, j))
				{
					DFS(i, j);
					maxi = max(maxi, cnt);
				}
			}
		}
		printf("%d\n", maxi);
		mem(vis, 0);
	}
	return 0;
}