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
#define INF					1000000100			
#define llINF					10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int cases;
int n, m, S, T;
vector<vector<pair<ll, int>>>G(20100);
priority_queue < pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>pq;
ll sp[20100];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	sc(cases); int cnt = 0;
	while (cnt < cases)
	{
		scanf("%d%d%d%d", &n, &m, &S, &T);
		++cnt;
		lop(i, m)
		{
			int from, to, cost;
			sc(from); sc(to); sc(cost);
			G[from].pb(MP(cost, to));
			G[to].pb(MP(cost, from));
		}
		lop(i, 20100)
			sp[i] = llINF;
		pq.push(MP(0, S));
		sp[S] = 0;

		while (!pq.empty())
		{
			int node = pq.top().second;
			ll cost = pq.top().first;
			pq.pop();

			rep(i, G[node])
			{
				if (cost + G[node][i].first < sp[G[node][i].second])
				{
					pq.push(MP(cost + G[node][i].first, G[node][i].second));
					sp[G[node][i].second] = cost + G[node][i].first;
				}
			}
		}
		if(sp[T] == llINF) printf("Case #%d: unreachable\n",cnt);
		else printf("Case #%d: %lld\n", cnt,sp[T]);
		G.clear();
		G.resize(20100);
	}
	return 0;
}