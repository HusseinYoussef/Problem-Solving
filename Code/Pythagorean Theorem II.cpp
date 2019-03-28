#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c, n;
	int number = 0;
//***************************************
	cin >> n;

	for (a = 1; a < n; a++)
	{
		for (b = a; b < n; b++)
		{
			c = sqrt(a*a + b*b);                                   // the result of sqrt would be float
			if (a + b > c && c == sqrt(a*a + b*b) && c <= n)        // if c == the result of float then the result is 100% int 
				number++;                                          // no float because it is a length
		}
	}
	cout << number;
	return 0;
}