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
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

const int N = 1e5 + 5;
int n;
int arr[N];
int ans[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n);
	for (int i = 0; i < n; ++i)sc(arr[i]);
	
	stack<pair<int,int>>st;               //Algorithm : NGE (Next Greater Element)   Geeks4Geeks
	st.push({ arr[0],0 });

	for (int i = 1; i < n; ++i)
	{
		int next = arr[i];
		int element = st.top().first;
		int idx = st.top().second;

		while (element < next)
		{
			ans[idx] = next;
			st.pop();
			if (st.empty())break;
			element = st.top().first;
			idx = st.top().second;
		}

		st.push({ next,i });
	}

	while (!st.empty())
	{
		int t = st.top().second;
		st.pop();
		ans[t] = -1;
	}
	for (int i = 0; i < n; ++i)printf("%d ", ans[i]);
	return 0;
}