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
#define INF					2000000100			
#define llINF				10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int n;
pair<int, int> tree[100005];
int dp[100005][3];

int rec(int idx, int op, int lst)
{
	if (idx == n) return 0;

	int &ret = dp[idx][op];
	if (~ret) return ret;

	ret = -INF;
	if (tree[idx].first > lst)
		ret = max(ret, rec(idx + 1, 0, tree[idx].first));
	if (tree[idx].first - tree[idx].second > lst)
		ret = max(ret, rec(idx + 1, 1, tree[idx].first) + 1);
	if (tree[idx].first + tree[idx].second < tree[idx + 1].first)
		ret = max(ret, rec(idx + 1, 2, tree[idx].first + tree[idx].second) + 1);

	return ret;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	sc(n);
	for (int i = 0; i < n; ++i) { sc(tree[i].first); sc(tree[i].second); }
	tree[n].first = INF;
	mem(dp, -1);

	int ans = rec(0, 0, -INF);
	printf("%d", ans);

	return 0;
}