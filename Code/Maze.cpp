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

int n, m, k, dots = 0;
char grid[502][502];
bool vis[502][502];
int cnt;
void DFS(int, int);
bool valid(int x, int y)
{
	return (grid[x][y] == '.' && !vis[x][y] && x >= 0 && y >= 0 && x < n && y < m);
}

void DFS(int x, int y)
{
	if (cnt == dots - k)return;
	vis[x][y] = 1;
	++cnt;
	lop(i, 4)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (valid(nx, ny))
			DFS(nx, ny);
	}
}

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	scanf("%d%d%d", &n, &m, &k);
	lop(i, n)
	{
		lop(j, m)
		{
			cin >> grid[i][j];
			if (grid[i][j] == '.')
				++dots;
		}
	}
	lop(i, n)
	{
		lop(j, m)
			if (grid[i][j] == '.')
			{DFS(i, j); break;}
	}
	lop(i, n)
	{	
		lop(j,m)
		{
			if (grid[i][j] == '.' && !vis[i][j])
				grid[i][j] = 'X';
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}
	return 0;
}

