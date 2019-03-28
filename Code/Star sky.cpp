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
typedef vector<vector<int> > VVI;
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
#define WHITE 0
#define GRAY 1
#define BLACK 2
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int inline max3(int a, int b, int c) { return max(a, max(b, c)); }

const int N = 1e5 + 10;
int n, q, c;
int dp[12][105][105], grid[12][105][105];

int main()           // *** Prefix sum Problem ***
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n); sc(q); sc(c);
	int x, y, s;
	while (n--)       
	{
		sc(x); sc(y); sc(s);
		++dp[s][x][y];
	}                                  // precalculate all rectangles from (1,1) to (i,j) for each initial brightness k
	for (int k = 0; k <= 10; ++k)for (int i = 1; i <= 100; ++i)for (int j = 1; j <= 100; ++j) 
		dp[k][i][j] = dp[k][i][j] + dp[k][i - 1][j] + dp[k][i][j - 1] - dp[k][i - 1][j - 1];
	int t, x2, y2;
	while (q--)
	{
		sc(t); sc(x); sc(y); sc(x2); sc(y2);
		ll ans = 0;
		for (int i = 0; i <= 10; ++i)    // now we have rect (1,1) to (x2,y2) and rect from (1,1) to (x,y)  we need the difference
		{                          // we get it using inclusion-exclusion  -> P.S (x-1) and (y-1) since the borders are considered inside the rect
			ans += ((dp[i][x2][y2] - dp[i][x2][y - 1] - dp[i][x - 1][y2] + dp[i][x - 1][y - 1]) * 1LL * ((i + t) % (c + 1)));
		}
		printf("%I64d\n", ans);
	}
	return 0;
}