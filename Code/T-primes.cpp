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

vector<bool>primes(1000015, 1);
void sieve()
{
	primes[0] = primes[1] = 0;
	for (int i = 2; i*i <= 1000010; ++i)
	{
		if (primes[i])
		{
			for (int k = i + i; k <= 1000010; k += i)
				primes[k] = 0;
		}
	}
}
int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	ll num;
	int n;
	sieve();                        
	sc(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &num);                   // Important Ovservation *** only Squares of primes are T-Primes ***
		ll s = sqrt(num);
		(s * s == num && primes[s]) ? puts("YES") : puts("NO");
	}
	return 0;
}