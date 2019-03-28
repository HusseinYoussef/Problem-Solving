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
	ll mx, open, closed;
};

const int N = 1e6 + 10;
node seg[4 * N];int  q;
string arr;

void build(int id = 1, int l = 0, int r = sz(arr))
{
	if (r - l < 2)
	{
		seg[id].mx = 0;
		(arr[l] == '(') ? ++seg[id].open : ++seg[id].closed;
		return;
	}

	int mid = (r + l) / 2;

	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
    // can get the answer of interval (L,R) from (L,M) & (M+1,R) -> left sum + right sum + min('(' of left,')'of right)
	seg[id].mx = seg[id * 2].mx + seg[id * 2 + 1].mx + min(seg[id * 2].open, seg[id * 2 + 1].closed);
	seg[id].open = seg[id * 2].open + seg[id * 2 + 1].open - min(seg[id * 2].open, seg[id * 2 + 1].closed);
	seg[id].closed = seg[id * 2].closed + seg[id * 2 + 1].closed - min(seg[id * 2].open, seg[id * 2 + 1].closed);
}

node getans(int x, int y, int id = 1, int l = 0, int r = sz(arr))
{
	if (l >= x && r <= y)
	{
		return seg[id];
	}

	int mid = (l + r) / 2;

	if (y <= mid) getans(x, y, id * 2, l, mid);
	else if (x >= mid) getans(x, y, id * 2 + 1, mid, r);
	else
	{
		node lft, right, ans;
		lft = getans(x, y, id * 2, l, mid);
		right = getans(x, y, id * 2 + 1, mid, r);
		ans.mx = lft.mx + right.mx + min(lft.open, right.closed);
		ans.closed = lft.closed + right.closed - min(lft.open, right.closed);
		ans.open = lft.open + right.open - min(lft.open, right.closed);
		return ans;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin >> arr;
	sc(q);
	build();
	int x, y;
	while (q--)
	{
		sc(x); sc(y);
		node ans = getans(--x, y);
		printf("%lld\n", ans.mx*2);
	}
	return 0;
}