#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long n;
	int i;
	vector<long long>vec;
//****************************
	cin >> n;

	for (i = 0; i < n; i++)
	{
		long long num;
		cin >> num;

		if (num % 2 == 0)
		{
			while (num % 2 == 0)
			{
				num /= 2;          // Excluding all 2 prime factors of each number
			}
		}

		if (num % 3 == 0)
		{
			while (num % 3 == 0)
			{
				num /= 3;          // Excluding all 3 prime factors of each number
			}
		}

		vec.push_back(num);        // and storing them in a vector
	}
	sort(vec.begin(), vec.end());        // sort in case of "No" there will be change in numbers  (max & min)
	if (vec[0] == vec[n - 1]) cout << "Yes";
	else cout << "No";
	return 0;
}