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
#define sc(x)               scanf("%d",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define EPS                 1e-9
#define pb					push_back
#define MP					make_pair
#define INF					1000000100			
#define llINF				10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

vector<pair<int, int>>objects(1010);
int dp[1010][32];
int N, G, MW, sum;

int solve(int idx, int wt)                        // Knapsack 
{
	if (wt > MW) return -1e6;                     // Be careful when both Base cases happen together (idx & wt)
	if (idx == N || wt == MW) return 0;
	
	int &ret = dp[idx][wt];
	if (~ret)return ret;

	return ret = max(solve(idx + 1, wt), solve(idx + 1, wt + objects[idx].second) + objects[idx].first);

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
		sc(N);
		for (int i = 0; i < N; ++i)
		{
			sc(objects[i].first), sc(objects[i].second);
		}
		sc(G), sum = 0;
		for (int i = 0; i < G; ++i)
		{
			sc(MW);
			mem(dp, -1);
			sum += solve(0, 0);
		}
		printf("%d\n", sum);
		objects.clear();
		objects.resize(1010);
	}
	return 0;
}