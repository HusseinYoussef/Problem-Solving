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

int n, k;
int arr[10004];
int dp[10004][105];

int rec(int idx, int mod)
{
	if (idx == n)
	{
		if (mod == 0) return 1;
		return 0;
	}
	
	int &ret = dp[idx][mod];
	if (~ret) return ret;

	return ret = rec(idx + 1, ((mod + arr[idx]) + k) % k) | rec(idx + 1, ((mod - arr[idx]) + k) % k);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int T;
	sc(T);
	while (T--)
	{
		sc(n); sc(k);
		mem(dp, -1);
		for (int i = 0; i < n; ++i) sc(arr[i]);
		if (rec(1, (arr[0] % k + k) % k)) printf("Divisible\n");
		else printf("Not divisible\n");
	}
	return 0;
}