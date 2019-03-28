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
#define INF					2e9+10			
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

const int N = 260;
int n, s, e;
string str;
int arr[N][10];
bool vis[N];
vector<vector<int>>G(N);
int main()
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
		sc(n); sc(s); sc(e);

		for (int i = 1; i <= n; ++i)
		{
			cin >> str;
			for (int j = 0; j < sz(str); ++j)  ++arr[i][str[j] - '0'];
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = i+1; j <= n; ++j)
			{
					int sum = 0;
					for (int k = 0; k <= 9; ++k)
					{
						sum += min(arr[i][k], arr[j][k]);
					}
					if (sum == 17)
						G[i].pb(j), G[j].pb(i);
			}
		}


		queue<pair<int, int>>q;
		q.push({ s,0 });
		vis[s] = 1;
		int ans = -1;
		while (!q.empty())
		{
			int node = q.front().first;
			int cst = q.front().second;
			q.pop();

			if (node == e)
			{
				ans = cst;
				break;
			}
			for (int i = 0; i < sz(G[node]); ++i)
			{
				if (!vis[G[node][i]])
				{
					q.push({ G[node][i],cst + 1 });
					vis[G[node][i]] = 1;
				}
			}
		}
		printf("%d\n", ans);


		for (int i = 1; i <= n; ++i)	
			G[i].clear();

		mem(arr, 0);
		mem(vis, 0);

	}
	return 0;
}