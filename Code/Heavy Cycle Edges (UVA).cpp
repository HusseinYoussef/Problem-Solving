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

const int N = 1e3 + 10;
int p[N];
vector<pair<int, pair<int, int>>>G;
int n, m;

int find(int u)
{
	if (u == p[u]) return u;
	return p[u] = find(p[u]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int u, v, w;
	while (scanf("%d%d", &n, &m) && (n || m))
	{
		for (int i = 0; i < n; ++i)p[i] = i;
		for (int i = 0; i < m; ++i)
		{
			sc(u); sc(v); sc(w);
			G.pb({ w,{u,v} });
		}
		sort(G.begin(), G.end());
		vector<int>ed;
		
		for (int i = 0; i < sz(G); ++i)
		{
			int a = find(G[i].second.first), b = find(G[i].second.second);

			if (a != b)
			{
				p[a] = b;
				continue;
			}
			ed.pb(G[i].first);
		}
		if (sz(ed))
		{
			for (int i = 0; i < sz(ed); ++i)
			{
				printf("%d", ed[i]);
				if (i != sz(ed) - 1) printf(" ");
			}
		}
		else
			printf("forest");
		printf("\n");
		G.clear();
	}
	return 0;
}