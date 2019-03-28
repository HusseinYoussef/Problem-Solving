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
#define sz(v)				((int)v.size())
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
ll inline max3(ll a, ll b, ll c) { return max(a, max(b, c)); }
ll inline min3(ll a, ll b, ll c) { return min(a, min(b, c)); }
ll power(ll x, ll p) { if (p == 0) return 1; else if (p % 2 == 0) return power(1LL * x*x, p / 2); else return 1LL * x*power(1LL * x*x, (p - 1) / 2); }
ll GCD(ll a, ll b) { if (b == 0) return a; return GCD(b, a%b); }

const int N = 1e2 + 5;
int n;
ll x[N], y[N], p[N];
ll Dis[N][N];
ll sp[N];

int main()     // Dijkstra  problem
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int t;
	sc(t);
	while (t--)
	{
		sc(n);
		for (int i = 1; i <= n; ++i)
		{
			scl(x[i]); scl(y[i]); scl(p[i]);
			sp[i] = llINF;
		}
		sp[n + 1] = llINF;
		scl(x[0]); scl(y[0]); scl(x[n + 1]); scl(y[n + 1]);

		for(int i=1;i<=n;++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (i != j)
				{
					Dis[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
					if (((x[i] - x[j]) * (x[i] - x[j])) + ((y[i] - y[j]) * (y[i] - y[j])) <= p[i] * p[i]) Dis[i][j] = min(Dis[i][j], 2LL);
				}
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			Dis[0][i] = abs(x[i] - x[0]) + abs(y[i] - y[0]);
			Dis[i][n + 1] = abs(x[i] - x[n + 1]) + abs(y[i] - y[n + 1]);
		}
		Dis[0][n + 1] = abs(x[n + 1] - x[0]) + abs(y[n + 1] - y[0]);

		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>pq;
		pq.push({ 0,0 }); sp[0] = 0;
		while (!pq.empty())
		{
			int node = pq.top().second;
			ll cst = pq.top().first;
			pq.pop();

			if (node == n + 1) break;
			for (int i = 1; i <= n + 1; ++i)
			{
				if (i != node && cst + Dis[node][i] < sp[i])
				{
					pq.push({ cst + Dis[node][i] ,i });
					sp[i] = cst + Dis[node][i];
				}
			}
		}
		
		printf("%lld\n", sp[n+1]);
	}
	return 0;
}