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

const int N = 1e6 + 10;
int ans[N];
int freq[N];
int arr[N],n,BS;
int res;

struct query
{
	int idx, l, r;

	query(int x,int y,int z)
	{
		l = x, r = y, idx = z;
	}

	bool operator < (const query & q) const
	{
		if (l / BS == q.l / BS)
			return r < q.r;
		return l / BS < q.l / BS;
	}
};

void add(int x)
{
	if (++freq[x] == 1) ++res;

}

void rem(int x)
{
	if (--freq[x] == 0) --res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int q;
	sc(n);
	BS = max(1,(int)sqrt(n));
	for (int i = 0; i < n; ++i)sc(arr[i]);
	sc(q);

	int l, r;
	vector<query>vec;
	for (int i = 0; i < q; ++i)
	{
		sc(l); sc(r);
		--l, --r;
		vec.pb(query(l, r, i));
	}
	sort(all(vec));

	int L = 0, R = -1;
	for (int i = 0; i < q; ++i)
	{
		int l = vec[i].l, r = vec[i].r;

		while (L > l) add(arr[--L]);
		while (R < r) add(arr[++R]);
		while (L < l) rem(arr[L++]);
		while (R > r) rem(arr[R--]);
		ans[vec[i].idx] = res;
	
	}
	for (int i = 0; i < q; ++i)
		printf("%d\n", ans[i]);

	return 0;
}