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
const int mod = 1e8;
int n1, n2, k1, k2;
int dp[102][102][12][12];

int solve(int fo, int hor, int f, int h)
{
	if (f > k1 || h > k2 || fo < 0 || hor < 0) return 0;
	if (fo + hor == 0)return 1;

	int &ret = dp[fo][hor][f][h];
	if(~ret) return dp[fo][hor][f][h];

	return ret = (solve(fo - 1, hor, f + 1, 0) % mod + solve(fo, hor - 1, 0, h + 1) % mod) % mod;
}

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	sc(n1); sc(n2); sc(k1); sc(k2);
	mem(dp, -1);

	int ans = solve(n1, n2, 0, 0);
	printf("%d", ans);
	return 0;
}