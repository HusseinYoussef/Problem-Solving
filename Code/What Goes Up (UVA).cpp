#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
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
#include <numeric>
#include <bitset>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
#define sc(x)              scanf("%d",&x)
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

int n;
vector<int>nums;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int num = 0;
	while (sc(num) != EOF) nums.pb(num);
	
	vector<int>seq(sz(nums),-1), LIS,idx;
	int t = 0;
	for (int i = 0; i < sz(nums); ++i)                // nlogn
	{
		auto pos = lower_bound(LIS.begin(), LIS.end(), nums[i])-LIS.begin();
		if (pos == sz(LIS)) { t = i; LIS.pb(nums[i]), idx.pb(i); }
		else
		{
			if (sz(LIS) - 1 == pos) t = i;
			LIS[pos] = nums[i];
			idx[pos] = i;
		}
		if (pos != 0)								// kol idx will store el idx ely gy mno
			seq[i] = idx[pos - 1];
		else
			seq[i] = -1;
	}

	printf("%d\n-\n", sz(LIS));

	idx.clear();
	for (int i = 0; i < sz(LIS); ++i)
	{
		idx.pb(nums[t]);
		t = seq[t];
	}

	reverse(idx.begin(), idx.end());
	for (int i = 0; i < sz(idx); ++i) printf("%d\n", idx[i]);
	return 0;
}