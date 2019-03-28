#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>

using namespace std;

typedef long long LL;
typedef unsigned int uint;

int main()
{
	int n_locations, s_population,sum = 0;
	map <int, int>mp;
	int arr[1005];
//******************************************

	scanf(" %d %d", &n_locations, &s_population);

	for (int i = 0; i < n_locations; ++i)
	{
		int x_cor, y_cor,popul_city;
		scanf(" %d%d%d", &x_cor, &y_cor, &popul_city);

		arr[i] = x_cor * x_cor + y_cor * y_cor;             // x^2 + y^2 = R^2   Circle Equation

		mp[arr[i]] += popul_city;                           // (1,1) (1,-1) (-1,-1)  Same circle
	}
	sort(arr, arr + n_locations);
	for (int i = 0; i < n_locations; ++i)
	{
		sum += mp[arr[i]];

		if (sum + s_population >= 1000000)
		{
			printf("%.7lf", sqrt((double)arr[i])); return 0;
		}
		mp[arr[i]] = 0;                                   // Because of the case in which Repeated number resulted of (x^2 + y^2)
	}
	printf("-1");
	return 0;
}