#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int coins_num, i, my_sum = 0, total_sum = 0,min_coins=0;
	int arr[101];
//************************************************
	cin >> coins_num;

	for (i = 0; i < coins_num; i++)
	{
		cin >> arr[i];
		total_sum += arr[i];
	}

	sort(arr, arr + coins_num);                   // sorting the array to be ble to get the highest values quickly

	i = 1;
	while (true)
	{
		my_sum += arr[coins_num - i];
		min_coins++;

		if (my_sum > total_sum - my_sum)
			break;
	 i++;
	}

	cout << min_coins;
	return 0;
}