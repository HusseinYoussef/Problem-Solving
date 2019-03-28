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

int a, b, N;
set<ll>s;
int freq[12], points[12];

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
		sc(a); sc(b); sc(N);
		s.clear();
		for (int i = 1; i*i <= N; ++i)
		{
			ll tmp = (1LL*a*i*i) + (1LL*b*i);
			if (tmp <= N)
				s.insert(tmp);
		}
		if (!sz(s)) { puts("-1"); continue; }
		int ans = 0;
		for (auto t : s)
		{
			ll tmp = t;
			int mx = 0;
			while (tmp)
			{
				mx = max(mx, ++freq[tmp % 10]);
				tmp /= 10;
			}
			for (int i = 0; i < 10; ++i)
			{
				if (freq[i] == mx)
					ans = max(ans, ++points[i]);
				freq[i] = 0;
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			if (points[i] == ans)
			{
				printf("%d\n", i); break;
			}
		}
		mem(points, 0);
	}
	return 0;
}