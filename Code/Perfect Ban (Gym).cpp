#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <stdio.h>
#include <map>
#include <unordered_map>
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
#define sz(v)				((int)v.size())
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
ll power(ll x, ll p) { if (p == 0) return 1; else if (p % 2 == 0) return power(1LL * x*x, p / 2); else return 1LL * x*power(1LL * x*x, (p - 1) / 2); }
ll GCD(ll a, ll b) { if (b == 0) return a; return GCD(b, a%b); }

const int N = 1e3 + 10;
int n, m;
int grid[N][N];

void getmax(int r,int c ,int &mr,int &mc)
{
	int mx = -1;
	for (int i = 1; i <= n; ++i)
	{
		if (i != r)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (j != c)
				{
					if (grid[i][j] > mx)
					{
						mx = grid[i][j];
						mr = i, mc = j;
					}
				}
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	sc(n); sc(m);
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)sc(grid[i][j]);

	int fmr, fmc;
	int smr, smc;
	int tmr, tmc;
	
	getmax(0, 0, fmr, fmc);

	getmax(fmr, 0, smr, smc);
	getmax(0, fmc, tmr, tmc);

	int r1, c1, r2, c2;
	getmax(fmr, smc, r1, c1);
	getmax(tmr, fmc, r2, c2);

	if (grid[r1][c1] < grid[r2][c2]) printf("%d %d", fmr, smc);
	else printf("%d %d", tmr, fmc);
	return 0;
}