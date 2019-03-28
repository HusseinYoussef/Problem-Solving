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
int n;
int arr[N];

ll GCD(ll a, ll b)
{
	if (b == 0) return a;
	return GCD(b, a%b);
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
	{                             //Assume plate size 1 then the min cost will be the sum of the array
		sc(n);                    // greater plates will produce greater or equal cost
		ll sum = 0, ans;          // to make every one have exactly x food  we get the GCD for the array   the value that will divide the whole array
		for (int i = 0; i < n; ++i) { sc(arr[i]); sum += arr[i]; }

		ans = arr[0];
		for (int i = 1; i < n; ++i) 
			ans = GCD(max(ans, (ll)arr[i]), min((ll)arr[i], ans));

		printf("%I64d %I64d\n", sum, ans);
	}
	return 0;
}