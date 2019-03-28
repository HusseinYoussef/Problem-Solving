#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <numeric>
#include <iomanip>
#include <iterator>

using namespace std;

typedef long long ll;
typedef unsigned int uint;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string input, temp;
	vector<int> vec;
	//************************************************************
	cin >> input;
	for (int i = 0; i < 125; ++i)
	{
		int part = i * 8, n = 0;
		stringstream s; string t;
		s << part; s >> t;
		vec.clear(); temp = input;
		for (int j = 0; j < t.length(); ++j)
		{
			int indx = temp.find(t[j]);
			if (indx != -1) { vec.push_back(indx); temp[indx] = 't'; }
			else break;
		}
		if (vec.size() == t.length() && is_sorted(vec.begin(), vec.end()))
		{
			printf("YES\n%d", part); return 0;
		}
	}
	printf("NO");
	return 0;
}