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
#define EPS                 1e-9
#define pb					push_back
#define MP					make_pair
#define PI                  3.14159265
#define INF					1000000100			
#define llINF				10000000000100
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

const int N = 505;
string grid[N];
int n, m, k;
int sp[N][N];

bool valid(int x, int y, int c)
{
	return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && sp[x][y] == INF);
}

int bfs()
{
	queue<pair<int, int>>q;
	q.push({ 0,0 });
	sp[0][0] = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int cst = sp[x][y];

		if (x == n - 1 && y == m - 1) break;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (valid(nx, ny, cst + 1))
			{
				q.push({ nx,ny });
				sp[nx][ny] = cst + 1;
			}
		}
	}
	return sp[n - 1][m - 1];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n); sc(m); sc(k);
	for (int i = 0; i < n; ++i)cin >> grid[i];

	for (int i = 0; i < n; ++i)for (int j = 0; j < m; ++j)sp[i][j] = INF;
	int ans1 = bfs();

	int x, y;
	for (int i = 0; i < k; ++i)
	{
		sc(x); sc(y);
		grid[x][y] = '.';
	}

	for (int i = 0; i < n; ++i)for (int j = 0; j < m; ++j)sp[i][j] = INF;
	int ans2 = bfs();

	(ans2 + 5 < ans1) ? puts("YES") : puts("NO");       // started 5 min after them
	return 0;
}