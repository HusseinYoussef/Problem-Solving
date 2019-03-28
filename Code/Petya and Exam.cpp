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
int inline max3(int a, int b, int c) { return max(a, max(b, c)); }

bool good[27];
int n;
string s, g, t;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int loc = -1;
	cin >> g >> s;
	for (int i = 0; i < sz(g); ++i)good[g[i] - 'a'] = 1;
	for (int i = 0; i < sz(s); ++i)if (s[i] == '*')loc = i;
	sc(n);

	while (n--)
	{
		cin >> t;
		if (loc == -1)
		{
			if (sz(s) != sz(t)) { puts("NO"); continue; }
			bool ok = 1;
			for (int i = 0; i < sz(s); ++i)
				ok &= (s[i] == t[i]) || (s[i] == '?' && good[t[i] - 'a']);
			(ok) ? puts("YES") : puts("NO");
		}
		else
		{
			if (sz(t) < sz(s) - 1) { puts("NO"); continue; }
			bool ok = 1;

			int lft = sz(s) - 1 - loc;
			for (int i = 0; i < loc; ++i)   // check chars before the *
				ok &= (s[i] == t[i]) || (s[i] == '?' && good[t[i] - 'a']);
			int j = sz(t) - 1;
			for (int i = sz(s) - 1; i > loc; --i, --j) // check chars after the *
				ok &= (s[i] == t[j]) || (s[i] == '?' && good[t[j] - 'a']);
			for (int i = loc; i <= j; ++i)  // check the chars the replaces the *
				ok &= (!good[t[i] - 'a']);
			(ok) ? puts("YES") : puts("NO");
		}
	}
	return 0;
}