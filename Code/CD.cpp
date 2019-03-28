#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned int uint;

int N, tracks, sum = 0;
int track[30];
vector<int> cd;
int sz = 0, total = 0;

void stereo(vector<int> vec,int sum,int i)
{
	if (i == tracks)
		return;

	for (int j = i; j < tracks; ++j)
	{
		if (sum + track[j] <= N)
		{
			vec.push_back(track[j]);
			if (sum + track[j] > total)
			{
				total = sum + track[j];
				cd = vec;
				sz = vec.size();
			}

			else if (vec.size() > sz && sum + track[j] == total)
				cd = vec;

			stereo(vec, sum + track[j], j + 1);
			vec.pop_back();
		}
	}
}
int main()
{
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
	while (cin >> N)
	{
		scanf(" %d", &tracks);

		for (int i = 0; i < tracks; ++i)
			cin >> track[i];
		
		vector<int>trial;
		
		stereo(trial, 0, 0);

		for (int i = 0; i < cd.size(); ++i)
			printf("%d ", cd[i]);
		
		printf("sum:%d\n", total);
		cd.clear(); total = 0; sz = 0; sum = 0;
	}
	return 0;
}