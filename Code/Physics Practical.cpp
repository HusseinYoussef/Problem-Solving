#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	int n, ans=100010;
	int arr[100010];
//************************
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;

	int i;
	for (i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);

	for (i = 0; i < n-1; ++i)
	{
		int l = i, r = n - 1, mid;
		while (l < r)
		{
			mid = l + (r - l + 1) / 2;

			if (arr[mid] <= 2 * arr[i])           // TTTTFFFF    | another solution FFFFTTTTT
				l = mid;
			else
				r = mid - 1;
		}
		ans = min(ans, n - r - 1 + i);
	}
	cout << ans;
	return 0;
}