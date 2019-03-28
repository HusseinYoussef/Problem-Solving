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

int n, k;
string grid[2];
int water[100100];
bool vis[2][100100];
queue<pair<int,pair<int, int>>>q;
bool out = false;

bool valid(int x, int y, int cost)
{
	return (x >= 0 && x < 2 && y >= 0 && cost + 1 < water[y] && grid[x][y] != 'X');
}

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	sc(n); sc(k);
	lop(i, 2)
		cin >> grid[i];
	lop(i, n)
		water[i] = i + 1;
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,k,k };
	q.push(MP(0,MP(0, 0)));
	vis[0][0] = 1;
	while (!q.empty())
	{
		int cellx = q.front().second.first;
		int celly = q.front().second.second;
		int cost = q.front().first;
		q.pop();
		if (celly >= n - 1 || celly + k >= n)
		{out = true; break;}
		lop(i, 4)
		{
			int nx = cellx + dx[i], ny = celly + dy[i];
			if (valid(nx, ny, cost) && (!vis[nx][ny]))
			{
				q.push(MP(cost + 1 ,MP(nx, ny)));
				vis[nx][ny] = 1;
			}
		}
	}
	printf("%s", (out)?"YES":"NO");
	return 0;
}