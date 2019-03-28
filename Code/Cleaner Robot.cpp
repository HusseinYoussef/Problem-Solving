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
const int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
const int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };

int w, h, sx, sy, dir, ans;
char grid[15][15];
int vis[15][15];

bool valid(int x, int y)
{
	return (x > 0 && x <= w && y > 0 && y <= h);
}

void DFS(int x, int y)
{
	if (!vis[x][y])
		++ans;
	vis[x][y] = 1;
	for (int i = dir,j = 0;j<4;++j)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (valid(nx, ny))
		{
			if (grid[nx][ny] != '*')
			{
				dir = i;
				DFS(nx, ny);
				break;
			}
			else if (grid[nx][ny] == '*')           //Cycle -> hit the same (*) in the same direction before
			{
				if (i + (-5) == vis[nx][ny])return;
				vis[nx][ny] = i + (-5);
			}
		}
		else                                        //Cycle -> hit the same (invalid cell) in the same direction before
		{
			if (i + (-5) == vis[nx][ny])return;
			vis[nx][ny] = i + (-5);
		}
		++i;
		i %= 4;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(w); sc(h);
	for (int i = 1; i <= w; ++i)for (int j = 1; j <= h; ++j)
	{
		cin >> grid[i][j];
		if (grid[i][j] == 'U' || grid[i][j] == 'L' || grid[i][j] == 'R' || grid[i][j] == 'D')
			sx = i, sy = j;
	}
	if (grid[sx][sy] == 'U') dir = 0;
	else if (grid[sx][sy] == 'R') dir = 1;
	else if (grid[sx][sy] == 'D') dir = 2;
	else if (grid[sx][sy] == 'L') dir = 3;

	DFS(sx, sy);
	printf("%d", ans);
	return 0;
}