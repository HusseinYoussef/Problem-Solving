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

const int N = 1e3 + 5 , mod = 1e9+7;
string r,l; int k; bool vis[N];
int dp[N][N][2];

int popcnt(int num)
{
	int cnt = 0;
	while (num)
	{
		cnt += num&1;
		num >>=1;
	}
	return cnt;
}

bool calc(int num)
{
	int ans = 0;
	while (num != 1)
	{
		num = popcnt(num);
		++ans;
	}
	return ans == k-1;
}

void precalc()
{
	mem(dp, -1);
	for (int i = 1; i <= 1000; ++i)
		if (calc(i)) vis[i] = 1;
}

int solve(int idx, int rem , bool RST)  // state idx , number of 1's put so far , r status
{
	if (idx == sz(r)) return vis[rem];

	int &ret = dp[idx][rem][RST];
	if (~ret) return ret;

	ret = 0;
	for (int i = 0; i < 2; ++i)
	{
		if (!RST && i > (r[idx] - '0')) continue;
		ret = ((ret % mod) + (solve(idx + 1, rem + i, RST || i < (r[idx] - '0')) % mod)) % mod;
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

	cin >> r >> k;
	if (k == 0) return puts("1");
	else if (k == 1) return cout << sz(r)-1, 0;
	precalc();
	int ans = solve(0, 0, 0);
	cout << ans << endl;
	return 0;
}