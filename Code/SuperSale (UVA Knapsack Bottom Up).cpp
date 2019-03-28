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

int N, MW;
pair<int,int> arr[1005];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int T;
	sc(T);
	while (T--)
	{
		sc(N);
		for (int i = 1; i <= N; ++i) { sc(arr[i].second); sc(arr[i].first); }

		int G;
		sc(G);

		sort(arr, arr + N);
		int dp[1005][35];
		int ans = 0;
		for (int k = 0; k < G; ++k)
		{
			sc(MW);
			mem(dp, 0);

			for (int j = 1; j <= MW; ++j)
			{
				if (j >= arr[1].first) dp[1][j] = arr[1].second;
			}

			for (int i = 2; i <= N; ++i)
			{
				for (int j = 1; j <= MW; ++j)
				{
					if (j < arr[i].first) dp[i][j] = dp[i - 1][j];
					else dp[i][j] = max(dp[i - 1][j], arr[i].second + dp[i - 1][j - arr[i].first]);
				}
			}
			ans += dp[N][MW];
		}
	
		printf("%d\n", ans);
	}
	return 0;
}