#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <numeric>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int uint;

int t, n;
int arr[15];
int vis[15];
vector<int>summy;
vector<vector<int>>vec;
map<vector<int>, bool>mp;

void rec(int sum, int indx)
{
	if (sum >= t)
	{
		if (sum == t)
		{
			if (!mp[summy])
			{
				mp[summy] = 1;
				vec.push_back(summy);
			}
		}
		return;
	}
	for (int i = indx; i < n; ++i)
	{
		if (!vis[i])
		{
			summy.push_back(arr[i]);
			vis[i] = 1;
			rec(sum + arr[i], i + 1);
			summy.pop_back();
			vis[i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif

	while (true)
	{
		scanf("%d%d", &t, &n);
		if (!t)
		 break;	
		vec.clear(); mp.clear();
		for (int i = 0; i < n; ++i)
			scanf("%d", &arr[i]);

		printf("Sums of %d:\n", t);
		rec(0, 0);
		if (!mp.size()) printf("NONE\n");
		else
		{
			for (int i = 0; i < vec.size(); ++i)
			{
				for (int j = 0; j < vec[i].size(); ++j)
					printf("%d%c", vec[i][j], (j == vec[i].size()-1) ? '\n' : '+');
			}
		}
	}
	return 0;
}