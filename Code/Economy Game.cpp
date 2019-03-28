#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
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
#define housep 1234567
#define carp 123456 
#define comp 1234 

using namespace std;

typedef long long ll;
typedef unsigned int uint;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
//**********************************************************
	scanf("%d", &n);	
	if (n >= 1234)
	{
		int c = 0;
		while (c * comp <= n)
		{
			int b = 0;
			while (c * comp + b * carp <= n)
			{
				if (!((n - (c * comp + b * carp)) % housep)) { printf("YES"); return 0; }
				++b;
			}
			++c;
		}
	}
	printf("NO");
	return 0;
}