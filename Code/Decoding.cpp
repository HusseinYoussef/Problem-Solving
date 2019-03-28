#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef unsigned int uint;

int main()
{
	int n;
	string encoded, decoded(""),Aux("");
//***********************************************
	cin >> n >> encoded;
	
	if (n > 2)
	{
		if (encoded.size() % 2 == 0)
		{
			decoded += encoded[0];
			decoded += encoded[1];
			encoded.erase(0, 2);
		}
		else
		{
			decoded += encoded[0];
			encoded.erase(0, 1);
		}

		int i = 1;
		while (i < encoded.size())
		{
			decoded += encoded[i];
			i = i + 2;
		}

		i = encoded.size() - 2;
		while (i >= 0)
		{
			Aux += encoded[i];
			i = i - 2;
		}
		Aux += decoded;

		cout << Aux;
	}
	else
	{
		cout << encoded;
	}
	return 0;
}