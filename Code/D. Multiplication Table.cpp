#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef unsigned int uint;

int main()
{
	LL n, m;
	LL k;
//***************
	cin >> n >> m >> k;

	LL l = 1, r = n*m, mid;

	while (l < r)
	{  
		mid = l + (r - l) / 2;
		LL sum = 0;

		for (int i = 1; i <= n; ++i)
			sum += min((mid / i), m*1LL);         

		if (sum >= k)
			r = mid;
		else
			l = mid + 1;
	}

	cout << r;
	return 0;
}