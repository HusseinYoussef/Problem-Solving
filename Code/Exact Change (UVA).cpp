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

int n, price;
int bills[102];
int dp[102][100010];

int solve(int idx, int sum)
{
	if (sum == 0)  return 0;
	if (idx == n || sum < 0) return INF;

	int &ret = dp[idx][sum];
	if (~ret) return ret;

	return ret = min(solve(idx + 1, sum - bills[idx]) + 1, solve(idx + 1, sum));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	sc(t);
	while (t--)
	{
		int p;
		sc(p); sc(n);
		mem(dp, -1);
		for (int i = 0; i < n; ++i) sc(bills[i]);

		for (price = p; price <= 30010; ++price)                     // loop checking every price till we get a valid one
		{                                                            // and it will be the minimum
			int ans = solve(0, price);
			if (ans < INF) { printf("%d %d\n", price, ans); break; }
		}
	}
	return 0;
}