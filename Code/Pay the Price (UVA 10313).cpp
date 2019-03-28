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

const int N = 302;
int arr[N];
ll dp[N][N][N];  // 1001 is useless as the max number of coins to use to get max number(300) is 300  1's

ll solve(int idx, int coins, int rem)
{
	if (coins == 0 || rem == 0) return rem == 0;
	if (idx == 300 || rem < 0) return 0;

	ll &ret = dp[idx][coins][rem];
	if (~ret) return ret;

	return ret = solve(idx + 1, coins, rem) + solve(idx, coins - 1, rem - arr[idx]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	string s,t;
	for (int i = 0; i < 300; ++i)arr[i] = i + 1;
	mem(dp, -1);
	while (getline(cin, s))
	{
		vector<int>vec;
		stringstream ss;
		ss << s;
		while (ss >> t) vec.pb(atoi(t.c_str()));

		ll ans = 0;
		int sum = vec[0];
		
		if (sz(vec) == 1)
		{
			ans = solve(0, 301, sum);
		}
		else if (sz(vec) == 2)
		{
			ans = solve(0, min(vec[1], 300), sum);
		}
		else  // dp[0][70][200]  is the number of ways to get 200 using 70 coins or less
		{
			if (vec[1]) ans = solve(0, min(vec[2],300), sum) - solve(0, min(vec[1]-1,300), sum);
			else ans = solve(0, vec[2], sum);
		}
		printf("%lld\n",ans);
	}

	return 0;
}