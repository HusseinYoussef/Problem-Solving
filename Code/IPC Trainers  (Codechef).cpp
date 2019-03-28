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
#define PI                  3.14159265
#define INF					1000000100			
#define llINF				10000000000100
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

const int N = 1e5 + 5;
int n, d;
int D, T, S;
pair<int, pair<int, int>> arr[N];

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
		sc(n); sc(d);

		ll ans = 0;
		for (int i = 0; i < n; ++i)
		{
			sc(D); sc(T); sc(S);
			ans += (S*1LL*T);
			arr[i] = { D,{T,S} };
		}
		sort(arr, arr + n);
		priority_queue<pair<int, int>>pq;

		int days = 1;
		for (int i = 0; i < n; ++i)
		{
			pair<int, int> ex, tst;
			ex.first = arr[i].second.second;
			ex.second = arr[i].second.first;
			if (days > d) break;
			if (arr[i].first == days)
				pq.push(ex);
			else
			{
				if (!pq.empty())
				{
					ans -= pq.top().first;
					tst = pq.top();
					pq.pop();
					if (tst.second != 1)
					{
						--tst.second;
						pq.push(tst);
					}
				}
				++days;
				if (arr[i].first == days)pq.push(ex);
				else --i;
			}
		}
		while (days <= d)
		{
			pair<int, int>tst;
			ans -= pq.top().first;
			tst = pq.top();
			pq.pop();
			if (tst.second != 1)
			{
				--tst.second;
				pq.push(tst);
			}
			++days;
		}
		cout << ans << endl;
	}
	return 0;
}