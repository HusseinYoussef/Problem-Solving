#include <iostream>

using namespace std;

int main()
{
	int rows_columns,i;
	long long value,divisors = 0;
//*****************************************
	cin >> rows_columns >> value;

	if (rows_columns < value)
	i = 2;
	else
	i = 1;

	for (i; i <= rows_columns; i++)
	{
		if (value % i == 0 && value / i <= rows_columns)
			divisors++;
	}

	cout << divisors;
	return 0;
}