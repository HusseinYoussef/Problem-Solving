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

const int N = 1e5 + 10;

int n, m;
ll seg[4 * N], lazy[4 * N];

void propagate(int father, int leftson, int rightson,int l,int r)
{
	int mid = (l + r) / 2;

	seg[leftson] += (mid-l)*1LL*lazy[father];
	seg[rightson] += (r-mid)*1LL*lazy[father];
	
	lazy[leftson] += lazy[father];
	lazy[rightson] += lazy[father];
	
	lazy[father] = 0;
}

void update(int x, int y, int val, int id = 1, int l = 0, int r = n)
{
	if (l >= y || r <= x) return;

	if (l >= x && r <= y)
	{
		seg[id] += (r - l) * 1LL * val;
		lazy[id] += val;
		return;
	}

	if (lazy[id])
	{
		propagate(id, id * 2, id * 2 + 1, l, r);
	}
	int mid = (l + r) / 2;
	update(x, y, val, id * 2, l, mid);
	update(x, y, val, id * 2 + 1, mid, r);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

ll get_sum(int x, int y, int id = 1, int l = 0, int r = n)
{
	if (l >= y || r <= x) return 0;

	if (l >= x && r <= y)
	{
		return seg[id];
	}

	if (lazy[id])
	{
		propagate(id, id * 2, id * 2 + 1, l, r);
	}

	int mid = (l + r) / 2;
    return 	get_sum(x, y,id * 2, l, mid) + get_sum(x, y, id * 2 + 1, mid, r);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int t;
	sc(t);
	while (t--)
	{
		sc(n); sc(m);

		int type, p, q, v;
		while (m--)
		{
			sc(type); sc(p); sc(q);
			--p;
			if (type == 0)
			{
				sc(v);
				update(p, q, v);
			}
			else
			{
				printf("%lld\n", get_sum(p, q));
			}
		}
		mem(seg, 0); mem(lazy, 0);
	}
	return 0;
}