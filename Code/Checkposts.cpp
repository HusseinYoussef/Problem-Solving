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
typedef vector<vector<int> > VVI;
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
#define WHITE 0
#define GRAY 1
#define BLACK 2
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int inline max3(int a, int b, int c) { return max(a, max(b, c)); }

const int N = 1e5 + 10, mod = 1e9 + 7;
int n, m, mn, cnt;
int cost[N], col[N];
VVI G(N), GT(N);
stack<int>st;
void dfs(int node)
{
	col[node] = GRAY;
	for (int i = 0; i < sz(G[node]); ++i) 
	{
		if (col[G[node][i]] == WHITE)
			dfs(G[node][i]);
	}
	st.push(node);
	col[node] = BLACK;
}

void dfs2(int node)
{
	col[node] = GRAY;
	if (cost[node] < mn)
	{
		mn = cost[node];
		cnt = 1;
	}
	else if (cost[node] == mn) ++cnt;
	for (int i = 0; i < sz(GT[node]); ++i)
	{
		if (col[GT[node][i]] == WHITE)
		{
			dfs2(GT[node][i]);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int x, y;
	sc(n);
	for (int i = 1; i <= n; ++i)sc(cost[i]);        // SCC Problem 
	sc(m);
	while (m--)
	{
		sc(x); sc(y);
		G[x].pb(y), GT[y].pb(x);
	}
	for (int i = 1; i <= n; ++i) if (!col[i]) dfs(i);    
	mem(col, 0); ll sum = 0, ans = 1;
	while (!st.empty())                      // Find each SCC  
	{                                       // find the lowest cost node int each SCC  if there ara more than one lowest node
		int node = st.top();               // then there are multiple ways to to so
		mn = INF, cnt = 1;
		if (col[node] == 0)
			dfs2(node), sum += mn, ans = (1LL * ans*cnt) % mod;
		st.pop();
	}
	printf("%I64d %I64d", sum, ans);
	return 0;
}