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

const int  N = 1e5 + 10;
int arr[N], n, q;
vector<vector<int>>buck(N);

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	sc(n); sc(q);
	for (int i = 0; i < n; ++i)sc(arr[i]);
	int bs = sqrt(n);

	for (int i = 0; i < n; ++i)
		buck[i / bs].pb(arr[i]);
	
	for (int i = 0; i <= (n - 1) / bs; ++i)
		sort(all(buck[i]));

	char c; int l, r, x, idx;
	while (q--)
	{
		scanf("\n");
		scanf("%c", &c);
		if (c == 'M')
		{
			sc(idx); sc(x);
			--idx;

			int b = idx / bs;
			int old = arr[idx];

			int i = lower_bound(buck[b].begin(), buck[b].end(), old) - buck[b].begin();
			buck[b][i] = x;
			sort(all(buck[b]));

			arr[idx] = x;
		}
		else
		{
			sc(l); sc(r); sc(x);
			--l, --r;
			
			int ans = 0;
			for (int i = l; i <= r; ++i)
			{
				if (i % bs == 0 && i+bs-1 <= r)
				{
					int idx = upper_bound(buck[i / bs].begin(), buck[i / bs].end(), x) - buck[i / bs].begin();
					ans += idx;
					i += bs - 1;
				}
				else
				{
					ans += (arr[i] <= x);
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}