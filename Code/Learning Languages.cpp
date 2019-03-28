#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
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
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
#define sc(x)           scanf("%d",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lop(i, n)		for(int i=1;i<=n;++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define repa(v)				lpi(i, 0, sz(v)) lpi(j, 0, sz(v[i]))
#define pb					push_back
#define MP					make_pair
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int n, m;
vector<vector<int>>languages(102);
vector<vector<int>>connections(102);
bool vis[102];

void DFS(int indx)
{
	vis[indx] = 1;
	rep(i, connections[indx])
		if (!vis[connections[indx][i]])
			DFS(connections[indx][i]);
}

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	sc(n); sc(m);
	int zeros = 0;
	lop(i, n)
	{
		int num;
		sc(num);
		if (!num) ++zeros;
		lop(j, num)
		{
			int lang;
			sc(lang);
			languages[lang].push_back(i);
		}
	}
	if (zeros == n) {printf("%d",n); return 0;}
	lop(k, m)
	{
		int i = 0, j = i + 1;
		while (i < sz(languages[k]) && j < sz(languages[k]))
		{
			connections[languages[k][i]].pb(languages[k][j]);
			connections[languages[k][j]].pb(languages[k][i]);
			++i; ++j;
		}
	}
	int CC = 0;
	lop(i, n) 
	{
		if (!vis[i])
		{
			++CC;
			DFS(i);
		}
	}
	printf("%d", CC - 1);
	return 0;
}