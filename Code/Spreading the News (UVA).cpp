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
#define INF					10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int E;
int M = 0, D = 0, T = 0;
vector<vector<int>>G(2800);
bool vis[2800];
queue<int>q;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	sc(E);
	lop(i, E)                      // Directed Graph
	{
		int num;
		sc(num);
		lop(j, num)
		{
			int friends;
			sc(friends);
			G[i].pb(friends);
		}
	}
	sc(T);
	while (T--)
	{
		int src, cnt = 0, lvl = 0, sz;
		M = D = 0;
		mem(vis, 0);
		sc(src);
		vis[src] = 1;
		q.push(src);
		while (!q.empty())
		{
			sz = sz(q);
			if (cnt > M)
			{M = cnt; D = lvl;}
			cnt = 0;
			while (sz--)
			{
				int node = q.front();
				q.pop();
				rep(i, G[node])
				{
					if (!vis[G[node][i]])
					{
						q.push(G[node][i]);
						vis[G[node][i]] = 1;
						++cnt;
					}
				}
			}
			++lvl;
		}
		printf("%d", M);
		if (M) printf(" %d\n", D);
		else printf("\n");
	}
	return 0;
}