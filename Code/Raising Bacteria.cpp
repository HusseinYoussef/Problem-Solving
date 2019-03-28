#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <numeric>
#include <map>
#include <vector>
#include <map>
#include <utility>
#include <set>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
int main()
{
	int n,cnt = 0;
	int sum = 1;

	cin >> n;
	while (n > 0)
	{
		if(sum *2 <= n)
		sum *= 2;
		else
		{
			n -= sum;
			sum = 1;
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}