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
#define llINF				10000000000100
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
int n;
vector<vector<int>>G(10);
int dp[N][10];

int rec(int sum, int tp)
{
	if (sum < 0) return INF;
	if (sum == 0) return 0;

	int &ret = dp[sum][tp];
	if (~ret) return ret;

	ret = INF;

	for (int i = 0; i < 4; ++i)
	{
		ret = min(ret, rec(sum - G[tp][i], G[tp][i]) + 1);
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	int t;
	sc(t);
	G[1] = { 2,3,4,5 };
	G[2] = { 1,4,6,3 };
	G[3] = { 1,5,6,2 };
	G[4] = { 2,6,5,1 };
	G[5] = { 1,3,6,4 };
	G[6] = { 4,2,3,5 };
	while (t--)
	{
		sc(n);
		mem(dp, -1);

		int ans = rec(n, 1);
		if (ans == INF) puts("-1");
		else printf("%d\n", rec(n, 1));
	}
	return 0;
}