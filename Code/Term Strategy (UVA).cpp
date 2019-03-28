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

int N, M;
int grid[12][105];
int dp[12][105];

int rec(int course, int lft)
{
	if (lft < 0 || (course < N && lft == 0)) return -INF;
	if (course == N) return 0;

	int &ret = dp[course][lft];
	if (~ret) return ret;

	ret = -INF;
	for (int i = 0; i < M; ++i)
		if (grid[course][i] >= 5)
			ret = max(ret, rec(course + 1, lft - (i + 1)) + grid[course][i]);

	return ret;
}

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
		sc(N); sc(M);
		for (int i = 0; i < N; ++i)	for (int j = 0; j < M; ++j) sc(grid[i][j]);
		mem(dp, -1);

		double ans = rec(0, M);
		if (ans < 0) printf("Peter, you shouldn't have played billiard that much.\n");
		else printf("Maximal possible average mark - %.2lf.\n", (ans+EPS)/ N);        // EPS for precision Important
	}

	return 0;
}