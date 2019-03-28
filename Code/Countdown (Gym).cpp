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

const int N = 1e3 + 10;
int n, m, d;
string arr[N],s;
map<string, int>mp;
VVI G(N);
int chil[N];

bool cmp(pair<int,string>&a,pair<int,string>&b)
{
	if (a.first == b.first) return a.second > b.second;
	else return a.first < b.first;
}

int dfs(int id,int dp)
{
	int cnt = 0;
	
	if (dp == d) return 1;
	else if (dp < d)
	{
		for (int i = 0; i < sz(G[id]); ++i)
		{
			cnt += dfs(G[id][i], dp + 1);
		}
	}
	return cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int t;
	int tr = 0;
	sc(t);
	while (t--)
	{
		sc(n); sc(d);
		int node = 1;
		while (n--)
		{
			cin >> s; sc(m);
			int par = 0;
			if (mp[s] == 0) par = mp[s] = node++;
			else par = mp[s];
			arr[par] = s;
			for (int i = 0; i < m; ++i)
			{
				cin >> s;
				int id = 0;
				if (mp[s] == 0) id = mp[s] = node++;
				else id = mp[s];
				arr[id] = s;

				G[par].pb(id);
			}
		}
		vector<pair<int, string>>v;
		for (int i = 1; i < node; ++i)
		{
			chil[i] = dfs(i, 0);
			v.pb({ chil[i],arr[i] });
		}
		sort(v.begin(), v.end(), cmp);
		int k = 0, lst = -1;
		printf("Tree %d:\n", ++tr);
		int cnt = 0;
		for (int i = sz(v) - 1; i >= 0; --i)
		{
			if (v[i].first == 0 || lst != v[i].first && cnt >= 3) break;
			cout << v[i].second << " " << v[i].first << "\n";
			++cnt;
			if (v[i].first != lst) lst = v[i].first;
		}
		printf("\n");

		mem(arr, 0);
		mem(chil, 0); mp.clear();
		for (int i = 1; i < node; ++i)G[i].clear();
	}
	return 0;
}