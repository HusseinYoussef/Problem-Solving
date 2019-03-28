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

int freq[26];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	string s;
	cin >> s;
	int maxi = -1;
	for (int i = 0; i < sz(s); ++i)
	{
		++freq[s[i] - 'a'];
		maxi = max(maxi, freq[s[i] - 'a']);
	}
	ll cst = INF;
	int ans = 0;
	for (int x = 2; x <= maxi + 1; ++x)          //when x is larger than the freq the results will repeat so we go to (max freq) + 1
	{
		ll sum = 0;
		for (int i = 0; i < 26; ++i)
		{
			sum += (long long)(freq[i] % x)*freq[i];
		}

		if (sum < cst)
		{
			cst = sum;
			ans = x;
			if (sum == 0)break;
		}
	}
	printf("%d", ans);
	return 0;
}