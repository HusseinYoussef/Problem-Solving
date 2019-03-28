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

const int N = 1e5 + 10;
int n, m;
int par[N];
vector<vector<int>>G(N);
int find(int u)
{
	if (u == par[u])return u;
	return par[u] = find(par[u]);
}

void move(int u, int v)
{
	int a = find(u), b = find(v);
	if (a != b)
	{
		par[u] = b;
		G[b].pb(u);

		if (sz(G[u]))     // in case moving a representive node
		{
			int c = G[u][sz(G[u]) - 1];
			par[c] = c;
			for (int i = sz(G[u]) - 2; i >= 0; --i)
			{
				G[c].pb(G[u][i]);
				par[G[u][i]] = c;
			}
			G[u].clear();
		}
		else   // in case of moving a normal node (leaf)
		{
			if (sz(G[a]))
			{
				auto iter = G[a].begin();
				while (*iter != u) ++iter;
				G[a].erase(iter);
			}
		}
	}
}

void uniun(int x,int y)
{
	int a = find(x), b = find(y);
	if (a != b)
	{
		if (sz(G[a]) > sz(G[b]))swap(a, b);

		par[a] = b;
		G[b].pb(a);
		for (int i = 0; i < sz(G[a]); ++i)
		{
			G[b].pb(G[a][i]);
			par[G[a][i]] = b;
		}
		G[a].clear();
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; ++i)par[i] = i;
		
		int t, p, q;
		for (int i = 0; i < m; ++i)
		{
			sc(t); sc(p);
			if (t == 1)
			{
				sc(q);
				uniun(p, q);
			}
			else if (t == 2)
			{
				sc(q);
				move(p, q);
			}
			else
			{
				int a = find(p), sum = a;
				for (int j = 0; j < sz(G[a]); ++j)
					sum += G[a][j];
				printf("%d %d\n", sz(G[a])+1, sum);
			}
		}
		G.clear();
		G.resize(N);
	}
	return 0;
}