#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
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
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

const int N = 10;
int n;
bool grid[N][N];
bool vis[N];

int rec(int j, int sz)
{
	if (sz == n) return 0;

	int ans = INF;
	for (int i = 0; i < n; ++i)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			ans = min(ans, rec(i, sz + 1) + (!grid[i][j]));
			vis[i] = 0;
		}
	}
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	int t;
	sc(t);
	while (t--)
	{
		sc(n);
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { int t; sc(t); grid[i][j] = t; }

		int ans = INF;
		for (int i = 0; i < n; ++i)
		{
			vis[i] = 1;
			ans = min(ans, rec(i, 1));
			vis[i] = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}