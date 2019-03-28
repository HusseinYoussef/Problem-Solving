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

int n, m;
pair<int, int>E[4005];
bool adjmt[4005][4005];
vector<vector<int>>G(4005);

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	sc(n); sc(m);
	for (int i = 0; i < m; ++i)
	{
		sc(E[i].first); sc(E[i].second);
		adjmt[E[i].first][E[i].second] = 1;
		adjmt[E[i].second][E[i].first] = 1;
		G[E[i].first].pb(E[i].second);
		G[E[i].second].pb(E[i].first);
	}
	uint ans = INF;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (j != E[i].first && j != E[i].second && adjmt[E[i].first][j] && adjmt[E[i].second][j])
				ans = min(ans, sz(G[E[i].first]) + sz(G[E[i].second]) + sz(G[j]) - 6);
		}
	}
	printf("%d", (ans != INF) ? ans : -1);
	return 0;
}