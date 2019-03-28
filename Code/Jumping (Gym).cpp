#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <stdio.h>
#include <map>
#include <unordered_map>
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

const int N = 1e5 + 10;
int n;
int sp[N];
VVI G(N);

int main()
{
	freopen("jumping.in", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int t, d;
	sc(t);
	while (t--)
	{
		sc(n);
		for (int i = 1; i <= n; ++i)   // multiple sources to a single destination
		{                             // reverse the edges to make it a single source to multiple destinations (bfs)
			sc(d);
			if (i + d <= n)
				G[i + d].pb(i);
			if (i - d >= 1)
				G[i - d].pb(i);
		}
		for (int i = 1; i <= n; ++i)sp[i] = INF;
		queue<int>q;
		q.push(n);
		sp[n] = 0;
		while (!q.empty())
		{
			int node = q.front();
			int cst = sp[node];
			q.pop();
			for (int i = 0; i<sz(G[node]); ++i)
			{
				if (cst + 1 < sp[G[node][i]])
				{
					q.push(G[node][i]);
					sp[G[node][i]] = cst + 1;
				}
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			if (sp[i] == INF) puts("-1");
			else printf("%d\n", sp[i]);
		}
		for (int i = 1; i <= n; ++i)if (sz(G[i]))G[i].clear();
	}

	return 0;
}
