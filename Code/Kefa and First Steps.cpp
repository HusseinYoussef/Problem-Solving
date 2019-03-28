#include <iostream>

using namespace std;

int main()
{
	int days_num,i,segment_len=0,maxy=0;
	long long arr[100100];
//******************************
	cin >> days_num;

	for (i = 0; i < days_num; i++)
		cin >> arr[i];
	

	for (i = 0; i < days_num - 1; i++)
	{
		if (arr[i + 1] >= arr[i])                        // comparing the current number with the next
			segment_len++;
		else
			segment_len= 0;
		
		if (segment_len > maxy)
			maxy = segment_len;
	}

	cout << maxy+1;
	return 0;
}