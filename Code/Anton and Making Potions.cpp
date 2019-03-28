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

const int N = 2e5 + 10;
int n, m, k, x, s;
int spellA[N], cstA[N];
int spellB[N], cstB[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n); sc(m); sc(k);
	sc(x); sc(s);
	for (int i = 1; i <= m; ++i)sc(spellA[i]);
	for (int i = 1; i <= m; ++i)sc(cstA[i]);
	for (int i = 1; i <= k; ++i)sc(spellB[i]);
	for (int i = 1; i <= k; ++i)sc(cstB[i]);
	spellA[0] = x, cstA[0] = 0;
	ll mn = 1LL * x*n;
	for (int i = 0; i <= m; ++i)
	{
		if (s >= cstA[i])
		{
			int mana = s - cstA[i];
			int l = 0, r = k, mid;
			while (l < r)
			{
				mid = l + (r - l + 1) / 2;
				if (cstB[mid] <= mana) l = mid;
				else r = mid - 1;
			}
			mn = min(mn, 1LL * (n - spellB[l])*spellA[i]);
		}
	}
	printf("%lld", mn);
	return 0;
}
