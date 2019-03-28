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
int inline max3(int a, int b, int c) { return max(a, max(b, c)); }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int n; ll ab, a, b;  // at first a = b = ab = 1
	sc(n);              // each round  ab is multiplied by k^3   at the end  ab = S^3 when S = k1 * k2 * k3 ..  so S must be an integer
	while (n--)         //so  (a/s) * (b/s) = s     if these conditions were satisfied  the answer is "YES"
	{
		scl(a); scl(b);
		ab = a * 1LL * b;
		int l = 1, r = 1e6, mid;
		while (l < r) // cube root using BS
		{
			mid = l + (r - l + 1) / 2;
			if (1LL * mid * mid * mid <= ab) l = mid;
			else r = mid - 1;
		}
		if (1LL * r * r * r == ab && a % r == 0 && b % r == 0) puts("YES");
		else puts("NO");
	}
	return 0;
}


/*
O(1) solution: Find . If it's not an integer, return NO.Otherwise, if s divides both a and b, return YES, otherwise return NO.
(Cube root can be found by binary search, for example.)
To prove that this works,
note that ab must be a cube, since every round it is multiplied by k^3 for some k. Moreover, if we set ab = s^3, then the product of all k played in the game is s.
Thus we need to have both a and b divisible by s, since they are the product of all k played in the game,
plus probably some more numbers. And this is all we need;
if ab = s3, let a = sx and b = sy, so we see xy = s. Thus a = x2y, b = xy2,
so one possible game is a winning a game with k = x and b winning a game with k = y.
*/