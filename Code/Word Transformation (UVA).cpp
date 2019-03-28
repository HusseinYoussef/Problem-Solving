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
#define llINF				40000000000100
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

const int N = 250;
map<string, int>mp;
VVI G(N);
int sp[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	int t, n = 0;
	cin >> t; 
	cin.ignore();
	while (t--)
	{
		string s, sr, ds;
		int id = 0;
		vector<string>vec;
		if (n != 0) cout << endl;
	    ++n;
		while (cin >> s && s != "*")
		{
			if (!mp.count(s)) mp[s] = id++;
			vec.pb(s);
		}
		for (int i = 0; i < sz(vec); ++i)
		{
			for (int j = i + 1; j < sz(vec); ++j)
			{
				int cnt = 0;
				if (sz(vec[i]) == sz(vec[j]))
				{
					for (int k = 0; k < sz(vec[i]); ++k)
					{
						if (vec[i][k] != vec[j][k])++cnt;
					}
					if (cnt == 1)
						G[mp[vec[i]]].pb(mp[vec[j]]), G[mp[vec[j]]].pb(mp[vec[i]]);
				}
			}
		}
		cin.ignore();
		while (getline(cin,sr) && sr != "")
		{
			stringstream ss;
			ss << sr;
			ss >> sr;
			ss >> ds;
			for (int i = 0; i < N; ++i)sp[i] = -1;
			queue<int>q;
			q.push(mp[sr]);
			sp[mp[sr]] = 0;
			while (!q.empty())
			{
				int node = q.front();
				int cst = sp[node];
				q.pop();
				for (int i = 0; i < sz(G[node]); ++i)
				{
					if (sp[G[node][i]] == -1)
						q.push(G[node][i]), sp[G[node][i]] = cst + 1;
				}
			}
			cout << sr << " " << ds << " " << sp[mp[ds]] << endl;
		}
		for (int i = 0; i < N; ++i)if (sz(G[i]))G[i].clear();
		mp.clear();
	}
	return 0;
}