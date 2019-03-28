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
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int n, s;ll sum;
int cst[100005];
ll totprice[100005],pocket;

bool valid(int k)
{
	for (int i = 1; i <= n; ++i) totprice[i] = cst[i] + (long long)i*k;
	sort(totprice+1, totprice + n+ 1);

	pocket = 0;
	for (int i = 1; i <= k; ++i)
		pocket += totprice[i];
	
	return (pocket <= s);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n); sc(s);
	for (int i = 1; i <= n; ++i) sc(cst[i]);

	int l = 0, r = n, mid; sum = 0;
	while (l < r)                      //Binary Search to get the Max K
	{
		mid = l + (r - l + 1) / 2;
		if (valid(mid))
		{
			l = mid;
			sum = pocket;
		}
		else
			r = mid - 1;
	}
	printf("%d %I64d", r, sum);
	return 0;
}