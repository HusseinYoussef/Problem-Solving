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
typedef long double ld;
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

const int N = 2e3 + 2,mod = 1e9+7;
int m, d;
string l, r;
int dp[N][N][2][2];

int solve(int idx, int rem, int LST, int RST)  // 1 free , 0 not free
{
	if (idx == sz(l)) return rem == 0;

	int &ret = dp[idx][rem][LST][RST];
	if (~ret) return ret;

	if (idx&1)
	{
		if (!LST)
			if (d < (l[idx]-'0')) return 0;
		if (!RST)
			if (d > (r[idx]-'0')) return 0;
		return ret = solve(idx + 1, (rem * 10 + d) % m, LST || (d > (l[idx]-'0')), RST || (d < (r[idx]-'0'))) % mod;
	}
	ret = 0;
	for(int i=0;i<10;++i)
	{
		if (i == d) continue;
		if (!LST)
			if (i < (l[idx]-'0'))continue;
		if (!RST)
			if (i > (r[idx]-'0'))continue;
		ret = ((ret % mod) + (solve(idx + 1, (rem * 10 + i) % m, LST || (i > (l[idx] - '0')), RST || (i < (r[idx] - '0'))) % mod)) % mod;
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin >> m >> d >> l >> r;
	mem(dp, -1);
	int ans = solve(0, 0, 0, 0);  // 0 LST & 0 RST as conditions atrn't free at first
	cout << ans;
	return 0;
}