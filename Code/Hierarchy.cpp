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

const int N = 1e4 + 10;
int p[N], q[N];
bool sp[N];
pair<int, pair<int, int>>arr[N];
int n, m;

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

	sc(n);
	for (int i = 0; i <= n; ++i)p[i] = i;
	for (int i = 0; i < n; ++i) sc(q[i]);
	sc(m);

	int from, to, cst;
	for (int i = 0; i < m; ++i)
	{
		sc(from); sc(to); sc(cst);
		arr[i] = { cst,{from,to} };
	}
	sort(arr, arr + m);
	
	ll ans = 0;
	for (int i = 0; i < m; ++i)
	{
		int a = find(arr[i].second.first), b = find(arr[i].second.second);
		if (a != b && !sp[arr[i].second.second])
		{
			p[a] = b;
			sp[arr[i].second.second] = 1;     // this guy got him self a supervisor can't get another one  1 supervisor for each employee
			ans += arr[i].first;
		}
	}
	int tst = find(1);
	for (int i = 2; i <= n; ++i) if (find(i) != tst) return puts("-1");
	printf("%I64d", ans);
	return 0;
}