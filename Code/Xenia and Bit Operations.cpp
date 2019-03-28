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

const int N = (1 << 17) + 10;
int n, m;
int arr[N], seg[4 * N];

bool Build(int id = 1, int l = 0,int r = 1<<n)
{
	if (r - l < 2)
	{
		seg[id] = arr[l];
		return 1;
	}

	int mid = (r + l) / 2;

	int f = Build(id * 2, l, mid);
	f = Build(id * 2 + 1, mid, r);

	if (f == 1) seg[id] = seg[id * 2] | seg[id * 2 + 1];
	else seg[id] = seg[id * 2] ^ seg[id * 2 + 1];

	return !f;
}

bool update(int idx, int val, int id = 1, int l = 0, int r = 1 << n)
{
	if (r - l < 2)
	{
		seg[id] = val;
		return 1;
	}

	int mid = (r + l) / 2;
	
	int f;
	if (idx < mid) f=update(idx,val,id * 2, l, mid);
	else f = update(idx,val,id * 2 + 1, mid, r);

	if (f == 1) seg[id] = seg[id * 2] | seg[id * 2 + 1];
	else seg[id] = seg[id * 2] ^ seg[id * 2 + 1];
	return !f;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n); sc(m);
	for (int i = 0; i < 1 << n; ++i)sc(arr[i]);
	int p, q;
	Build();
	while (m--)
	{
		sc(p); sc(q);
		--p;
		update(p, q);
		printf("%d\n", seg[1]);
	}
	return 0;
}