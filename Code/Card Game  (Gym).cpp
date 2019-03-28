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
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

const int N = 1e6 + 5;
int n, k;
int arr[N];

bool valid(ll pw)
{
	int kd = 1;
	int cnt = 0,mx = arr[0];
	for (int i = 0; i < n; ++i)
	{	
		if (arr[i] > pw) return 0;         //each card power should be <= pw    or we will just move to the next kid
		mx = max(mx, arr[i]), ++cnt;
		ll p = mx * cnt * 1LL;
		if (p > pw)
		{
			++kd;
			cnt = 1;
			mx = arr[i];
		}
		if (kd > k) return 0;
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int T;
	sc(T);
	while (T--)
	{
		int mx = -1;
		sc(n); sc(k);
		for (int i = 0; i < n; ++i) { sc(arr[i]); mx = max(mx, arr[i]); }

		ll l = 0, r = (ll)n*mx, mid;
		while (l < r)
		{
			mid = l + (r - l) / 2;
			if (valid(mid))
				r = mid;
			else
				l = mid + 1;
		}
		printf("%I64d\n", r);
	}
	return 0;
}