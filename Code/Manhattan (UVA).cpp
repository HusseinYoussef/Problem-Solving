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

const int N = 65;
int s, a, m;
VVI G(2 * N), GT(2 * N);
int col[2 * N], comp[2 * N];;
stack<int>st;
int id; bool tk[2 * N];

int NOT(int x)
{
	return x < N ? x + N : x - N;
}

void reset()
{
	for (int i = 0; i < 2 * N; ++i)
	{
		if (sz(G[i])) G[i].clear();
		if (sz(GT[i]))GT[i].clear();
	}
	mem(col, 0); mem(comp, 0); mem(tk, 0);
}

void dfs(int node)
{
	col[node] = GRAY;
	for (int i = 0; i < sz(G[node]); ++i)
	{
		if (!col[G[node][i]])
			dfs(G[node][i]);
	}
	st.push(node);
	col[node] = BLACK;
}

void dfs2(int node)
{
	col[node] = GRAY;

	for (int i = 0; i < sz(GT[node]); ++i)
	{
		if (!col[GT[node][i]])
			dfs2(GT[node][i]);
	}
	comp[node] = id;
}
                          //*** 2-SAT problem ***
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int t;
	int x1, y1, x2, y2;                 //  v > true 
	sc(t);
	while (t--)
	{
		sc(s); sc(a); sc(m);
		vector<int>nodes;
		while (m--)
		{
			sc(x1); sc(y1); sc(x2); sc(y2);
			--x1, --y1, --x2, --y2;

			y1 += s, y2 += s;
			if (!tk[x1])nodes.pb(x1), tk[x1] = 1; if (!tk[x2]) nodes.pb(x2), tk[x2] = 1; if (!tk[y1]) nodes.pb(y1), tk[y1] = 1; if (!tk[y2]) nodes.pb(y2), tk[y2] = 1;
			//if (!tk[NOT(x1)])nodes.pb(NOT(x1)), tk[NOT(x1)] = 1; if (!tk[NOT(x2)]) nodes.pb(NOT(x2)), tk[NOT(x2)] = 1; if (!tk[NOT(y1)]) nodes.pb(NOT(y1)), tk[NOT(y1)] = 1; if (!tk[NOT(y2)]) nodes.pb(NOT(y2)), tk[NOT(y2)] = 1;

			if (x2 < x1) y1 = NOT(y1), y2 = NOT(y2);
			if (y2 < y1) x1 = NOT(x1), x2 = NOT(x2);

			if (x1 == x2) { G[NOT(x1)].pb(x1); GT[x1].pb(NOT(x1)); continue; }   // X or X  so X must be true -> so  NOT(X) --> X 
			if (y1 == y2) { G[NOT(y1)].pb(y1); GT[y1].pb(NOT(y1)); continue; }   // Y or Y  so Y must be true -> so  NOT(Y) --> Y
			                                                                     // so they are forced to br True
			G[NOT(x1)].pb(x2), GT[x2].pb(NOT(x1));
			G[NOT(x2)].pb(x1), GT[x1].pb(NOT(x2));

			G[NOT(y2)].pb(x2), GT[x2].pb(NOT(y2));
			G[NOT(x2)].pb(y2), GT[y2].pb(NOT(x2));

			G[NOT(x1)].pb(y1), GT[y1].pb(NOT(x1));
			G[NOT(y1)].pb(x1), GT[x1].pb(NOT(y1));

			G[NOT(y2)].pb(y1), GT[y1].pb(NOT(y2));
			G[NOT(y1)].pb(y2), GT[y2].pb(NOT(y1));
		}

		for (int i = 0; i < sz(nodes); ++i)
		{
			if (col[nodes[i]] == WHITE)
				dfs(nodes[i]);
			if (col[NOT(nodes[i])] == WHITE)
				dfs(NOT(nodes[i]));
		}
		mem(col, 0);
		while (!st.empty())
		{
			int node = st.top();
			if (!col[node])
				++id, dfs2(node);
			st.pop();
		}
		bool f = 1;
		for (int i = 0; i < sz(nodes); ++i)
		{
			if (comp[nodes[i]] == comp[NOT(nodes[i])])
			{
				f = 0; break;
			}
		}
		(f) ? puts("Yes") : puts("No");
		reset();
	}
	return 0;
}