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
#define llINF				5e18+10
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
ll dp[N], k;
int n, q;
string f, a, b, c;

char solve(int i, ll pos)
{
	if (pos > dp[i]) return '.';
	if (i == 0)
	{
		if (pos < sz(f)) return f[pos];
		return '.';
	}
	if ((pos >= sz(a) && pos < sz(a) + dp[i - 1]))
	{
		return solve(i - 1, pos - sz(a));
	}
	else if (pos >= sz(a) + dp[i - 1] + sz(b) && pos < sz(a) + dp[i - 1] + sz(b) + dp[i - 1])
	{
		return solve(i - 1, pos - (sz(a) + dp[i - 1] + sz(b)));
	}
	else if (pos < sz(a)) return a[pos];
	else if (pos >= sz(a) + dp[i - 1] && pos < sz(a) + dp[i - 1] + sz(b))
	{
		return b[pos - (sz(a) + dp[i - 1])];
	}
	else if (pos >= sz(a) + dp[i - 1] + sz(b) + dp[i - 1] && pos < sz(a) + dp[i - 1] + sz(b) + dp[i - 1] + sz(c))
	{
		return c[pos - (sz(a) + dp[i - 1] + sz(b) + dp[i - 1])];
	}
	return '.';
}

void calc()
{
	f = "What are you doing at the end of the world? Are you busy? Will you save us?";
	a = "What are you doing while sending \"";
	b = "\"? Are you busy? Will you send \"";
	c = "\"?";

	dp[0] = sz(f);
	for (int i = 1; i <= 100000; ++i)
	{
		dp[i] = min(sz(a) + dp[i - 1] + sz(b) + dp[i - 1] + sz(c),(ll)4e18);  
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	calc();
	cin >> q;
	while (q--)
	{
		cin >> n >> k;
		--k;

		char ans = solve(n, k);
		cout << ans;
	}
	cout << endl;
	return 0;
}