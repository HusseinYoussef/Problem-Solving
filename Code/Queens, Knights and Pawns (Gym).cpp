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
#define INF					1000000100			
#define llINF				10000000000100
#define WHITE 0
#define GRAY 1
#define BLACK 2
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 1, 1, -1, -1, -2, 2, -2, 2 };
const int dy[] = { 2, -2, 2, -2, 1, 1, -1, -1 };
ll inline max3(ll a, ll b, ll c) { return max(a, max(b, c)); }
ll inline min3(ll a, ll b, ll c) { return min(a, min(b, c)); }
ll power(ll x, ll p) { if (p == 0) return 1; else if (p % 2 == 0) return power(1LL * x*x, p / 2); else return 1LL * x*power(1LL * x*x, (p - 1) / 2); }
ll GCD(ll a, ll b) { if (b == 0) return a; return GCD(b, a%b); }

const int N = 1e3 + 10;
int n, m, x;
int grid[N][N];
vector<pair<int, int>>queen,knight,pawn;

bool valid(int x, int y)
{
	return x > 0 && x <= n && y > 0 && y <= m;
}

int calck()
{
	int cnt = 0;
	for (int i = 0; i < sz(knight); ++i)
	{
		int x = knight[i].first, y = knight[i].second;
		for (int j= 0,nx,ny; j < 8; ++j)
		{
			nx = x + dx[j], ny = y + dy[j];
			if (valid(nx, ny) && grid[nx][ny] == 0)
			{
				++cnt;
				grid[nx][ny] = 1;
			}
		}
	}
	return cnt;
}

int calcq()
{
	int cnt = 0;
	for (int i = 0; i < sz(queen); ++i)
	{
		int x = queen[i].first, y = queen[i].second;

		for (int j = x-1; j > 0; --j) // up
		{
			if (!valid(j, y) || grid[j][y] == 2) break;
			else if (grid[j][y] == 0)
			{
				++cnt;
				grid[j][y] = 1;
			}
		}
		for (int j = x + 1; j <= n; ++j) // down
		{
			if (!valid(j, y) || grid[j][y] == 2) break;
			else if (grid[j][y] == 0)
			{
				++cnt;
				grid[j][y] = 1;
			}
		}

		for (int j = y + 1; y <= m; ++j) // right
		{ 
			if (!valid(x, j) || grid[x][j] == 2) break;
			else if (grid[x][j] == 0)
			{
				++cnt;
				grid[x][j] = 1;
			}
		}
		for (int j = y - 1; y > 0; --j)  // left
		{
			if (!valid(x, j) || grid[x][j] == 2) break;
			else if (grid[x][j] == 0)
			{
				++cnt;
				grid[x][j] = 1;
			}
		}

		for (int nx = x + 1, ny = y + 1; x <= n&&y <= m; ++nx, ++ny)
		{
			if (!valid(nx, ny) || grid[nx][ny] == 2) break;
			else if (grid[nx][ny] == 0)
			{
				++cnt;
				grid[nx][ny] = 1;
			}
		}
		for (int nx = x - 1, ny = y - 1; x > 0&&y > 0; --nx, --ny)
		{
			if (!valid(nx, ny) || grid[nx][ny] == 2) break;
			else if (grid[nx][ny] == 0)
			{
				++cnt;
				grid[nx][ny] = 1;
			}
		}
		for (int nx = x - 1, ny = y + 1; x > 0 && y <= m; --nx, ++ny)
		{
			if (!valid(nx, ny) || grid[nx][ny] == 2) break;
			else if (grid[nx][ny] == 0)
			{
				++cnt;
				grid[nx][ny] = 1;
			}
		}
		for (int nx = x + 1, ny = y - 1; x <= n && y > 0; ++nx, --ny)
		{
			if (!valid(nx, ny) || grid[nx][ny] == 2) break;
			else if (grid[nx][ny] == 0)
			{
				++cnt;
				grid[nx][ny] = 1;
			}
		}
	}
	return cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int bd = 0;
	while (scanf("%d%d", &n, &m) && n && m)
	{
		mem(grid, 0); int p = 0;
		int sum = n*m;
		sc(x);
		int r, c;
		for (int i = 0; i < x; ++i)
		{
			sc(r); sc(c);
			grid[r][c] = 2;
			queen.pb({ r,c });
		}
		sc(x);
		for (int i = 0; i < x; ++i)
		{
			sc(r); sc(c);
			grid[r][c] = 2;
			knight.pb({ r,c });
		}
		sc(x);
		for (int i = 0; i < x; ++i)
		{
			sc(r); sc(c);
			grid[r][c] = 2;
			++p;
		}

		int a = calck();
		int b = calcq();

		printf("Board %d has %d safe squares.\n",++bd, sum - a - b - p - sz(knight) - sz(queen));
		queen.clear();
		knight.clear();
	}
	return 0;
}