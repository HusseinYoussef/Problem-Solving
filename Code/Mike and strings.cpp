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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, ans = INF;
	string arr[55];
	sc(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	string smpl = arr[0];
	for (int i = 0; i < sz(smpl); ++i)
	{
		int c = 0;
		for (int j = 1; j < n; ++j)
		{
			string tmp = arr[j];
			int cnt = 0,k=0;
			for (; k < sz(arr[j]); ++k)
			{
				if (smpl == tmp) break;
				else
				{
					++cnt;
					tmp += tmp[0];
					tmp.erase(0, 1);
				}
			}
			if (k == sz(smpl)) return puts("-1");
			c += cnt;
		}
		c += i;
		ans = min(ans, c);
		smpl += smpl[0];
		smpl.erase(0, 1);
	}
	printf("%d", ans);
	return 0;
}