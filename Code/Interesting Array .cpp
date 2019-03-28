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
int  seg[4 * N], lazy[4 * N];

void propagate(int father, int leftson, int rightson)
{
	seg[leftson] |= lazy[father];
	seg[rightson] |= lazy[father];
	lazy[leftson] |= lazy[father];
	lazy[rightson] |= lazy[father];
	lazy[father] = 0;
}
void update(int x, int y, int val, int id = 1, int l = 0, int r = n)
{
	if (x >= r || y <= l) return;
	if (l >= x && r <= y)
	{
		seg[id] |= val;
		lazy[id] |= val;
		return;
	}

	if (lazy[id])
	{
		propagate(id, id * 2, id * 2 + 1);
	}
	int mid = (l + r) / 2;

	update(x, y, val, id * 2, l, mid);
	update(x, y, val, id * 2 + 1, mid, r);

	seg[id] = seg[id * 2] & seg[id * 2 + 1];
}

int get_sum(int x, int y,int id = 1, int l = 0, int r = n)
{
	if (x >= r || y <= l) return (1 << 30) - 1;
	if (l >= x && r <= y)
	{
		return seg[id];
	}

	if (lazy[id])
	{
		propagate(id, id * 2, id * 2 + 1);
	}

	int mid = (l + r) / 2;
	return get_sum(x, y, id * 2, l, mid) & get_sum(x, y, id * 2 + 1, mid, r);
}

void print(int id = 1, int l = 0,int r = n)
{
	if (r - l < 2)
	{
		printf("%d ", seg[id]);
		return ;
	}
	if (lazy[id])
	{
		propagate(id, id * 2, id * 2 + 1);
	}
	int mid = (l + r) / 2;
	print(id * 2, l, mid);
	print(id * 2 + 1, mid, r);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n); sc(m);

	int x, y, z;
	vector<pair<int, pair<int, int>>>vec;
	while (m--)
	{
		sc(x); sc(y); sc(z);
		--x;
		vec.pb({ z,{x,y} });
		update(x, y, z);
	}
	for (int i = 0; i < sz(vec); ++i)
	{
		z = vec[i].first;
		x = vec[i].second.first;
		y = vec[i].second.second;
		if (get_sum(x, y) != z) return puts("NO");
	}
	puts("YES");
	print();
	return 0;
}