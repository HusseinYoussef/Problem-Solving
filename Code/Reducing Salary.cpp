#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <numeric>
#include <iomanip>
#include <iterator>

using namespace std;

typedef long long ll;
typedef unsigned int uint;

ll Y , ans = -1;
ll sum;
bool verify(ll t)
{
	sum = 0;
	while (t > 0)
	{
		sum += t;
		t /= 10;
	}
	return sum >= Y;
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	scanf("%lld", &Y);
	
	ll l = Y/10, r = Y, mid;
	while (l < r)
	{
		mid = l + (r - l) / 2;
		if (verify(mid))
			r = mid;
		else
			l = mid + 1;
	}
	sum = 0; ll temp = r;
	while (temp > 0)
	{
		sum += temp;
		temp /= 10;
	}
	if (sum == Y) ans = r;
	printf("%lld", ans);
	return 0;
}