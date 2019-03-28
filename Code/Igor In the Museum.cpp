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

int n, m, k, color,cnt;
char grid[1005][1005];
int ans[1000006];
int vis[1005][1005];

int DFS(int x, int y)
{
	vis[x][y] = color;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (!vis[nx][ny])
		{
			if (grid[nx][ny] == '.') DFS(nx, ny);
			else ++cnt;
		}
	}
	return cnt;
}

int main()              
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	sc(n); sc(m); sc(k);

	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j)cin >> grid[i][j];

	color = 1;
	while (k--)           
	{
		int x, y;
		sc(x); sc(y);
		cnt = 0;

		if (vis[x][y]) printf("%d\n", ans[vis[x][y]]);
		else  printf("%d\n", ans[color] = DFS(x, y));      //if not visited color the cell and its relatives with DFS with some color
		++color;                                           // and save the answer of that color  so if we found (x,y) visited cell
	}                                                      // it will have a color and we have the answer for that color 
	return 0;
}