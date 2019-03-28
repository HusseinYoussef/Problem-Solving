#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int a, b, c;
	int i, j, k;
	long long sum = 0;
//************************************
	cin >> a >> b >> c;
	vector<int>vec(a*b*c + 1, 0);         // Initialized with 0
	for (i = 1; i <= a*b*c; i++)
	{
		for (j = i; j <= a*b*c; j += i)
		{
			vec[j]++;                     // Each index (number) will contain its divisors
		}
	}

	for (i = 1; i <= a; i++)
	{
		for (j = 1; j <= b; j++)
		{
			for (k = 1; k <= c; k++)
			{
				sum += vec[i*j*k];        // Adding the [i*j*k] divisors to the sum
			}
		}
	}

	cout << sum;

	return 0;
}