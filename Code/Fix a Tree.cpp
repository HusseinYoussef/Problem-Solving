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
int n, arr[N], p[N]; bool vis[N];
int root = -1, ans;

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

	sc(n);
	for (int i = 1; i <= n; ++i) { sc(arr[i]), p[i] = i; if (i == arr[i])root = i; } // notice cycle may exist

	for (int i = 1; i <= n; ++i)
	{
		int a = find(i), b = find(arr[i]);     // so first let's destroy the cycles
		if (a != b)
		{
			p[a] = b;
		}
		else
		{
			if (arr[i] != i)                  // if a & b in same components and not a one node
			{// same cc  cycle                // then it's a cycle
				if (root == -1)
				{
					root = i;
					arr[i] = i;
					++ans;
				}
				else
				{
					p[a] = root;
					++ans;
					arr[i] = root;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) // as far as now .. no cycles .. only disjoint sets  so we join them
	{
		int a = find(i), b = find(root);
		if (a != b)
		{
			p[a] = b;
			arr[a] = b;
			++ans;
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i)printf("%d ", arr[i]);
	return 0;
}