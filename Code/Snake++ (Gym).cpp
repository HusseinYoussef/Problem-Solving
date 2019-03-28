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
#include <unordered_map>
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
typedef vector<vector<int> > VVI;
#define sc(x)               scanf("%d",&x)
#define scl(x)              scanf("%lld",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define EPS                 1e-9
#define pb					push_back
#define MP					make_pair
#define PI                  3.14159265
#define INF					1000000100			
#define llINF				10000000000100
#define WHITE 0
#define GRAY 1
#define BLACK 2
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int inline max3(int a, int b, int c) { return max(a, max(b, c)); }

int n, m, k;
char grid[15][15];
bool vis[15][15];
bool ans;
bool valid(int x, int y)
{
	return (grid[x][y] != '#' && !vis[x][y]);
}

void dfs(int x, int y, int len, int o)  // Backtracking
{
	if (len >= k + o) { ans = 1; return; }
	vis[x][y] = 1;
	for (int i = 0,nx,ny; i < 4; ++i)
	{
		nx = x + dx[i], ny = y + dy[i];
		if (nx == -1) nx = n-1;
		else if (nx == n) nx = 0;
		if (ny == -1) ny = m - 1;
		else if (ny == m)ny = 0;

		if (valid(nx, ny))
		{
			dfs(nx, ny, len + 1, o + (grid[nx][ny] == 'o'));
		}
	}
	vis[x][y] = 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int t;
	sc(t);
	int x, y;
	int cnt = 1;
	while (t--)
	{
		sc(n); sc(m); sc(k);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> grid[i][j];
				if (grid[i][j] == 'x')
					x = i, y = j;
			}
		}
		ans = 0;
		dfs(x, y, 1, 0);
		
		if (ans)
			printf("Case #%d: Fits perfectly!\n", cnt++);
		else 
			printf("Case #%d: Oh no, snake's too fat!\n", cnt++);
	}
	return 0;
}