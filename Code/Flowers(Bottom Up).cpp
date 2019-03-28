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


int t, k, mod = 1e9 + 7;
int dp[100005];
int sum[100005];


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	sc(t); sc(k);
	dp[0] = 1;
	for (int i = 1; i <= 100000; ++i)
	{
		dp[i] = dp[i - 1];
		if (i >= k) dp[i] = (dp[i] + dp[i - k]) % mod;
	}
	for (int i = 1; i <= 1e5; ++i)
		sum[i] = (sum[i - 1] + dp[i]) % mod;

	int a, b;
	while (t--)
	{
		sc(a); sc(b);
		printf("%d\n", (sum[b] - sum[a - 1] + mod) % mod);
	}
	return 0;
}