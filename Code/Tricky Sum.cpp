#include <iostream>

using namespace std;

int main()
{
	int num;
	long long temp, i,j;
	long long sum;


	cin >> num;

	for (j = 0; j < num; j++)
	{
		cin >> temp;
		sum = temp*(temp + 1) / 2;       // original Sum

		for (i = 1; i <= temp; i*=2)
			sum -= 2 * i;                // Excluding 2 and its multiples

		cout << sum << endl;
	}

	return 0;
}