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

int n, m;
string board[52];
bool vis[52][52];
int cnt;
bool cycle = false;

bool valid(int x, int y , char col)
{
	return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && board[x][y] == col);
}

void DFS(int x, int y, int px, int py)
{
	vis[x][y] = 1;
	++cnt;
	lop(i, 4)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (valid(nx, ny, board[x][y]))
			DFS(nx, ny, x, y);
		else
		{
			if(nx >= 0 && ny >=0 && ny < m && nx <n)
			if ((nx != px || ny != py ) && vis[nx][ny] && cnt >= 4 && board[x][y] == board[nx][ny])
			{cycle = true; return;}
		}
	}
}

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	sc(n); sc(m);
	lop(i, n)
	cin >> board[i];
	
	lop(i, n)
	{	
		lop(j, m)
		{	
			if (!vis[i][j] && !cycle)
			{
				cnt = 0;
				DFS(i, j, i, j);
			}
			if (cycle)
			{
				printf("Yes"); return 0;
			}
		}
	}
	printf("No");
	return 0;
}