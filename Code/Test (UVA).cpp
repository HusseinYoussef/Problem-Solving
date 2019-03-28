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

const int N = 30;
int n, idx;
VVI G(N), GT(N); int col[N];
bool tk[30];
stack<int>st;
vector<int>s;
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
	for (int i = 0; i < sz(GT[node]); ++i)
	{
		if (!col[GT[node][i]])
			dfs2(GT[node][i]);
	}
	s.pb(node);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c = 0;
	while (sc(n) && n)
	{
		if (c)printf("\n");
		vector<int>nodes;
		while (n--)
		{
			vector<char>vec; char c;
			for (int i = 0; i < 5; ++i)
			{
				cin >> c;
				vec.pb(c);
				if (!tk[c - 'A'])
					nodes.pb(c - 'A'), tk[c - 'A'] = 1;
			}
			cin >> c;
			for (int i = 0; i < sz(vec); ++i)
			{
				if (vec[i] != c)
				{
					G[c - 'A'].pb(vec[i] - 'A');
					GT[vec[i] - 'A'].pb(c - 'A');
				}
			}
		}
		for (int i = 0; i < sz(nodes); ++i) if (!col[nodes[i]])dfs(nodes[i]);
		mem(col, 0);
		VVI ans;
		while (!st.empty())               // SCC Problem
		{
			int node = st.top();
			if (!col[node])
			{
				dfs2(node), ans.pb(s), s.clear();
			}
			st.pop();

		}
		for (int i = 0; i < sz(ans); ++i) if (sz(ans[i]) > 1)sort(all(ans[i]));
		sort(ans.begin(), ans.end());
		for (int i = 0; i < sz(ans); ++i)
		{
			for (int j = 0; j < sz(ans[i]); ++j)
			{
				printf("%c", ans[i][j] + 'A');
				if (j != sz(ans[i]) - 1)printf(" ");
			}
			printf("\n");
		}
	
		mem(tk, 0); mem(col, 0);
		for (int i = 0; i < N; ++i)
		{
			if (sz(G[i]))G[i].clear();
			if (sz(GT[i]))GT[i].clear();
			
		}
		ans.clear();
		++c;
	}
	return 0;
}