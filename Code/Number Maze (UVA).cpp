#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
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
#include <numeric>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
#define sc(x)           scanf("%d",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lop(i, n)		for(int i=0;i<n;++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define repa(v)				lpi(i, 0, sz(v)) lpi(j, 0, sz(v[i]))
#define pb					push_back
#define MP					make_pair
#define INF					1000000100			
#define llINF				10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int M;
int R, C;
int grid[1050][1050];
int sp[1050][1050];
priority_queue<pair<int, pair<int, int>>, vector< pair<int, pair<int, int> > >, greater< pair<int, pair<int, int>> > >pq; 
bool valid(int x, int y, int cost)
{
	return (x >= 0 && y >= 0 && x < R && y < C && cost + grid[x][y] < sp[x][y]);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	sc(M);
	while (M--)
	{
		memset(grid, 0, sizeof grid);
		sc(R); sc(C);
		lop(i, R)
			lop(j, C)
				sc(grid[i][j]);
		lop(i, 1050)
			lop(j, 1050)
			sp[i][j] = INF;

		pq.push(MP(grid[0][0], MP(0, 0)));
		sp[0][0] = grid[0][0];
		while (!pq.empty())
		{
			int cellx = pq.top().second.first;
			int celly = pq.top().second.second;
			int cost = pq.top().first;
			pq.pop();

			lop(i, 4)
			{
				int nx = cellx + dx[i], ny = celly + dy[i];
				if (valid(nx, ny, cost))
				{
					pq.push(MP(cost + grid[nx][ny], MP(nx,ny)));
					sp[nx][ny] = cost + grid[nx][ny];
				}
			}

		}
		printf("%d\n", sp[R - 1][C - 1]);
	}
	return 0;
}