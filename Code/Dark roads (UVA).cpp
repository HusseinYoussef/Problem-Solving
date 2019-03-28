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
#define EPS                 1e-9
#define pb					push_back
#define MP					make_pair
#define PI                  3.14159265
#define INF					1000000100			
#define llINF				10000000000100
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

const int N = 2e5 + 10;
int p[N];
int m, n;

int find(int u)
{
	if (u == p[u]) return u;
	return p[u] = find(p[u]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int x, y, z;
	while (scanf("%d%d", &m, &n) && m && n)
	{
		vector<pair<int, pair<int, int>>>vec;
		for (int i = 0; i < N; ++i)p[i] = i;
		int tot = 0;
		for (int i = 0; i < n; ++i)
		{
			sc(x); sc(y); sc(z);
			vec.pb({ z,{x,y} });
			tot += z;                           //Calculate total current cost
		}
		sort(vec.begin(), vec.end());
		int MST = 0;                            //Calculate The MST  (min cost and conneced Graph (Tree))
		for (int i = 0; i < sz(vec); ++i)
		{
			int a = find(vec[i].second.first), b = find(vec[i].second.second);
			if (a != b)
			{
				p[a] = b;
				MST += vec[i].first;
			}
		}
		printf("%d\n", tot - MST);            // the max money we save is the Difference between total and min cost
	}
	return 0;
}