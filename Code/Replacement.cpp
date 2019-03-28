#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, i;
	long long arr[100010];
//**************************
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);              // sorting to make sure that the last element is the largest 
	if (arr[n - 1] == 1)             // if the last element is 1 then the minimum value is 2
		arr[n - 1] = 2;
	else 
		arr[n - 1] = 1;              // otherwise the minimum value is 1
	sort(arr, arr + n);

	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}