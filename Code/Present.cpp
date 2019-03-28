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

int n, m, w;
int arr[100005],tmp[100005];

bool valid(ll len)             // important
{
	ll d = m, ex = 0;
	mem(tmp, 0);
	for (int i = 0; i < n; ++i)
	{
		ex += tmp[i];
		if (len - (arr[i] + ex) > 0)
		{
			if (len - (arr[i] + ex) > d) return false;

			tmp[min(n, i + w)] -= ((len - (arr[i] + ex)));
			d -= (len - (arr[i] + ex));
			ex += (len - (arr[i] + ex));
		}
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

	int mini = INF;
	sc(n); sc(m); sc(w);
	for (int i = 0; i < n; ++i) { sc(arr[i]); mini = min(mini, arr[i]); }

	ll l = mini, r = 2e9, mid;
	while (l < r)
	{
		mid = l + (r - l + 1) / 2;
		if (valid(mid))
			l = mid;
		else
			r = mid - 1;
	}
	printf("%I64d", r);
	return 0;
}