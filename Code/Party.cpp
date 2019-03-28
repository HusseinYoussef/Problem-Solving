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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	vector<vector<int>>G(2005);

	sc(n);
	for (int i = 1; i <= n; ++i)
	{
		int nm;
		sc(nm);
		if (nm == -1) G[0].pb(i);
		else G[nm].pb(i);
	}
	queue<int>q;
	int ch = 1;
	int s = 0;
	int lvl = -1;
	q.push(0);
	while (!q.empty())
	{
		while (ch--)
		{
			int node = q.front();
			q.pop();
			s += sz(G[node]);
			for (int i = 0; i < sz(G[node]); ++i)
				q.push(G[node][i]);
		}
		++lvl;
		ch = s;
		s = 0;
	}
	printf("%d", lvl);
	return 0;
}