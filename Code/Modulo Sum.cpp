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

int n, m;
int seq[1000005];
int dp[1002][1002];

bool rec(int idx, int sum,bool tk)
{
	if (!sum && tk) return 1;
	if (idx == n) return 0;

	int &ret = dp[idx][sum];
	if (~ret) return ret;

	return ret = rec(idx + 1, sum, tk) || rec(idx + 1, (sum + seq[idx]) % m, 1);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	sc(n); sc(m);
	for (int i = 0; i < n; ++i) sc(seq[i]);
	mem(dp, -1);
	if (n >= m) return puts("YES");
	if (rec(0, 0, 0)) printf("YES");
	else printf("NO");
	return 0;
}