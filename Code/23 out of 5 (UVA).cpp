#include <iostream>
#include <algorithm>

using namespace std;
int arr[5];
bool found;
bool Rec(int i, int sum)
{
	if (i == 5)
		return sum == 23;

	return Rec(i + 1, sum + arr[i]) || Rec(i + 1, sum - arr[i]) || Rec(i + 1, sum * arr[i]);
}
int main()
{
	while (true)
	{
		for (int i = 0; i < 5; ++i)
			cin >> arr[i];

		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0 && arr[3] == 0 && arr[4] == 0)
			break;

		sort(arr, arr + 5);
		found = false;
		do
		{
			if (Rec(1, arr[0]))
			{
				found = true;
				break;
			}
		} while (next_permutation(arr, arr + 5));

		if (found)
			cout << "Possible\n";
		else
			cout << "Impossible\n";

	}
	return 0;
}