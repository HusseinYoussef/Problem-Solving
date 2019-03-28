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

const int N = 105;
int n, m;
int grid[N][N];
int r[N], c[N], ansr[N], ansc[N];

int main()        // *** Brute Force Solution ***
{                 // take the first row k times then calculate the required times for other rows and columns
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int st = INF, sum = INF, cnt; bool f;            
	sc(n); sc(m);
	for (int i = 0; i < n; ++i)for (int j = 0; j < m; ++j)sc(grid[i][j]);
	for (int i = 0; i < m; ++i)st = min(st, grid[0][i]);           // the minimum element in the first row
	for (int i = 0; i <= st; ++i)    // iterating over all possible numbers can be used on the first row  from 0 times -> (min element) times
	{
		cnt = r[0] = i, f = 0;  // first row
		for (int j = 0; j < m; ++j)  // columns
			c[j] = grid[0][j] - i, cnt += c[j];          // since each element must be 0  if we know how many time we take the furst row
		for (int k = 1; k < n; ++k)  // check other rows       // then can calculate how many i need to take from each column to reach 0
		{
			int tst = grid[k][0] - c[0];
			if (tst < 0) { f = 1; break; }
			
			for (int z = 1; z < m; ++z)              // since i know how many i take from each column i can calculate how many i need to take from
				if (grid[k][z]-c[z] != tst) { f = 1; break; }       // the left rows
			
			if (f) break;
			r[k] = tst, cnt += tst;
		}
		if (f)continue;
		if (cnt < sum)
		{
			sum = cnt;
			for (int i = 0; i < n; ++i)ansr[i] = r[i];
			for (int i = 0; i < m; ++i)ansc[i] = c[i];
		}
	}
	if (sum == INF)sum = -1;
	printf("%d\n", sum);
	if (sum != -1)
	{
		for (int i = 0; i < n; ++i)
			if (ansr[i]) for (int j = 0; j < ansr[i]; ++j) printf("row %d\n", i + 1);
		for (int i = 0; i < m; ++i)
			if (ansc[i]) for (int j = 0; j < ansc[i]; ++j) printf("col %d\n", i + 1);
	}
	return 0;
}