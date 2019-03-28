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
#define sc(x)           scanf("%d",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define EPS                             1e-9
#define pb					push_back
#define MP					make_pair
#define INF					1000000100			
#define llINF				10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	int n;
	int arr[100010];
	sc(n);
	for (int i = 0; i < n; ++i) sc(arr[i]);
	printf("%d %d\n", abs(arr[0] - arr[1]), abs(arr[0] - arr[n - 1]));
	for (int i = 1; i < n - 1; ++i) printf("%d %d\n", min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1])), max(abs(arr[i] - arr[0]), abs(arr[i] - arr[n - 1])));
	printf("%d %d\n", abs(arr[n - 1] - arr[n - 2]), abs(arr[n - 1] - arr[0]));
	return 0;
}