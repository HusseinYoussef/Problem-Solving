#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <stdio.h>
#include <map>
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
#define sc(x)               scanf("%d",&x)
#define scl(x)              scanf("%lld",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define EPS                 1e-9
#define pb					push_back
#define MP					make_pair
#define PI                  3.14159265
#define INF					1000000100			
#define llINF				10000000000100
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

const int N = 1e3 + 10;
pair<int, int>arr[N]; int p[N], sz[N]; bool vis[N];
pair<ll, ll>sum[N];
int n, m, W;
ll dp[N][N];
vector<vector<int>>G(N); vector<int>vec;

int find(int u)
{
	if (u == p[u]) return u;
	return p[u] = find(p[u]);
}

ll rec(int idx, int lft)      // similar to knapsack problem
{                                     // got 3 Choices ->>  leave the Group || take all the Group || take only one from the Group
	if (lft < 0) return -INF;
	if (idx == sz(vec) || lft == 0) return 0;

	ll &ret = dp[idx][lft];
	if (~ret) return ret;

	ret = max(rec(idx + 1, lft), rec(idx + 1, lft - sum[vec[idx]].first) + sum[vec[idx]].second);
	int r = vec[idx];
	for (int i = 0; i < sz(G[r]); ++i)
	{
		ret = max(ret, rec(idx + 1, lft - arr[G[r][i]].first) + arr[G[r][i]].second);
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

	sc(n); sc(m); sc(W);
	for (int i = 1; i <= n; ++i)sc(arr[i].first), p[i] = i, sz[i] = 1, sum[i].first = arr[i].first;
	for (int i = 1; i <= n; ++i)sc(arr[i].second) , sum[i].second = arr[i].second;
	mem(dp, -1);

	int x, y;
	while (m--)
	{
		sc(x); sc(y);

		int a = find(x), b = find(y);
		if (a != b)
		{
			if (sz[a] > sz[b]) swap(a, b);
			p[a] = b;
			sz[b] += sz[a];
			sum[b].first += sum[a].first;
			sum[b].second += sum[a].second;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		int root = find(i);
		if (!vis[root])
		{
			vis[root] = 1;
			vec.pb(root);
		}
		G[root].pb(i);
	}

	ll ans = rec(0, W);
	printf("%I64d", ans);
	return 0;
}