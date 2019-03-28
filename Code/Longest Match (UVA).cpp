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
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

vector<string> words,chosen;
string fst, snd, s;
int LCS[510][510];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int cases = 1;
	while (getline(cin, fst))
	{
		getline(cin, snd);
	
		for (int i = 0; i < sz(fst); i++) if (!isupper(fst[i]) && !islower(fst[i]) && !isdigit(fst[i])) fst[i] = ' ';
		for (int i = 0; i < sz(snd); i++) if (!isupper(snd[i]) && !islower(snd[i]) && !isdigit(snd[i])) snd[i] = ' ';

		stringstream xx(fst);
		stringstream yy(snd);

		words.clear();
		chosen.clear();

		while (xx >> s) words.push_back(s);
		while (yy >> s) chosen.push_back(s);

		if (sz(words) == 0 || sz(chosen) == 0)
		{
			printf("%2d. Blank!\n", cases++);
			continue;
		}

		for (int j = 0; j < sz(words); ++j) LCS[0][j] = 0;
		for (int i = 0; i < sz(chosen); ++i) LCS[i][0] = 0;

		for (int i = 1; i <= sz(chosen); ++i)
		{
			for (int j = 1; j <= sz(words); ++j)
			{
				if (words[j - 1] == chosen[i - 1])
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
				else
					LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
		}

		 printf("%2d. Length of longest match: %d\n", cases++, LCS[sz(chosen)][sz(words)]);
	}
	
	return 0;
}