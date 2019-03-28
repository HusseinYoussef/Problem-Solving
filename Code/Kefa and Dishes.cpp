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

int n, m, k;
int saf[20];
ll dp[1 << 18][20];
int bonus[20][20];


ll solve(int idx,int msk,int cnt)                   
{
	if (cnt == m) return saf[idx];
	
	ll &ret = dp[msk][idx];
	if (~ret) return ret;
	
	for (int i = 1; i <= n; ++i)
	{
		if (!(msk & (1 << (i - 1))))	// try every dish to eat
		{
			ret = max(ret, saf[idx] + bonus[idx][i] + solve(i, msk | (1 << i - 1), cnt + 1));   // get the best
		}
	}

	return ret;
}

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	sc(n); sc(m); sc(k);
	mem(dp, -1);
	for (int i = 1; i <= n; ++i) sc(saf[i]);
	for (int i = 0; i < k; ++i)
	{
		int x, y, c;
		sc(x); sc(y); sc(c);
		bonus[x][y] = c;
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int msk = 0;
		ans = max(ans, solve(i, msk | (1 << i - 1), 1));
	}
	printf("%lld", ans);
	return 0;
}