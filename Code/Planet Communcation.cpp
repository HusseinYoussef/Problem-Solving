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
#define llINF				        5e18+10
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

int n;
struct slope
{
	ll a, b, c;

	slope(ll & x, ll &y, ll &z)
	{
		a = x, b = y, c = z;
	}

	bool operator < (const slope & s)const
	{
		if (a != s.a)
			return a < s.a;
		if (b != s.b)
			return b < s.b;
		return c < s.c;
	}
};
map<slope, bool>mp;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n);
	int x0, x1, y0, y1, z0, z1;
	sc(x0); sc(y0); sc(z0);
	int ans = 0;
	while (--n)
	{
		sc(x1); sc(y1); sc(z1);
		ll a = y0 - y1, b = x0 - x1, c = z0 - z1;
		ll gcd = GCD(GCD(a, b), c);
		a /= gcd, b /= gcd, c /= gcd;

		if (!mp.count(slope(a, b, c)))
		{
			++ans;
			mp[slope(a, b, c)] = 1;
		}

	}
	cout << ans;
	return 0;
}