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
#define EPS                           1e-9
#define pb					push_back
#define MP					make_pair
#define INF					1000000100			
#define llINF				10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int n, m, a;
int pockets[100005], cst[100005];

bool valid(int r)
{
	int cnt = n - r, s = a;
	for (int i = 0; i < m && cnt < n; ++i)
	{
		if (pockets[cnt] + s < cst[i]) return false;
		else if (pockets[cnt] >= cst[i]) ++cnt;
		else if (pockets[cnt] + s >= cst[i]) { s -= (cst[i] - pockets[cnt]); ++cnt; }
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n); sc(m); sc(a);
	for (int i = 0; i < n; ++i)sc(pockets[i]);
	for (int i = 0; i < m; ++i)sc(cst[i]);
	
	sort(pockets, pockets + n);
	sort(cst, cst + m);
	                                            //Note :: if K boys can buy then the Richest K can buy the Cheapest K bikes
	ll l = 0, r = min(n,m), mid;                //BS to get the Max boys who can buy
	while (l < r)
	{
		mid = l + (r - l + 1) / 2;
		if (valid(mid))
			l = mid;
		else
			r = mid - 1;
	}
	printf("%d", r);

	ll sum = 0, price = 0;
	for (int i = n - r; i < n; ++i)sum += pockets[i];
	for (int i = 0; i < r; ++i)price += cst[i];

	l = 0, r = sum, mid;                            // BS to get the Min personal money to Pay
	while (l < r) 
	{
		mid = l + (r - l) / 2;
		if (mid + a >= price)
			r = mid;
		else
			l = mid + 1;
	}
	printf(" %I64d", r);
	return 0;
}