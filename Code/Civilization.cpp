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

const int N = 3e5 + 50;
int n, m, q;
int p[N], diam[N], siz[N]; bool vis[N];
vector<vector<int>>G(N);
int mv, md;

void dfs(int node, int dp, int par)
{
	if (dp > md)
	{
		md = dp;
		mv = node;
	}
	for (int i = 0; i < sz(G[node]); ++i)
	{
		if (par != G[node][i])
		{
			dfs(G[node][i], dp + 1, node);
		}
	}
}

int find(int u)
{
	if (u == p[u]) return u;
	return p[u] = find(p[u]);
}

int calcdiam(int u)
{
	md = -1;
	dfs(u, 0, 0);
	md = -1;
	dfs(mv, 0, 0);
	return md;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n); sc(m); sc(q);
	for (int i = 1; i <= n; ++i)p[i] = i, siz[i] = 1;
	int x, y;
	for (int i = 0; i < m; ++i)
	{
		sc(x); sc(y);

		G[x].pb(y);
		G[y].pb(x);

		int a = find(x), b = find(y);
		if (siz[b] < siz[a])swap(a, b);
		p[a] = b;
		siz[b] += siz[a];
	}

	for (int i = 1; i <= n; ++i)
	{
		int c = find(i);
		if (!vis[c])
		{
			vis[c] = 1;
			diam[c] = calcdiam(i);     // diam array will store the diam of the component that c its representitivve
		}
	}

	int t;
	while (q--)
	{
		sc(t);
		if (t == 2)
		{
			sc(x); sc(y);
			int a = find(x), b = find(y);
			if (a != b)
			{
				if (siz[b] < siz[a])swap(a, b);
				p[a] = b;  
				siz[b] += siz[a];    // equation to get the minimum longest path 
				diam[b] = max(diam[a], max(diam[b], ((diam[a] + 1) / 2) + ((diam[b] + 1) / 2) + 1));
			}
		}
		else
		{
			sc(x);
			printf("%d\n", diam[find(x)]);
		}
	}
	return 0;
}