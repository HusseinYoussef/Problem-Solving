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

int n, m;
int cap[200010];
int water[200010];
set<int>emp;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	sc(n);
	for (int i = 1; i <= n; ++i) { sc(cap[i]); emp.insert(i); }
	sc(m);
	for (int i = 0; i < m; ++i)
	{
		int tst;
		sc(tst);

		if (tst == 1)
		{
			int p, x;
			sc(p); sc(x);

			while (x > 0)
			{
				if (x + water[p] > cap[p])
				{
					x = x - (cap[p] - water[p]);
					water[p] = cap[p];
					if (p == n) x = 0;
					emp.erase(p);
				}
				else
				{
					water[p] += x; x = 0;
				}
				set<int> ::iterator it = emp.lower_bound(p);
				if (it == emp.end()) break;
				p = *it;
			}
		}
		else
		{
			int k;
			sc(k);

			printf("%d\n", water[k]);
		}
	}
	return 0;
}