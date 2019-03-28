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

const int N = 1e5 + 10;
int n;
pair<int, int>arr[N];
int dp[N];
int rec(int idx, int lst)
{
	if (idx <= 0) return 0;

	int &ret = dp[idx];
	if (~ret) return ret;

	int l = 1, r = idx-1, mid;
	
	while (l < r)
	{
		mid = l + (r - l + 1) / 2;
		if (arr[mid].first < lst) l = mid;
		else r = mid - 1;
	}
	if (r > 0 && arr[r].first < lst) ret = rec(l, arr[r].first - arr[r].second) + idx - l - 1;
	else  ret = rec(r, arr[r].first - arr[r].second) + idx - 1;

	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n);
	for (int i = 1; i <= n; ++i)
	{
		sc(arr[i].first); sc(arr[i].second);
	}

	ll ans = llINF; mem(dp, -1);
	sort(arr+1, arr + n+1);
	for (int i = n; i > 0; --i)
	{
		ans = min(ans, (ll)rec(i, arr[i].first - arr[i].second) + n - i);
	}
	printf("%lld\n", ans);
	return 0;
}