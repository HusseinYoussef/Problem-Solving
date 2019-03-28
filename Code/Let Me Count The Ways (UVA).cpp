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
#define sc(x)            scanf("%d",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define EPS                            1e-9
#define pb					push_back
#define MP					make_pair
#define INF					1000000100			
#define llINF				10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int pocket;
int change[] = { 1,5,10,25,50 };
ll dp[8][30002];

ll solve(int idx, int sum)
{
	if (sum == 0) return 1;
	if (idx == 5 || sum < 0)return 0;

	ll &ret = dp[idx][sum];
	if (~ret) return ret;

	return ret = solve(idx + 1, sum) + solve(idx, sum - change[idx]);    

}

int main()
{
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
	mem(dp, -1);                // No need to do more than one memset
	while (cin >> pocket)
	{	
		ll ans = solve(0, pocket);

		if(ans != 1) printf("There are %lld ways to produce %d cents change.\n", ans, pocket);
		else printf("There is only 1 way to produce %d cents change.\n", pocket);
	}
	return 0;
}