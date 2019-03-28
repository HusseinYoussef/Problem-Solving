#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <stdio.h>
#include <map>
#include <unordered_map>
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
typedef vector<vector<int> > VVI;
#define sc(x)               scanf("%d",&x)
#define scl(x)              scanf("%lld",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define EPS                 1e-9
#define pb					push_back
#define MP					make_pair
#define PI                  3.14159265
#define INF					1000000100			
#define llINF				10000000000100
#define WHITE 0
#define GRAY 1
#define BLACK 2
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
ll inline max3(ll a, ll b, ll c) { return max(a, max(b, c)); }
ll inline min3(ll a, ll b, ll c) { return min(a, min(b, c)); }
ll power(ll x, ll p) { if (p == 0) return 1; else if (p % 2 == 0) return power(1LL * x*x, p / 2); else return 1LL * x*power(1LL * x*x, (p - 1) / 2); }
ll GCD(ll a, ll b) { if (b == 0) return a; return GCD(b, a%b); }

int s, x1, x2, t1, t2, p, d;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;

	if (t2 <= t1) printf("%d", abs(x1 - x2)*t2); // if igor is faster than the Tram
	else
	{
		int tmp;
		if (d == 1 && x1 >= p || d == -1 && x1 <= p)
		{
			tmp = abs(x1 - p)*t1;
			if (x2 < x1 && d == 1) tmp += abs(x1 - s)*t1*2;
			else if(x2 > x1 && d == -1) tmp += abs(x1 - 0)*t1 * 2;
		}
		else if (d == 1)
		{
			tmp = abs(x1 - p)*t1 + abs(s - p)*t1*2;
			if (x2 > x1)
			{
				tmp += x1*t1*2;
			}
		}
		else if (d == -1)
		{
			tmp = abs(x1 - p)*t1 + abs(0 - p)*t1*2;
			if (x2 < x1) tmp += abs(x1 - s)*t1*2;
		}
		printf("%d", min(abs(x1 - x2)*t2, tmp+ abs(x1 - x2)*t1));   // else the minimum between time taken by foot and time taken by Tram 
	}                                                               // to reach X1 then X2
	return 0;
}


//In the other case we need to use the following hint : the time of arrive does not depend on how much Igor walk before enter the tram,
//if the tram will reach the finish point faster than Igor.So Igor can wait the tram in the point x1.