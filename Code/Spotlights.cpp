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

const int N = 1e3 + 10;
int n, m;
bool grid[N][N];
bool dir[N][N][4];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int ans = 0;
	sc(n); sc(m);
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)sc(grid[i][j]);

	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j) dir[i][j][3] |= grid[i][j] | dir[i][j - 1][3];
	for (int i = 1; i <= n; ++i)for (int j = m; j >= 1; --j) dir[i][j][1] |= grid[i][j] | dir[i][j + 1][1];
	for (int j = 1; j <= m; ++j)for (int i = 1; i <= n; ++i) dir[i][j][2] |= grid[i][j] | dir[i - 1][j][2];
	for (int j = 1; j <= m; ++j)for (int i = n; i >= 1; --i) dir[i][j][0] |= grid[i][j] | dir[i + 1][j][0];
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) if (!grid[i][j])for (int k = 0; k < 4; ++k) ans += dir[i][j][k];
	printf("%d\n", ans);
	return 0;
}