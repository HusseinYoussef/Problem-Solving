#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int k2, k3, k5, k6;
	int mini, sum = 0,i;
//************************
	cin >> k2 >> k3 >> k5 >> k6;

	if (k2 <= min(k5, k6))
		mini = k2;
	else if (k5 <= min(k6, k2))
		mini = k5;
	else
		mini = k6;

	for (i = 0; i < mini; i++)
		sum += 256;

	if (k2 - mini > 0)
		for (i = 0; i < min(k3, k2 - mini); i++)
			sum += 32;

	cout << sum;
	return 0;
}