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

int l, r, d;
vector<bool>prime(32005, 1);
deque<int>q;

bool valid()    //check if there is a determinate prime out of range
{
	bool up = false,down = false;
	for (int i = q.front() - 1; i >= 0; --i)
	{
		if (prime[i] && q.front() - i == d && (i < min(l, r) || i > max(l, r))) { down = false; break; }
		else if (prime[i] && q.front() - i != d) { down = true; break; }
	}
	for (int i = q.back() + 1; i <= 32000; ++i)
	{
		if (prime[i] && i - q.back() == d && (i < min(l, r) || i > max(l, r))) { up = false; break; }
		else if (prime[i] && q.back() - i != d) { up = true; break; }
	}
	return (up && down);
}

void print()
{
	std::deque<int>::iterator it;
	if (!valid()) return;
	int cnt = sz(q);
	for (it = q.begin(); it != q.end(); ++it, --cnt)
	{
		if (cnt > 1)printf("%d ", *it);
		else printf("%d\n", *it);
	}
}

void sieve()
{
	prime[0] = prime[1] = 0;
	for (int i = 2; i*i <= 32000; ++i)
	{
		if (prime[i])
		{
			for (int j = i + i; j <= 32000; j += i)
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

	sieve();
	while (scanf("%d%d", &l, &r) && (l || r))
	{
		q.clear();
		for (int i = min(l,r); i <= max(l,r); ++i)
		{
			if (i == 7829)
			{
				int k = 0;
				++k;
			}
			if (prime[i])
			{
				if (sz(q) == 0)
					q.pb(i);
				
				else if (sz(q) == 1)
				{
					d = i - q.back();
					q.pb(i);
				}
				else if (sz(q) >= 2)
				{
					int tst = i - q.back();
					if (tst != d)
					{
						if (sz(q) >= 3)
						{
							print();
							int tmp = q.back();
							q.clear();
							q.pb(tmp);
						}
						else
							q.pop_front();
						d = tst;
					}
					q.pb(i);
				}
			}
			if (i == max(l,r) && sz(q) >= 3)
				print();
		}
	}
	return 0;
}