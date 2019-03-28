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

const int N = 1e3 + 10;
int n, m;
int minS[N], maxjobs[N], fixS[N];
int empl[N];
string str;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int t;
	sc(t);
	while (t--)
	{
		sc(n); sc(m);
		ll ans = 0; int cnt = 0;
		
		for (int i = 1; i <= n; ++i)sc(minS[i]);
		for (int i = 1; i <= m; ++i) { sc(fixS[i]); sc(maxjobs[i]); }
		for (int i = 1; i <= n; ++i)
		{
			int idx = 0, mx = 0;
			cin >> str;
			for (int j = 0; j < m; ++j)
			{
				if (str[j] == '1')
				{
					if (fixS[j+1] >= minS[i] && fixS[j + 1] > mx && maxjobs[j + 1] > 0)
					{
						idx = j + 1;
						mx = fixS[j + 1];
					}
				}
			}
			if (idx)
			{
				++cnt;
				ans += fixS[idx];
				--maxjobs[idx];
				empl[idx]++;
			}
		}
		int sum = 0;
		for (int i = 1; i <= m; ++i)if (empl[i] == 0)++sum;

		printf("%d %lld %d\n", cnt, ans, sum);
		mem(empl, 0);
	}
	return 0;
}