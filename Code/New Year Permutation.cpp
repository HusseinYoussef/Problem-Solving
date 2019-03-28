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
#define PI                  3.14159265
#define INF					1000000100			
#define llINF				10000000000100
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

const int N = 305;
int arr[N], par[N];
bool vis[N];
string grid[N];
int n;

int find(int u)
{
	if (u == par[u]) return u;
	return par[u] = find(par[u]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n);
	for (int i = 0; i < n; ++i)sc(arr[i]), par[i] = i;
	for (int i = 0; i < n; ++i)cin >> grid[i];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (grid[i][j] == '1')
			{
				int a = find(i); int b = find(j);
				if (a != b)
					par[a] = b;                          // all cells that can be swapped together are in the same connected component
			}                                            //  .**.*
		}                                                //  .*.*.        //all stars in the same connected component
	}
	for (int i = 0; i < n; ++i)find(i);                 
	for (int i = 0; i < n; ++i)
	{
		int c = find(i); int mn = INF;
		for (int j = 0; j < n; ++j)
		{
			if (par[j] == c && !vis[arr[j]])
			{
				mn = min(mn, arr[j]);
			}
		}
		vis[mn] = 1;
		printf("%d ", mn);
	}
	return 0;
}