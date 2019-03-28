#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>
#include <map>
#include <cmath>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned int uint;

int n_problems, l, r, x;
int NOW = 0;
int arr[20];
vector<int>vec;
void distro(int i,int sum)
{
	if (i == n_problems)
		return;

	for (int j = i; j < n_problems; ++j)
	{
		if (sum + arr[j] <= r)
		{
			vec.push_back(arr[j]);
			if (sum + arr[j] >= l && vec[vec.size()-1] - vec[0] >= x)
				++NOW;
			distro(j + 1, sum + arr[j]);
			vec.pop_back();
		}
		else
			return;
	}
}

int main()
{
	scanf(" %d%d%d%d", &n_problems, &l, &r, &x);

	for (int i = 0; i < n_problems; ++i)
		cin >> arr[i];
	
	sort(arr, arr + n_problems);

	distro(0, 0);

	printf("%d", NOW);
	return 0;
}