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

int n, k, G, T;
bool vis[105];
string road;

bool valid(int idx)
{
	return (idx < n && idx >= 0 && road[idx] != '#' && !vis[idx]);
}

void DFS(int idx)
{
	vis[idx] = 1;

	if (valid(idx + k)) DFS(idx + k);
	if (valid(idx - k)) DFS(idx - k);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	sc(n); sc(k);
	cin >> road;
	for (int i = 0; i < sz(road); ++i) { if (road[i] == 'G')G = i; else if (road[i] == 'T')T = i; }

	DFS(G);

	if (vis[T])return puts("YES");
	return puts("NO");
}