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

const int N = 2e3 + 10;
int sum[N], a[N], b[N];
int k, n;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	set<int>mp;
	sc(k); sc(n);
	for (int i = 1; i <= k; ++i)sc(a[i]), sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; ++i) { sc(b[i]); mp.insert(b[i]); }
	set<ll>isc;
	for (int i = 1; i <= k; ++i)isc.insert(b[1]-sum[i]);
	
	set<ll>::iterator it; int ans = 0;
	for (it = isc.begin(); it != isc.end(); ++it)
	{
		set<int>st;
		for (int i = 1; i <= k; ++i)              // better use set over map for time to check if number exists or not  
		{
			if (mp.count(sum[i] + *it))st.insert(sum[i] + *it);
		}
		if (sz(st) == n) ++ans;
	}
	printf("%d", ans);
	return 0;
}