#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <queue>
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
#include <numeric>
#include <bitset>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
#define sc(x)           scanf("%d",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define EPS                             1e-9
#define pb					push_back
#define MP					make_pair
#define INF					1000000100			
#define llINF					10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

vector<int>primes;
bool isprime(int p)
{
	if (p == 0 || p == 1) return 0;
	for (int i = 2; i*i <= p; ++i)
	{
		if (p % i == 0)
			return false;
	}
	return true;
}

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	int n;
	sc(n);
	for (int i = n; i > 1; i-=2)
	{
		if (isprime(i))
		{
			n -= i;
			primes.pb(i);
			break;
		}
	}
	if (n == 2) primes.pb(2), n -= 2;
	for (int i = n-1; i > 1; --i)
	{
		if (isprime(i) && isprime(n - i))
		{
			primes.pb(i), primes.pb(n - i);
			break;
		}
	}
	printf("%d\n", sz(primes));
	for (int i = 0; i < sz(primes); ++i)
		printf("%d ", primes[i]);
	return 0;
}