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
#define sz(v)				((int)v.size())
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
ll inline max3(ll a, ll b, ll c) { return max(a, max(b, c)); }
ll inline min3(ll a, ll b, ll c) { return min(a, min(b, c)); }
ll power(ll x, ll p) { if (p == 0) return 1; else if (p % 2 == 0) return power(1LL * x*x, p / 2); else return 1LL * x*power(1LL * x*x, (p - 1) / 2); }
ll GCD(ll a, ll b) { if (b == 0) return a; return GCD(b, a%b); }

int n, n1, n2, c1, c2;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	while (scanf("%d", &n) && n)
	{
		sc(c1); sc(n1); sc(c2); sc(n2);

		if (n % GCD(n1, n2)) { puts("failed"); continue; }

		if (c1 * 1.0 / n1 < c2*1.0 / n2) // --> to get the minimum cost we compare person price(pp) for each boat
		{                              // it's obvious to take as much as possible of the cheaper price  --> so boat with cheaper pp  will
			for (int i = n / n1; i >= 0; --i)       // be used more than the other boat |  so we get the maximum number i can use it (x)
			{                                       // x*n1 + y*n2 = n    --> we got x so we can get y easily
				if ((n - (i*n1)) % n2 == 0)
				{
					printf("%d %d\n", i, (n - (i*n1)) / n2);
					break;
				}
			}
		}
		else
		{
			for (int i = n / n2; i >= 0; --i)
			{
				if ((n - (i*n2)) % n1 == 0)
				{
					printf("%d %d\n", (n - (i*n2)) / n1, i );
					break;
				}
			}
		}
	}
	return 0;
}