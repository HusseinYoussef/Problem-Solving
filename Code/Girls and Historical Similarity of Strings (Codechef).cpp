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


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int t;
	string P, Q;
	sc(t);
	while (t--)
	{
		cin >> P >> Q;                       // IDEA ->>  number of chars must be equal  and for each char in string p  
		set<char>stp, stq;                   //  there is only one type char in string Q 
		                                     //  aab bba (Right)  | abb bba  (Wrong)  same # of chars but b char in string P
		for (int i = 0; i < sz(P); ++i)      //  maps to different chars in Q  (a & b)
			stp.insert(P[i]), stq.insert(Q[i]);
		
		bool f = 1;
		if (sz(stp) == sz(stq))
		{
			set<char>::iterator it;

			for (it = stp.begin(); it != stp.end(); ++it)
			{
				int cnt = 0; char lst = '#';
				for (int i = 0; i < sz(P); ++i)
				{
					if (P[i] == *it)
					{
						if(Q[i] != lst)
						{
							++cnt;
							lst = Q[i];
						}
					}
				}
				if (cnt > 1) { f = 0; break; }
			}
		}
		else f = 0;

		(f) ? puts("YES") : puts("NO");
	}
	return 0;
}