#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <stdio.h>
#include <map>
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
#define sc(x)               scanf("%d",&x)
#define scl(x)              scanf("%lld",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define EPS                 1e-9
#define pb					push_back
#define MP					make_pair
#define PI                  3.14159265
#define INF					1000000100			
#define llINF				10000000000100
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int inline max3(int a, int b, int c) { return max(a, max(b, c)); }

struct node
{
	ll mx;              // 4 requirements to build interval (L,R) from (L,M) & (M+1,R)
	ll maxleft;
	ll maxright;
	ll sum;
};

const int N = 5e4 + 10;
int arr[N]; node seg[4 * N];
int n, m;

node merge(node lft, node right)
{
	node ans;
	ans.sum = lft.sum + right.sum;
	ans.maxleft = max(lft.maxleft, lft.sum + right.maxleft);     // max left (prefix)
	ans.maxright = max(right.maxright, right.sum + lft.maxright);  // max right suffix
	ans.mx = max3(lft.mx, right.mx, lft.maxright + right.maxleft); // 3 cases : the max subarray exists in the left interval or the right one
	return ans;                                                   // or in both (mutual) some in left and some in right
}                                                                // we need the max of them all

void build(int id = 1, int l = 0, int r = n)
{
	if (r - l < 2)
	{
		seg[id].mx = seg[id].maxleft = seg[id].maxright = seg[id].sum = arr[l];
		return;
	}

	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);

	seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}

node getans(int x, int y, int id = 1, int l = 0, int r = n)
{
	if (l >= x && r <= y)
	{
		return seg[id];
	}

	int mid = (l + r) / 2;

	if (y <= mid) return getans(x, y, id * 2, l, mid);
	else if (x >= mid) return getans(x, y, id * 2 + 1, mid, r);
	else
	{
		node lft, right, ans;
		lft = getans(x, y, id * 2, l, mid);
		right = getans(x, y, id * 2 + 1, mid, r);
		return ans = merge(lft, right);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n);
	for (int i = 0; i < n; ++i)sc(arr[i]);
	sc(m);
	int x, y;
	build();
	while (m--)
	{
		sc(x); sc(y);
		node ans = getans(--x, y);
		printf("%lld\n", ans.mx);
	}
	return 0;
}