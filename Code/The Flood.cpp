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
#define sc(x)              scanf("%d",&x)
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
int sx, sy;
char grid [1010][1010];
int sp[1010][1010];

bool valid(int x,int y,int cost)
{
	return (x >= 0 && x < n && y >= 0 && y < m && cost < sp[x][y] && grid[x][y] != '#');
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	vector<pair<int, int>>dots;
	sc(n); sc(m);
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { sp[i][j] = INF; cin >> grid[i][j]; if (grid[i][j] == '.')dots.pb({ i,j }); }
	sc(sx); sc(sy);

	--sx, --sy;
	int maxi = 0;
	queue<pair<int,int>>q;
	q.push(MP(sx, sy));
	sp[sx][sy] = 0;

	while (!q.empty())
	{
		int cellx = q.front().first;
		int celly = q.front().second;
		int cst = sp[cellx][celly];
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cellx + dx[i]; int ny = celly + dy[i];
			if (valid(nx, ny, cst + 1))
			{
				q.push(MP(nx, ny));
				sp[nx][ny] = cst + 1;
				maxi = max(sp[nx][ny], maxi);
			}
		}
	}
	for (int i = 0; i < sz(dots); ++i)
		if (sp[dots[i].first][dots[i].second] == INF) return puts("-1");
	printf("%d", maxi);
	return 0;
}