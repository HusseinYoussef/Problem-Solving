#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
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
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
#define sc(x)           scanf("%d",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lop(i, n)		for(int i=0;i<n;++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define repa(v)				lpi(i, 0, sz(v)) lpi(j, 0, sz(v[i]))
#define pb					push_back
#define MP					make_pair

int k,cnt = 0;
int arr[15];
bool vis[15];
vector<vector<int>>subsets;

void rec(int indx,vector<int>vec)
{
	if (sz(vec) == 6) { subsets.push_back(vec); return; }
	else if (indx == k)return;
	for (int i = indx; i < k; ++i)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			vec.push_back(arr[i]);
			rec(i + 1, vec);
			vec.pop_back();
			vis[i] = 0;
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	while (true)
	{
		sc(k); if (!k)break;
		if (cnt > 0) { ++cnt; printf("\n"); }
		++cnt;
		lop(i, k)sc(arr[i]);
		vector<int>com; subsets.clear();
		rec(0, com);
		lop(i, sz(subsets))
			lop(j, sz(subsets[i]))
			printf("%d%c", subsets[i][j], (j != sz(subsets[i]) - 1) ? ' ' : '\n');
	}
	return 0;
}