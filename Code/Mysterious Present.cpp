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

int n,solve;
pair<int, int> enve[5010];
int dp[5010];
vector<int>path;

int LIS(int prv)
{
	int &ret = dp[prv];
	if (~ret) return ret;

	int maxi = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (enve[i].first > enve[prv].first && enve[i].second > enve[prv].second)
		{
			int ans = LIS(i) + 1;
			maxi = max(maxi, ans);
		}
	}
	return ret = maxi;
}

void getPath(int lgth,int prv)
{
	if (lgth < 0) return;
	for (int i = 1; i <= n; ++i)
	{
		if (dp[i] == lgth && (enve[i].first > enve[prv].first && enve[i].second > enve[prv].second))
		{
			path.pb(i);
			getPath(lgth - 1,i);
			break;
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	sc(n); sc(enve[0].first); sc(enve[0].second);
	for (int i = 1; i <= n; ++i) { sc(enve[i].first); sc(enve[i].second); }
	mem(dp, -1);

	solve = LIS(0);
	getPath(solve - 1, 0);

	printf("%d\n", solve);
	for (int i = 0; i < sz(path); ++i) printf("%d ", path[i]);
	
	return 0;
}