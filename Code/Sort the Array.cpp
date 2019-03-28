#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
	int array_size, i, segment = 0, seg_start = 1;
	long long arr[100010];
	vector <int>vec;
	//**************************************

	cin >> array_size;

	for (i = 0; i < array_size; i++)
		cin >> arr[i];
	for (i = 0; i < array_size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			if (segment == 0) seg_start = i + 1;
			if ((arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) || segment == 0)
				segment++;
		}

		if (arr[i] > arr[i + 1])
		{
			vec.push_back(arr[i]);
			if (i == array_size - 2 || arr[i + 2] > vec[0])
			{
				vec.push_back(arr[i + 1]);
			}
			else if (arr[i + 2] < vec[0] && arr[i + 2] > arr[i + 1])
			{
				cout << "no";
				return 0;
			}
		}
	}
	if (segment > 1)                       // if Segments are > 1 means there should be more than one segment (only 1 is allowed )
		cout << "no";
	else if (seg_start == 1 || vec[vec.size() - 1] > arr[seg_start - 2])        //  comparing the last element in the vector with
		printf("yes\n%d %d", seg_start, (vec.size() == 0) ? seg_start : vec.size() + seg_start - 1); // the element before the segment that should be smaller when reversed
	else
		printf("no");
	return 0;	
}