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
const int mod = 1000000007;
int t, k;
int a, b;
int dp[100010];
int arr[100010];
int solve(int sum)                 // Important problem        
{ // sum represents the flower string that can be used        & let's see how we can reach it
	if (sum == 0)return 1;
	if (sum < 0) return 0;

	int &ret = dp[sum];
	if (~ret) return dp[sum];

	return dp[sum] = (solve((sum - 1) % mod) + solve((sum - k) % mod)) % mod;
}

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	sc(t); sc(k);
	mem(dp, -1);
	solve(100000);
	int arr[100010]; arr[0] = 0;
	for (int i = 1; i <= 1e5; ++i) arr[i] = (arr[i - 1] % mod + dp[i] % mod) % mod;
	while (t--)
	{
		sc(a); sc(b);
		printf("%lld\n", 1ll * ((arr[b] - arr[a - 1]) % mod + mod) % mod);   // Handle negtive and overflow
	}
	return 0;
}