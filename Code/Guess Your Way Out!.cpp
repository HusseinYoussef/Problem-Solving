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

int h; ll E;

ll pw(ll x, int n)
{
	if (n == 0) return 1;

	else if (n % 2 == 0)
		return pw(x*x, n / 2);
	else
		return x * pw(x*x, (n - 1) / 2);
}

ll nds(int he)  //count the nodes in subtree with height he
{
	ll ans = 0;

	while (he >= 0)
	{
		ans += pw(2, he);
		--he;
	}
	return ans;
}

ll rec(bool op, int he, ll tr)              // 0 -> left .. 1 -> Right
{
	if (he == 0) return 0;

	ll cnt = pw(2, he);
	bool dir = (tr > (cnt / 2)) ? 1 : 0;         // if the target in the right subtree the whole left subtree will be visited

	if (dir == op)        //+1 for the root node
	{
		return 1 + rec(!op, he - 1, (dir) ? tr - (cnt / 2) : tr);
	}
	else // here will go to the correct dir   and visit all the left subtree at once
	{
		return 1 + nds(he - 1) + rec(op, he - 1, (dir) ? tr - (cnt / 2) : tr);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(h); scl(E);

	printf("%I64d", rec(0, h, E));
	return 0;
}