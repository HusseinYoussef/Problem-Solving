#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, k, i;
	long long arr[55];
//********************
	cin >> n >> k;

	if (k <= n)
	{
		for (i = 0; i < n; i++)
			cin >> arr[i];

		sort(arr, arr + n);                    // sorting ascendingly 

		cout << arr[n - k] << " " << "0";      // Moving only on X-axis until i reach the last point in the first wanted square
	}                                          
	else
		cout << "-1";
	return 0;
}