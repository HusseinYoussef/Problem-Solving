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

const int N = 4e4 + 10;
vector<bool>primes(N,1);
vector<int>p;

void sieve()
{
	primes[0] = primes[1] = 0;
	for (int i = 2; i*i <= N; ++i)
	{
		if (primes[i])
		{
			for (int j = i*i; j < N; j += i)
				primes[j] = 0;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	string s, t;
	sieve();
	for (int i = 2; i < N; ++i)if (primes[i])p.pb(i);
	while (getline(cin, s) && s[0] != '0')
	{
		stringstream ss;
		ss << s;
		int sum = 1;
		while (ss >> t)
		{
			int x = atoi(t.c_str());
			ss >> t;
			sum *= power(x, atoi(t.c_str()));
		}
		--sum;
		vector<pair<int, int>>ans;
		for (int i = 0; i < sz(p) && 1ll * p[i] * p[i] <= sum; ++i)
		{
			int e = 0;
			while (sum%p[i] == 0)
			{
				++e;
				sum /= p[i];
			}
			if (e) ans.pb({ p[i],e });
		}
		if (sum > 1) ans.pb({ sum,1 });
		for (int i = sz(ans) - 1; i >= 0; --i)
		{
			printf("%d %d", ans[i].first, ans[i].second);
			if (i != 0) printf(" ");
		}
		printf("\n");
	}
	return 0;
}