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
#define lpi(i, j, n)	for(int i=(j);i<=(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define repa(v)				lpi(i, 0, sz(v)) lpi(j, 0, sz(v[i]))
#define pb					push_back
#define MP					make_pair

int n;
vector<pair<pair<int,int>,vector<int>>>Graph(102);
bool vis[102];

void DFS(int Node)
{
	vis[Node] = 1;
	rep(i, Graph[Node].second)
	{
		if (!vis[Graph[Node].second[i]])
			DFS(Graph[Node].second[i]);
	}
}

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	sc(n);
	lop(i, n)
	{
		int x, y;
		scanf("%d%d",&x, &y);
		Graph[i].first.first = x; Graph[i].first.second = y;
	}
	lop(i, n)
	{
		lpi(j, i + 1, n)
		{
			if (Graph[j].first.first == Graph[i].first.first || Graph[j].first.second == Graph[i].first.second)
			{
				Graph[i].second.push_back(j);
				Graph[j].second.push_back(i);
			}
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