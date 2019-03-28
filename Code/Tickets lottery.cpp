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
#define EPS                 1e-9
#define pb					push_back
#define MP					make_pair
#define PI                  3.14159265
#define INF					1000000100			
#define llINF				10000000000100
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

const int maxbit = (1 << 19) + 10;

int c, k; int arr[500100];
vector<int>vec,query; int BIT[maxbit];
map<int, int>mp;

void update(int idx, int val)
{
	for (; idx < maxbit; idx += (idx&-idx))
		BIT[idx] += val;
}

int getSum(int idx)
{
	int sum = 0;
	for (; idx; idx -= (idx&-idx)) sum += BIT[idx];
	return sum;
}

//int getRangeSum(int l, int r)
//{
//	return getSum(r) - getSum(l - 1);
//}

void mapping()         // values may reach 1e9 while all numbers wont exceed 5e5  so we map them 
{
	arr[0] = -1;
	int cnt = 1;
	sort(vec.begin(), vec.end());
	for (auto i : vec) arr[cnt] = i, mp[i] = cnt++;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int t;
	sc(t);
	while (t--)
	{
		sc(c); sc(k);
		int val, mn = INF, mx = 0;
		while (c--)
		{
			sc(val);
			if (val)
				vec.pb(val);
			query.pb(val);
		}
		mapping();
		for (int i = 0; i < sz(query); ++i)
		{
			val = query[i];
			if (val) update(mp[val], 1),mn = min(mn, val), mx = max(mx, val);
			else
			{
				int l = mp[mn], r = 5e5+10, mid;
				int ans = 0;
				while (l < r)
				{
					mid = l + (r - l) / 2;
					if (getSum(mid) >= k) r = mid, ans = mid;
					else l = mid + 1;
				}
				printf("%d\n", arr[ans]);
			}
		}
		vec.clear(); query.clear(); mem(BIT, 0);
	}
	return 0;
}