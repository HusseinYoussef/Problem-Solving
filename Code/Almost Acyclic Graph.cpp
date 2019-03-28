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

const int N = 505;
int n, m;
VVI G(N);
vector<int>cycle;
int vis[N];
stack<int>st;
bool c;
int x, y;
void dfs(int node)     // find a cycle  then remove an edge from it (removing this cycle) then try to find another cycle
{
	vis[node] = GRAY;
	st.push(node);
	if (c) return;

	for (int i = 0; i < sz(G[node]) && !c; ++i)
	{
		if (node == x && y == G[node][i]) continue;
		if (vis[G[node][i]] == WHITE)
		{
			dfs(G[node][i]);
		}
		else if (vis[G[node][i]] == GRAY)
		{
			c = 1;
			if (sz(cycle))return;
			while (!st.empty())
			{
				int tp = st.top();
				cycle.pb(tp);
				st.pop();
				if (tp == G[node][i]) break;
			}
			return;
		}
	}
	if(sz(st) && st.top() == node)st.pop();
	vis[node] = BLACK;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	sc(n); sc(m);
	int f, t;
	while (m--)
	{
		sc(f); sc(t);
		G[f].pb(t);
	}

	for (int i = 1; i <= n && !sz(cycle); ++i)
	{
		if (vis[i] == WHITE)
		{
			dfs(i);
		}
	}
	if (!sz(cycle))return puts("YES");

	reverse(all(cycle));

	for (int i = 0; i < sz(cycle); ++i)
	{
		x = cycle[i], y = cycle[(i + 1)%sz(cycle)];
		
		c = 0;
		mem(vis, WHITE);
		for (int j = 1; j <= n && !c; ++j)
		{
			if (vis[j] == WHITE)
				dfs(j);
		}
		if (!c) return puts("YES");
	}

	puts("NO");
	return 0;
}