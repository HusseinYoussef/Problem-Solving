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

ll dp[15],mx;
string s,ans("");

void rec(int lft, string t)
{
	if (lft == 1)
	{
		sort(t.begin(), t.end());
		reverse(t.begin(), t.end());
		int tmp = atoi(t.c_str());
		if (tmp > mx)
			mx = max(1LL * tmp, mx), ans = t;
		return;
	}

	for (int i = 2; i <= 9; ++i)
	{
		if (lft % dp[i] == 0)
		{
			string tt = t;
			tt += i + '0';
			rec(lft / dp[i], tt);
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
	int m;
	sc(m);
	dp[0] = 1;
	for (int i = 1; i <= 9; ++i)dp[i] = i*dp[i - 1];
	cin >> s;
	int n = 1;
	
	string ss = "";
	for (int i = 0; i < sz(s); ++i)
	{
		ans = ""; mx = 0;
		n = dp[s[i] - '0'];
		rec(n, "");
		ss += ans;
	}
	sort(ss.begin(), ss.end());
	reverse(ss.begin(), ss.end());
	cout << ss;
	return 0;
}