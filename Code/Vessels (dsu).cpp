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

const int  N = 2e5 + 10;
int par[N], ans[N], cap[N];
int n, m;

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
	for (int i = 1; i <= n+1; ++i)par[i] = i;
	for (int i = 1; i <= n; ++i)sc(cap[i]);
	sc(m);
	int t, p, x, k;
	while (m--)
	{
		sc(t);
		if (t == 1)
		{
			sc(p); sc(x);

			for (int i = find(p); i <= n; i = find(i + 1))
			{
				int tmp = ans[i];
				ans[i] += min(cap[i], x);
				cap[i] -= ans[i]-tmp;
				x -= ans[i]-tmp;
				if (cap[i] == 0)
				{
					par[i] = find(i + 1);
				}
				if (x == 0)break;
			}
		}
		else
		{
			sc(k);
			printf("%d\n", ans[k]);
		}
	}
	return 0;
}