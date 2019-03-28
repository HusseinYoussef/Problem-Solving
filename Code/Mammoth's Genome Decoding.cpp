#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <numeric>
#include <iterator>

using namespace std;

typedef long long LL;
typedef unsigned int uint;

int main()
{
	int n;
	string encoded;
	int A, T, C, G,unk;
	cin >> n >> encoded;
//***********************************************************
	A = count(encoded.begin(), encoded.end(), 'A');
	G = count(encoded.begin(), encoded.end(), 'G');
	C = count(encoded.begin(), encoded.end(), 'C');
	T = count(encoded.begin(), encoded.end(), 'T');
	unk = count(encoded.begin(), encoded.end(), '?');

	if (n % 4 == 0)
	{
		if (A <= n/4 && G <= n/4 && T <= n/4 && C <= n/4)
		{
			for (int i = 0; i < n && unk != 0; ++i)
			{
				if (encoded[i] == '?')
				{
					if (A < (n / 4))
					{
						encoded[i] = 'A';
						++A;
						--unk;
					}
					else if (T < n / 4)
					{
						encoded[i] = 'T';
						++T;
						--unk;
					}
					else if (G < n / 4)
					{
						encoded[i] = 'G';
						++G;
						--unk;
					}
					else if (C < n / 4)
					{
						encoded[i] = 'C';
						++C;
						--unk;
					}
				}
			}
			cout << encoded;
		}
		else
			cout << "===";
	}

	else
	{
		cout << "===";
	}


	return 0;
}