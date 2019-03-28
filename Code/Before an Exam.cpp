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

int d, ST;
pair<int, int> days[35];
int sol[35];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	sc(d); sc(ST);
	int sm = 0, sx = 0;
	for (int i = 0; i < d; ++i) { sc(days[i].first); sc(days[i].second); sm += days[i].first; sx += days[i].second; }

	if (ST >= sm && ST <= sx)
	{
		for (int i = 0; i < d; ++i)
		{
			sol[i] = days[i].first;
			ST -= sol[i];
		}
		while (ST > 0)
		{
			for (int i = 0; i < d; ++i)
			{
				if (sol[i] < days[i].second)
				{
					++sol[i];
					--ST;
					if (!ST) break;
				}
			}
		}
		puts("YES");
		for (int i = 0; i < d; ++i)printf("%d ", sol[i]);
		return 0;
	}
	return puts("NO");
}