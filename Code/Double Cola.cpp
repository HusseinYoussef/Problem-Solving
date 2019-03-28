#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
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
#define sc(x)           scanf("%d",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define EPS                             1e-9
#define pb					push_back
#define MP					make_pair
#define INF					1000000100			
#define llINF					10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	string arr[5] = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };

	int n,per = 0;
	cin >> n;
	int k = n;
	int i;
	for (i = 1; n - i * 5 > 0; i *= 2) n -= i * 5;
	int cnt = 0;
	for (int j = k - n+1; j <= k; ++j)
	{
		if (cnt == i) { ++per, cnt = 0; }
		++cnt;
	}
	cout << arr[per];
	/*cout << arr[(n - 1) / i];*/          // better solution  no need for the second loop
	return 0;
}