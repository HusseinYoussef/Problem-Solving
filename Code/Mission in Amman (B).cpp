#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
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

int m, k;
ll sum = 0;
int arr[100005];

bool valid(ll n)
{
	int i = m - 1;
	ll h = 0;
	while (arr[i] > n && i >= 0)
	{
		h += (arr[i] - n);
		--i;
	}
	return (h <= k);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	sc(m); sc(k);
	for (int i = 0; i < m; ++i) { sc(arr[i]); sum += arr[i]; }
	sort(arr, arr + m);

	ll l = ceil(sum*1.0 /m), r = sum, mid;
	while (l < r)
	{
		mid = l + (r - l) / 2;
		if (valid(mid))
			r = mid;
		else
			l = mid + 1;
	}
	printf("%lld", r);
	return 0;
}