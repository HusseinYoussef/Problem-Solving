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

int n, q;
int dp[100010][110];
int arr[100010];

int solve(int p, int k)
{
	if (p > n) return 0;
	if(k>109) return solve(p + arr[p] + k, k) + 1;

	int &ret = dp[p][k];
	if (ret != 0) return ret;

	return ret = solve(p + arr[p] + k, k) + 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	sc(n);
	for (int i = 1; i <= n; ++i) sc(arr[i]);
	sc(q);

	for (int i = 0; i < q; ++i)
	{
		int p, k;
		sc(p); sc(k);

		int ans = solve(p, k);
		printf("%d\n", ans);
	}

	return 0;
}