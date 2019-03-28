#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
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
#define sc(x)              scanf("%d",&x)
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

vector<vector<int>>G(100010);
vector<int>cand;
bool vis[100010], rdp[100010];

int DFS(int node)
{
	vis[node] = 1;
	int c = 0;
	for (int i = 0; i < sz(G[node]); ++i)
		if (!vis[G[node][i]])
			c += DFS(G[node][i]);

	if (rdp[node] && !c)
	{
		++c;
		cand.pb(node);
	}
	return c;
}

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	sc(n);
	for (int i = 1; i < n; ++i)
	{
		int from, to, road;
		sc(from); sc(to); sc(road);

		G[from].pb(to);
		G[to].pb(from);

		if (road == 2)
			rdp[to] = rdp[from] = 1;
	}
	int ans = DFS(1);
	printf("%d\n", ans);
	for (int i = 0; i < sz(cand); ++i) printf("%d ", cand[i]);
	cout << clock() << "\n";
	return 0;
}