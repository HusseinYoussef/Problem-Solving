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
int inline max3(int a, int b, int c) { return max(a, max(b, c)); }

const int N = 1e5 + 10;
int n, m;
bool vis[N]; int col[N];
vector<vector<int>>G(N);
stack<int>topo;

void dfs1(int node)
{
	col[node] = 1;  // Gray

	for (int i = 0; i < sz(G[node]); ++i)
	{
		if (!col[G[node][i]])
			dfs1(G[node][i]);
	}
	topo.push(node);
	col[node] = 2; // Black
}

void dfs2(int node)
{
	vis[node] = 1;

	for (int i = 0; i < sz(G[node]); ++i)
	{
		if (!vis[G[node][i]])
			dfs2(G[node][i]);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int t, x, y;
	sc(t);
	while (t--)
	{
		sc(n); sc(m);
		while (m--)                 //P.S  Graph may not be DAG  so use DFS instead of queue here (better)
		{
			sc(x); sc(y);
			G[x].pb(y);
		}
		for (int i = 1; i <= n; ++i)        // minimum number of DFS to visit all nodes  = topological sort + DFS  
		{	                               //  (Not topo sort just a way to order the nodes in decreasing finishing time order using DFS & stack)
			if (col[i] == 0)  // White
				dfs1(i);
		}
		int cnt = 0; 
		while (!topo.empty())
		{
			int node = topo.top();
			if (!vis[node])
				dfs2(node), ++cnt;
			topo.pop();
		}
		printf("%d\n", cnt);
		mem(vis, 0); mem(col, 0);
		for (int i = 1; i <= n; ++i)G[i].clear();
	}
	return 0;
}