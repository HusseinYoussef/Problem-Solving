#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef unsigned int uint;

int main()
{
	int n_students, m_places, Q_commands,cnt_coveredplaces = 0;
	map<int, int>mp;
	vector<int>vec;
//***********************************************************
	scanf(" %d %d %d", &n_students, &m_places, &Q_commands);
	vec.resize(n_students + 1);

	for (int i = 1; i <= n_students; ++i)
	{
		scanf(" %d", &vec[i]);
		++mp[vec[i]];
	}

	cnt_coveredplaces = mp.size();
	
	for (int i = 0; i < Q_commands; ++i)
	{
		int kid, target;
		scanf(" %d %d", &kid, &target);

		if (mp[target] == 0)
			++cnt_coveredplaces;
		if (mp[vec[kid]] == 1)
			--cnt_coveredplaces;

		++mp[target];
		--mp[vec[kid]];
		vec[kid] = target;            //** Changing the current location
		printf("%d\n", m_places - cnt_coveredplaces);
	}
	return 0;
}