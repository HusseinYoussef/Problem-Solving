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
int n, poke;
int arr[N];
string s;

bool valid(int f)
{
	int ans = 0;
	mem(arr, 0);
	for (int i = 0; i < f; ++i)         //Get first f flats
	{
		ans += (arr[s[i]] == 0);
		++arr[s[i]];
	}
	if (ans >= poke) return 1;

	for (int i = f; i < n; ++i)        // then add another flat and remove one from the first f and so on ..  ###...->> .###.. ..###.
	{                                  // will get all f flats combinations
		ans -= (arr[s[i - f]] == 1);  
		--arr[s[i - f]];
		ans += (arr[s[i]] == 0);
		++arr[s[i]];
		if (ans >= poke) return 1;
	}
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n);
	cin >> s;
	set<char>st;
	for (int i = 0; i < sz(s); ++i)
		st.insert(s[i]);
	poke = sz(st);

	int l = 1, r = n, mid;
	while (l < r)
	{
		mid = l + (r - l) / 2;
		if (valid(mid))
			r = mid;
		else
			l = mid + 1;
	}
	printf("%d", r);
	return 0;
}