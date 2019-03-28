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
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int inline max3(int a, int b, int c) { return max(a, max(b, c)); }
ll power(ll x, ll p) { if (p == 0) return 1; else if (p % 2 == 0) return power(1LL * x*x, p / 2); else return 1LL * x*power(1LL * x*x, (p - 1) / 2); }
ll GCD(ll a, ll b) { if (b == 0) return a; return GCD(b, a%b); }

const int N = 55;
int n, m;
pair<int, int> r[N], c[N];
bool grid[N][N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n); sc(m);
	for (int i = 0; i < n; ++i)for (int j = 0; j < m; ++j) sc(grid[i][j]);

	for (int i = 0; i < n; ++i)
	{
		int sum1 = 0, sum2 = 0;
		for (int j = 0; j < m; ++j)
		{
			if (grid[i][j] == 0)++sum1;
			else ++sum2;
		}
		r[i] = { sum1,sum2 };
	}
	for (int j = 0; j < m; ++j)
	{
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < n; ++i)
		{
			if (grid[i][j] == 0)++sum1;
			else ++sum2;
		}
		c[j] = { sum1,sum2 };
	}
	ll ans = n*m;
	for (int i = 0; i < n; ++i) { if (r[i].first > 1)ans += power(2, r[i].first) - 1 - r[i].first; if (r[i].second > 1)ans += power(2, r[i].second) - 1- r[i].second; }
	for (int i = 0; i < m; ++i) { if (c[i].first > 1)ans += power(2, c[i].first) - 1- c[i].first; if (c[i].second > 1) ans += power(2, c[i].second) - 1- c[i].second; }
	printf("%lld", ans);
	return 0;
}