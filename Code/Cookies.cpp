#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef unsigned int uint;

int main()
{
	int n;
	int sum = 1;
//*********************************
	scanf(" %d", &n);
	for (int i = 2; i <= n; ++i)
		sum = (sum * 3) % 1000003 ;

	cout << sum;

	return 0;
}