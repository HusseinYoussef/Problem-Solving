#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <list>
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
#define sz(v)				((int)v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define EPS                 1e-9
#define pb					push_back
#define MP					make_pair
#define PI                  3.14159265
#define INF					2e9+10			
#define llINF				40000000000100
#define WHITE 0
#define GRAY 1
#define BLACK 2
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
ll inline max3(ll a, ll b, ll c) { return max(a, max(b, c)); }
ll inline min3(ll a, ll b, ll c) { return min(a, min(b, c)); }
ll power(ll x, ll p) { if (p == 0) return 1; else if (p % 2 == 0) return power(1LL * x*x, p / 2); else return 1LL * x*power(1LL * x*x, (p - 1) / 2); }
ll GCD(ll a, ll b) { if (b == 0) return a; return GCD(b, a%b); }

string grid[52];
int vis[52][52];
int n, m;

bool ok(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 'B' && vis[x][y] != GRAY;
}

void dfs(int x, int y, int lst, int tu)
{
	if (tu > 2)return;
	vis[x][y] = GRAY;
	for (int i = 0,nx,ny; i < 4; ++i)
	{
		nx = x + dx[i], ny = y + dy[i];
		if (ok(nx, ny))
		{
			dfs(nx, ny, i, tu + (i != lst));
		}
	}
	vis[x][y] = BLACK;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n); sc(m);
	for (int i = 0; i < n; ++i) cin >> grid[i];
	int x, y;
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (grid[i][j] == 'B')
			{
				dfs(i, j, -1, 0); bool f = 0;
				for (int i = 0; i < n; ++i)for (int j = 0; j < m; ++j) if (grid[i][j] == 'B' && vis[i][j] != BLACK)return puts("NO");
				mem(vis, 0);
			}
		}
	}
	puts("YES");
	return 0;
}