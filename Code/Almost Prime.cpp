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
#define EPS                           1e-9
#define pb					push_back
#define MP					make_pair
#define INF					1000000100			
#define llINF				10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

vector<bool>prime(3005, 1);
bool arr[3005];

void Sieve()
{
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= 3002; ++i)
	{
		if (prime[i])
		{
			for (int j = i + i; j <= 3000; j += i)
				prime[j] = 0;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int n;
	Sieve();
	sc(n);

	for (int i = 1; i <= n; ++i)
	{
		int ans = 0;
		int tmp = i;
		for (int j = 2; j < 3000; ++j)
		{
			if (prime[j] && tmp % j == 0)
			{
				++ans;
				while (tmp % j == 0) tmp /= j;
			}
			if (tmp == 1) break;
		}
		if (ans == 2) arr[i] = 1;
	}
	
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans += arr[i];
	printf("%d", ans);

	return 0;
}