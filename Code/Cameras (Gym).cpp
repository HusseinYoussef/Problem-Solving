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

const int N = 1e5 + 10;
int n, k, ra;
int arr[N];
bool vis[N];
bool tmp[N];

bool valid(int c)
{
	int ans = 0;
	for (int i = 0; i < n; ++i) vis[i] = tmp[i];
	for (int i = 0; i < ra; ++i)
	{
		if (vis[i])
			++ans;
	}
	if (ans == 0)
	{
		vis[ra - 1] = vis[ra - 2] = 1, ans += 2, c -= 2;
	}
	else if (ans == 1)vis[ra - 1] = 1, ++ans, --c;

	for (int i = ra; i < n; ++i)
	{
		if (vis[i - ra])--ans;
		if (vis[i])++ans;

		if (ans < 2)
		{
			if (!vis[i])
				--c, vis[i] = 1,++ans;
		}
	}
	return c >= 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n); sc(k); sc(ra);
	
	int x;
	for (int i = 0; i < k; ++i)sc(x), tmp[x] = vis[x] = 1;

	int l = 0, r = n, mid;
	while (l < r)
	{
		mid = l + (r - l) / 2;
		if (valid(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d", l);
	return 0;
}