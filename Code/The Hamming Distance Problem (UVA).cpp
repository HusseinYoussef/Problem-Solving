#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
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
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int uint;


int datasets,N,H;
vector<string>bits;

void rec(string bitstring, int ones,int indx)
{
	if (ones == H)
	{
		bits.push_back(bitstring);
		return;
	}
	for (int i = indx; i < bitstring.size(); ++i)
	{
		if (bitstring[i] == '0')
		{
			bitstring[i] = '1';
			rec(bitstring, ones + 1, i +1);
			bitstring[i] = '0';
		}
	}
}

int main()
{
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
	scanf("%d", &datasets);

	while (datasets > 0)
	{
		--datasets;
		scanf("%d%d", &N, &H);
		bits.clear();
		string origin(N, '0');
		rec(origin, 0,0);
		for (int i = bits.size() - 1; i > -1; --i)
			cout << bits[i] <<endl;

		if(datasets != 0)
			printf("\n");
	}
	return 0;
}