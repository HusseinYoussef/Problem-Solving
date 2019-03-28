#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <numeric>
#include <iterator>

using namespace std;

typedef long long LL;
typedef unsigned int uint;

int A_start, B_end,K_primes;
vector<int>prime(1000005,1);

void sieve()
{
	prime[0] = prime[1] = 0;

	for (int i = 2; i <= B_end;++i)
	{
		if (prime[i])
		{
			for (int j = i+i; j <= B_end; j += i)
			{
				prime[j] = 0;
			}
		}
	}
}

int main()
{
	scanf(" %d%d%d", &A_start, &B_end, &K_primes);
	sieve();
	int sum = 0;
	for (int i = A_start; i <= B_end; ++i)
		sum += prime[i];
	if (sum < K_primes)
	{
		printf("-1"); return 0;
	}


	for (int i = 2; i <= B_end; ++i)
		prime[i] += prime[i - 1];

	int l = 1, r = B_end - A_start + 1, mid;  
	while (l < r)
	{
		bool found = true; int cnt = 0;
		mid = l + (r - l) / 2;
		for (int i = A_start; i <= B_end - mid + 1; i++)
		{
			if (prime[i] != prime[i-1]) cnt = 1;
			if (prime[i + mid - 1] - prime[i] + cnt < K_primes)
			{
				found = false;
				break;
			}
			cnt = 0;
		}
		if (found)
			r = mid;
		else
			l = mid+ 1;
	}
	printf("%d", r);
	return 0;
}