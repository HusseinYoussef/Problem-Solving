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

const int N = 1e5 + 10;
int n;
VVI G(N); vector<int>ans;
int init[N], goal[N];
bool vis[N];
void dfs(int node, int eo, int oo, bool lvl)
{
	vis[node] = 1;
	bool nw = init[node],f = 0;
	if (lvl & 1)                      // nodes in levels with same parity will affect each other
	{                                 // get the current val after the operations done the ancestors
		if (oo & 1) nw = !nw;
	}
	else
	{
		if (eo & 1) nw = !nw;
	}

	if (nw != goal[node]) f = 1, ans.pb(node);;

	for (int i = 0; i < sz(G[node]); ++i)
	{
		if (!vis[G[node][i]])
		{
			if (lvl & 1) dfs(G[node][i], eo, oo + f, !lvl);
			else dfs(G[node][i], eo + f, oo, !lvl);
		}
	}
}

int main()                // first fix ancestors (if needed) then fix the node in their subtrees
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n);
	int u, v;
	for (int i = 0; i < n - 1; ++i)
	{
		sc(u); sc(v);
		G[v].pb(u);
		G[u].pb(v);
	}
	for (int i = 1; i <= n; ++i)sc(init[i]);
	for (int i = 1; i <= n; ++i)sc(goal[i]);
	dfs(1, 0, 0, 0);
	printf("%d\n", sz(ans));
	for (int i : ans)printf("%d\n",i);
	return 0;
}