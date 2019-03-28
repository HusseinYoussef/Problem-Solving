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
#define sc(x)              scanf("%d",&x)
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

int n;
int arr[200010];
ll dp[2][200010];
bool trap[2][200010];

ll solve(bool op, int idx)                             // takecare overflow
{
	if (idx < 0 || idx >= n) return 0;

	ll &ret = dp[op][idx];
	if (~ret) return ret;

	if (trap[op][idx]) return -llINF;                   // for cycle
	trap[op][idx] = 1;

	if (op)	ret = arr[idx] + solve(0, idx - arr[idx]);
	else ret = arr[idx] + solve(1, idx + arr[idx]);

	trap[op][idx] = 0;
	return ret;
}

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	ll ans;
	sc(n);
	for (int i = 1; i < n; ++i)sc(arr[i]);
	mem(dp, -1);

	for (int i = 1; i < n; ++i)
	{
		arr[0] = i;
		ans = i + solve(1, i);

		if (ans < 0) puts("-1");
		else printf("%lld\n", ans);
	}

	return 0;
}