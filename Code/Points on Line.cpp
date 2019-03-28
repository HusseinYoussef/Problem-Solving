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
#define EPS                           1e-9
#define pb					push_back
#define MP					make_pair
#define INF					1000000100			
#define llINF				10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int n, d;
int arr[100005];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	sc(n); sc(d);
	for (int i = 0; i < n; ++i)sc(arr[i]);

	ll cnt = 0;
	for (int i = 0; i < n - 2; ++i)
	{
		ll l = i + 2, r = n - 1, mid;
		if (arr[i + 2] - arr[i] <= d)
		{
			while (l < r)
			{
				mid = l + (r - l + 1) / 2;              // TTTTFFFF
				if (arr[mid] - arr[i] <= d)
					l = mid;
				else
					r = mid - 1;
			}
			int c = r - i;							 //  then getting number of possible Combinations
			ll com = 1ll * c * (c - 1) / 2; //  the last true - the current i = the elements in between and the last true which contains the combinations
			cnt += com;			//range C 2
		}
	}
	printf("%I64d", cnt);
	return 0;
}