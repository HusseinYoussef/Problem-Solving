#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef unsigned int uint;
int main()
{
	int n_elements;
	LL arr[500010], sum = 0, temp = 0, ans = 0, x = 0;
	//******************************************************
	scanf(" %d", &n_elements);
	for (int i = 0; i < n_elements; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum % 3 == 0)
	{
		sum /= 3;
		for (int i = 0; i < n_elements - 1; ++i)
		{
			temp += arr[i];

			if (temp == 2 * sum) ans += x;

			if (temp == sum)++x;
		}
	}
	cout << ans;                  // printf caused overflow because CF doesnt accept &lld long long
	return 0;
}