#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
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
#include <numeric>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
#define sc(x)           scanf("%d",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lop(i, n)		for(int i=0;i<n;++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define repa(v)				lpi(i, 0, sz(v)) lpi(j, 0, sz(v[i]))
#define pb					push_back
#define MP					make_pair
#define INF					10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int n, m;
vector<vector<pair<ll, int>>>G(100010);
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>pq;
//bool vis[100010];
vector<ll>sp(100010, INF);
vector<int>par(100010,-1);

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	sc(n); sc(m);
	lop(i, m)
	{
		int from, to, cost;
		sc(from); sc(to); sc(cost);
		if (from != to)
		{
			G[from].pb(MP(cost, to));
			G[to].pb(MP(cost, from));
		}
	}

	pq.push(MP(0, 1));
	sp[1] = 0;

	while (!pq.empty())
	{
		int node = pq.top().second;
		ll cost = pq.top().first;
		pq.pop();
		//if (vis[node]) continue;            // el Vis m3mol asln 3shan el Multiple Edges asln
		//vis[node] = 1;                      // el Node ely gbtlha el SP 5las n3mlha pop 3shan lw ro7nalha tany nla2eha vis
		rep(i, G[node])
		{
			if (cost + G[node][i].first < sp[G[node][i].second])
			{
				pq.push(MP(cost + G[node][i].first,G[node][i].second));
				sp[G[node][i].second] = cost + G[node][i].first;
				par[G[node][i].second] = node;
			}
		}
	}
	vector<int>path;
	while (n != -1)
	{
		path.pb(n);
		n = par[n];
	}
	if (sz(path) == 1) printf("-1");
	else 
	{
		reverse(all(path));
		rep(i, path)
			printf("%d ", path[i]);
	}
	return 0;
}