#include <iostream>

using namespace std;
                                                //Pipeline (Arabic CP UTube)****
int main()
{
	long long n_pipes, k_splitters;
//*****************************************
	cin >> n_pipes >> k_splitters;

	if (n_pipes == k_splitters)
	{
		cout << "1"; return 0;
	}

	else if (n_pipes == 1)
	{
		cout << "0"; return 0;
	}
	                                       // {2 3 4 5 6 7 8 9 10 11} - 9  >= n
	--n_pipes;  --k_splitters;             // {1 2 3 4 5 6 7 8 9 10} >= n-1    there is one more substracted added to rigth & left 

	if (k_splitters*(k_splitters + 1) / 2 >= n_pipes)
	{
		long long l = 1, r = k_splitters , mid;

		while (l < r)                                            // Getting the subset whose sum is <= n_pipes
		{
			mid = l + (r - l) / 2;

			if ((k_splitters - mid + 1) * (mid + k_splitters) / 2 > n_pipes)     // the sum of Sequential calculation 
				l = mid + 1;
			else
				r = mid;
		}
		long long ans = k_splitters - l + 1;
		if ((k_splitters - l + 1) * (l + k_splitters) / 2 != n_pipes)
			++ans;                                                    // if the subset sum is < n_pipes  so 1 more splitter needed
		cout << ans;
	}

	else
		cout << "-1";
	return 0;
}