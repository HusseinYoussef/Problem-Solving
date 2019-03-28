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

const int  N = 2e3 + 10;

int n, k, pos;
int a[N], b[N]; ll dp[N][N];

ll rec(int p, int m)
{
	if (p == n)return 0;
	if (m == k)return llINF;

	ll &ret = dp[p][m];
	if (~ret)return ret;

	return ret = min(rec(p, m + 1), max(rec(p + 1, m + 1), (ll)abs(a[p] - b[m]) + abs(b[m] - pos)));   
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n); sc(k); sc(pos);
	for (int i = 0; i < n; ++i)sc(a[i]);
	for (int i = 0; i < k; ++i)sc(b[i]);
	sort(a, a + n); sort(b, b + k); mem(dp, -1);       //sort to make each person close to the closest key
	printf("%lld", rec(0, 0));
	return 0;
}