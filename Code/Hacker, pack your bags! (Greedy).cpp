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
typedef long double ld;
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
#define llINF				        5e18+10
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

const int N = 2e5 + 10;
int l[N], r[N], cst[N], x, n;
vector<vector<pair<int,int>>>G(N);
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n); sc(x);
	for (int i = 0; i < n; ++i)
		sc(l[i]), sc(r[i]), sc(cst[i]), G[r[i] - l[i] + 1].pb({ l[i],cst[i] });
	
	for (int i = 0; i < N; ++i)
	{
		if (!sz(G[i]))continue;
		sort(all(G[i]));
		int mn = INF;
		for (int j = sz(G[i]) - 1; j >= 0; --j)
		{
			mn = min(mn, G[i][j].second);
			G[i][j].second = mn;
		}
	}
	int ans = INF;
	for (int i = 0; i < n; ++i)
	{
		int dur = r[i] - l[i] + 1;
		if (dur >= x) continue;

		int y = x - dur;
		if (!sz(G[y]))continue;

		pair<int, int> p = { r[i],INF };
		int idx = upper_bound(G[y].begin(), G[y].end(), p)-G[y].begin();
		
		if (idx == sz(G[y]))continue;
		ans = min(ans, cst[i] + G[y][idx].second);
	}
	if (ans == INF) puts("-1");
	else cout << ans << endl;
	return 0;
}