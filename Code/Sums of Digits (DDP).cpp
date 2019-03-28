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

const int N = 350;    // Important 
int n, arr[N];
string l(N, '0');
int dp[N][N][2];

int solve(int idx ,int sum , bool LST) // Digit DP
{
	if (sum < 0) return 0;
	if (idx == N) return (sum == 0) && LST;
	
	if (~dp[idx][sum][LST]) return dp[idx][sum][LST];

	dp[idx][sum][LST] = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (!LST)
			if (i < (l[idx] - '0')) continue;
		dp[idx][sum][LST] |= solve(idx + 1, sum - i, LST || (i > (l[idx] - '0')));
	}
	return dp[idx][sum][LST];
}

string path(int idx, int sum, bool LST)  // recover el path
{
	if (idx == N) return "";

	for (int i = 0; i < 10; ++i)
	{
		if (!LST && (i < (l[idx] - '0')))continue;
		if (solve(idx + 1, sum - i, LST || (i > (l[idx] - '0'))))  // take least number will gurantee minimum number
		{
			string tmp = "";
			tmp += char(i + '0') + path(idx + 1, sum - i, LST || (i > (l[idx] - '0')));
			return tmp;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	sc(n);
	for (int i = 0; i < n; ++i)sc(arr[i]);
	for (int i = 0; i < n; ++i)
	{
		mem(dp, -1);
		solve(0, arr[i], 0);
		string ans = path(0, arr[i], 0);
		l = ans;
		bool f = 0;
		for (int i = 0; i < sz(ans); ++i)
		{
			if (ans[i] != '0') f = 1;
			if (f) cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}