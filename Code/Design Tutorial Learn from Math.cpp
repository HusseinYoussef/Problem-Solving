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

vector<bool>primes(1000100, 1);
void sieve(int n)
{
	primes[0] = primes[1] = 0;
	for (int i = 2; i*i <= n; ++i)
	{
		if (primes[i])
		{
			for (int k = i + i; k <= n; k += i)
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
	int n;
	cin >> n;
	sieve(n);
	for (int i = 2; i < n; ++i)
	{
		if (!primes[i] && !primes[n - i])
		{
			cout << i << " " << n - i;
			return 0;
		}
	}
	return 0;
}