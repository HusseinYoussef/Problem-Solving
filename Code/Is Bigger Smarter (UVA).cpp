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

int cnt = 1;
pair<int, int>animals[1010];
vector<int>path;
int dp[1010];

int rec(int idx)
{
	if (idx == cnt) return 0;

	int &ret = dp[idx];
	if (~ret) return ret;

	ret = 0;
	for (int i = 1; i < cnt; ++i)
	{
		if (animals[i].first > animals[idx].first && animals[i].second < animals[idx].second)
			ret = max(ret, rec(i) + 1);
	}
	return ret;
}

void getpath(int idx,int lft)
{
	if (lft < 0) return;
	for (int i = 1; i < cnt; ++i)
	{
		if (dp[i] == lft && animals[i].first > animals[idx].first && animals[i].second < animals[idx].second)
		{
			path.pb(i);
			getpath(i,lft - 1);
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
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	while (scanf("%d%d", &animals[cnt].first, &animals[cnt].second) != EOF)	++cnt;
	animals[0] = { 0,INF };
	mem(dp, -1);

	int ans = 0;
	for (int i = 1; i < cnt; ++i)
		ans = max(ans, rec(i));
	getpath(0,ans);

	printf("%d\n", sz(path));
	for (int i = 0; i < sz(path); ++i)printf("%d\n", path[i]);

	return 0;
}