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
#include <numeric>
#include <bitset>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
#define sc(x)            scanf("%d",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define EPS                            1e-9
#define pb					push_back
#define MP					make_pair
#define INF					1000000100			
#define llINF				10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int nums[205];
ll dp[205][25][15];
int N, Q;
int D, M;
ll solve(int idx, int remsum,int left)
{
	if (left == 0 && remsum == 0)return 1;
	if (idx == N || left == 0) return 0;

	ll &ret = dp[idx][remsum][left];
	if (~ret) return ret;

	return ret = solve(idx + 1, remsum, left) + solve(idx + 1, ((remsum + nums[idx]) % D + D) % D, left - 1);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int s = 1, q;
	while (scanf("%d%d", &N, &Q), (N || Q))
	{
		for (int i = 0; i < N; ++i) sc(nums[i]);

		printf("SET %d:\n", s++),q = 1;
		for (int i = 0; i < Q; ++i)
		{
			sc(D); sc(M);
			mem(dp, -1);
			ll ans = solve(0, 0, M);
			printf("QUERY %d: %lld\n", q++, ans);
		}

	}
	return 0;
}