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
int n, m, q;
map<string, int>mp;

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

	string s;
	sc(n); sc(m); sc(q);
	for (int i = 1; i <= n; ++i)
	{
		cin >> s;
		mp[s] = i;
		p[i] = i;
		p[i + n] = i + n;
	}
	int t;
	string x, y;
	while (m--)
	{
		sc(t);
		cin >> x >> y;

		int a = find(mp[x]), b = find(mp[y]);
		int abar = find(mp[x] + n), bbar = find(mp[y] + n);
		
		if (t == 1)
		{
			if (a != bbar)
			{
				p[a] = b;
				p[abar] = bbar;
				printf("YES\n"); continue;
			}
		}
		else
		{
			if (a != b)
			{
				p[a] = bbar;
				p[abar] = b;
				printf("YES\n"); continue;
			}
		}
		printf("NO\n");
	}
	while (q--)
	{
		cin >> x >> y;

		int a = find(mp[x]), b = find(mp[y]);
		int abar = find(mp[x] + n), bbar = find(mp[y] + n);

		if (a == b) puts("1");
		else if (a == bbar) puts("2");
		else puts("3");
	}
	return 0;
}