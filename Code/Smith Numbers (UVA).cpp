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
#define INF					2e9+10			
#define llINF				40000000000100
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

const int N = 1e5 + 2;
vector<bool>primes(N, 1);
vector<int>p;

void sieve()
{
	primes[0] = primes[1] = 0;
	for (int i = 2; i*i <= N; ++i)
	{
		if (primes[i])
			for (int j = i*i; j < N; j += i)
				primes[j] = 0;
	}
}

ll count(ll x)
{
	int sum = 0;
	while (x)
	{
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int t; sc(t);
	ll n;
	sieve();
	for (int i = 2; i < N; ++i)if (primes[i])p.pb(i);
	while (t--)
	{
		scl(n);
		while (1)
		{
			++n;
			ll x = n;
			ll dig = count(x),s = 0;
			if (n == 4997801)
			{
				cout << "";
			}
			for (int i = 0; i < sz(p) && 1ll * p[i] * p[i] <= x; ++i)
			{
				int e = 0;
				while (x%p[i] == 0)
				{
					++e;
					x /= p[i];
				}
				s += 1ll*e*count(p[i]);
			}
			if (x > 1 && x != n)s += count(x);   // primes aren't smith numbers
			if (s == dig)
			{
				printf("%lld\n", n);
				break;
			}
		}
	}
	return 0;
}