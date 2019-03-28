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
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lop(i, n)		for(int i=0;i<n;++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define repa(v)				lpi(i, 0, sz(v)) lpi(j, 0, sz(v[i]))
#define pb					push_back
#define MP					make_pair
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int R, C;
int grid[1100][1100];
priority_queue<pair<int , pair<int,int>> , vector< pair<int , pair<int, int> > > , greater< pair<int  , pair<int, int>> > >que;
int sp[1100][1100];
bool valid(int x, int y,int cost)
{
	return (x >= 0 && y >= 0 && x < R && y < C && cost + 1 < sp[x][y] && grid[x][y] != -1);
}

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	int startx, starty;
	int stopx, stopy;
	while (true)
	{
		memset(grid, 0, sizeof grid);
		sc(R); sc(C);
		if (!R)break;
		int rowBo;
		sc(rowBo);
		lop(i, rowBo)
		{
			int r, num;
			sc(r); sc(num);
			lop(j, num)
			{
				int c;
				sc(c);
				grid[r][c] = -1;   // Bombs
			}
		}
		sc(startx); sc(starty);
		sc(stopx); sc(stopy);

		lop(i, 1100)
		lop(j, 1100) 
		sp[i][j] = 100000000;

		que.push(MP(0 , MP(startx, starty)));
		sp[startx][starty] = 0;

		while (!que.empty())
		{
			int cellx = que.top().second.first;
			int celly = que.top().second.second;
			int cost = que.top().first;
			que.pop();
			lop(i, 4)
			{
				int nx = cellx + dx[i], ny = celly + dy[i];
				if (valid(nx, ny, cost))
				{
					que.push(MP(cost +1 , MP(nx, ny)));
					sp[nx][ny] = cost + 1;
				}
			}
		}
		printf("%d\n", sp[stopx][stopy]);
	}
	return 0;
}