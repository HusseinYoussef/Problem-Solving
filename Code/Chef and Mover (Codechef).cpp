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
typedef vector<vector<int> > VVI;
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
#define WHITE 0
#define GRAY 1
#define BLACK 2
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int inline max3(int a, int b, int c) { return max(a, max(b, c)); }

const int N = 1e5 + 10;
int n, D;
ll arr[N];

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
	{
		ll sum = 0, cnt = 0;        // since each move increases an element by 1 and decreases another by 1  then the total sum will never change
		sc(n); sc(D);              // and since at the end all elements are equal and i have total sum then i can get that unique element
		for (int i = 0; i < n; ++i)sc(arr[i]), sum += arr[i];

		if (sum % n != 0) { puts("-1"); continue; }   // if sum % n != 0  then can't divide the sum on the array , all elements can't be equal

		sum /= n; bool ok = 1;
		for (int i = 0; i < n - D; ++i)
		{
			if (arr[i] < sum)
			{
				cnt += (sum - arr[i]);
				arr[i + D] -= (sum - arr[i]);
				arr[i] = sum;
			}
			else if (arr[i] > sum)
			{
				cnt += (arr[i] - sum);
				arr[i + D] += (arr[i] - sum);
				arr[i] = sum;
			}
		}
		for (int i = n-D; i < n; ++i)if (arr[i] != sum) { ok = 0; break; }
		if (ok)cout << cnt << endl;
		else puts("-1");
	}
	return 0;
}