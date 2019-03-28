#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
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
vector<bool>primes(100010, 1);
void sieve()
{
	primes[0] = primes[1] = 0;
	for (int i = 2; i*i <= 100001;++i)
	{
		if (primes[i])
		{
			for (int j = i + i; j <= 100001; j += i)
				primes[j] = 0;
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
	sc(n);
	sieve();
	printf("%d\n", (n >= 3) ? 2 : 1);
	for (int i = 1; i <= n; ++i)
	{
		if (primes[i+1])
			printf("1 ");
		else
			printf("2 ");
	}
	return 0;
}