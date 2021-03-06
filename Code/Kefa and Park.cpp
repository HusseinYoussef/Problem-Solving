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
#define EPS                           1e-9
#define pb					push_back
#define MP					make_pair
#define INF					1000000100			
#define llINF				10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int n, m,ans;
bool cts[100005];
bool vis[100005];
vector<vector<int>>G(100005);

void DFS(int node, int cats)
{
	vis[node] = 1;
	if (cats > m) return;
	if (sz(G[node]) == 1 && node != 1)++ans;         //only leaf will have 1 child (it's parent-Undirected-) or the root(excluded)
	for (int i = 0; i < sz(G[node]); ++i)
	{
		if (!vis[G[node][i]])
		{
			DFS(G[node][i], (cts[G[node][i]] ? cats + 1 : 0));
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

	sc(n); sc(m);
	for (int i = 1; i <= n; ++i) { int tmp; sc(tmp); cts[i] = tmp; }
	for (int i = 0; i < n - 1; ++i)
	{
		int from, to;
		sc(from); sc(to);

		G[from].pb(to);
		G[to].pb(from);
	}
	DFS(1, cts[1]);
	printf("%d", ans);
	return 0;
}