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

const int N = 1e5 + 10;
int n,mx;
string l, r, s;
ll dp[12][12][2][2][2][2];

// k represents  number of Consecutive  9's     --- LST1,RST1 constraints for number a || LST2 ,RST2 constriants for number b
// https://codeforcessolutions.com/codeforces-round-452-problem-d/
ll solve(int idx, int k, bool LST1, bool RST1 , bool LST2 , bool RST2)
{
	if (idx == sz(r)) return k == mx;

	ll &ret = dp[idx][k][LST1][RST1][LST2][RST2];
	if (~ret) return ret;

	ret = 0;
	for (int i = 0; i <= 9; ++i)  // first number a
	{
		if (!LST1)
			if (i < l[idx] - '0') continue;
		if (!RST1)
			if (i > r[idx] - '0') continue;
		for (int j = 0; j <= 9; ++j) // second number b
		{
			if (!LST2)
				if (j < l[idx] - '0')continue;
			if (!RST2)
				if (j > r[idx] - '0')continue;

			bool f = (i + j == 9);
			ret += solve(idx + 1, f ? k + 1 : 0, LST1 || i > (l[idx] - '0'), RST1 || i < r[idx] - '0', LST2 || j >(l[idx] - '0'), RST2 || j < (r[idx] - '0'));
		}
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

	sc(n);
	if (n < 5) cout << 1ll * n * (n - 1) / 2 << endl;
	else
	{
		int x = n + n - 1;               // 1 <= a, b <= n
		int nine = 1, m = 10;
		stringstream ss,rr;
		ss << x;
		ss >> s;
		string n9(sz(s), '9');
		mx = (s < n9) ? sz(s) - 1 : sz(s);  // max number of 9's the sum would have
		mem(dp, -1);
		rr << n;
		rr >> r;
		for (int i = 0; i < sz(r); ++i) l += '0';
		l[sz(r) - 1] = '1';

		int ans = solve(0, 0, 0, 0, 0, 0) / 2;
		cout << ans << endl;
	}

	return 0;
}