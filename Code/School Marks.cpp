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
ll power(ll x, ll p) { if (p == 0) return 1; else if (p % 2 == 0) return power(1LL * x*x, p / 2); else return 1LL * x*power(1LL * x*x, (p - 1) / 2); }

const int N = 1e3 + 10;
int n, k, p, x, y;
int a[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n); sc(k); sc(p); sc(x); sc(y);
	int sum = 0; --n;
	for (int i = 0; i<k; ++i)
	{
		sc(a[i]);
		sum += a[i];
	}
	bool ok = 0;
	int b, s;
	int i;
	for (i = y; i <= p; ++i)
	{
		b = 0, s = 0;
		for (int j = 0; j<k; ++j)
		{
			if (a[j] > i) ++b;
			else if (a[j] < i) ++s;
		}
		if (b <= (n / 2) && s <= n / 2)
		{
			ok = 1;
			break;
		}
	}
	if (!ok || sum + min((n / 2) - s, n + 1 - k) + (n + 1 - k - min((n / 2) - s, n + 1 - k))*i > x)
		return puts("-1");

	for (int j = 0; j<min((n / 2) - s, n + 1 - k); ++j) printf("1 ");
	for (int j = 0; j<(n + 1 - k - min((n / 2) - s, n + 1 - k)); ++j) printf("%d ", i);

	return 0;
}
