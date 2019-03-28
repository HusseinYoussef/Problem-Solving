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
#define INF					1000000100			
#define llINF				10000000000100
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

const int N = 105;
int n, m;
char grid[N][N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int bs = 0;
	sc(n); sc(m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) cin >> grid[i][j];

	int minx = n, miny = m, maxx = 0, maxy = 0;
	for(int i=0;i<n;++i)
		for (int j = 0; j < m; ++j)
		{
			if (grid[i][j] == 'B')
			{
				++bs;
				if (i < minx) minx = i;
				if (i > maxx)maxx = i;
				if (j < miny) miny = j;
				if (j > maxy) maxy = j;

			}
		}
	if (bs == 0) return puts("1");
	int h = maxy - miny + 1, v = maxx - minx + 1;
	int all = max(h, v)*max(h, v);

	h = max(h, v), v = max(h, v);
	if (h > m || v > n) return puts("-1");
	printf("%d", all - bs);
	return 0;
}