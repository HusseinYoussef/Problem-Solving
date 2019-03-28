#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdio>
#include <set>
#include <utility>

using  namespace std;

typedef long long ll;
typedef unsigned int uint;

int main()
{
	int n, arr[110];
	int maxy = 0, zeros = 0, ones = 0, all = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) { scanf("%d", &arr[i]); if(arr[i])++all; }
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= n - i; ++j)
		{
			ones = zeros = 0;
			for (int k = j; k < i +j; ++k)
			{
				if (arr[k])
					++ones;
				else
					++zeros;
			}
			if (all + zeros - ones > maxy)
				maxy = all + zeros - ones;
		}
	}
	cout << maxy;
	return 0;
}

/*
int main()                                       A Better solution
{
	int n, a, ones = 0, zeros = 0, MAX = 0;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> a;
		if (a)
		{
			ones++;
			if (zeros)zeros--;
		}
		else
		{
			zeros++;
			zeros>MAX ? MAX = zeros : zeros;
		}
	}
	MAX == 0 ? cout << ones - 1 << endl : cout << ones + MAX << endl;

	return 0;
}*/