#include <iostream>

using namespace std;

int main()
{
	long long n, i;
	//*******************************
	cin >> n;

	for (i = 2; i*i <= n; i++)           // Traversing the the square root of N
	{
		if (n % i == 0)
		{
			while (n % i == 0)
			{
				n /= i;             // Excluding all i 
			}
			n *= i;                 // except 1 (added manually)
		}
	}

	cout << n;
	return 0;
}