                                   // Vanya and Lanterns 
                                         // All Cases Covered xD
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int lantern_num, street_length, i, j;
	double max_Diff = 0;
	int arr[1010];
	//***********************************************
	cin >> lantern_num >> street_length;

	for (i = 0; i < lantern_num; i++)
		cin >> arr[i];
	sort(arr, arr + lantern_num);

	for (i = 0; i < lantern_num - 1; i++)                  
	{                                                      
		j = i + 1;                                         //   Getting the Difference between evrey 2 lanterns places
		if (arr[j] - arr[i] > max_Diff)                    //   Getting the max difference
			max_Diff = arr[j] - arr[i];
	}

	if (arr[0] == 0 && arr[lantern_num - 1] != street_length)
	{                                                                             // Case of a lantern in the beginning
		if (street_length - arr[lantern_num - 1] > max_Diff / 2)                  // and not at the end
			printf("%.10lf", (double)(street_length - arr[lantern_num - 1]));
	}
	else if (arr[0] != 0 && arr[lantern_num - 1] == street_length)                // Case of a lantern at the end
	{                                                                             // and not in the beginning 
		if (lantern_num == 1)
			printf("%.10lf", (double)street_length);
		else if (arr[0] > max_Diff / 2)
			printf("%.10lf", (double)arr[0]);
	}
	else                                                                          // Case of no lanters at the end
	{                                                                             // or in the beginning
		if (lantern_num == 1)
			printf("%.10lf", (double)max(street_length - arr[0], arr[0]));
		else
		{
			if (max((int)max_Diff/2, street_length - arr[lantern_num - 1]) < arr[0])
				printf("%.10lf", (double)arr[0]);
			else if (street_length - arr[lantern_num-1] > max_Diff/2)
				printf("%.10lf", (double)(street_length - arr[lantern_num - 1]));
			else
				printf("%.10lf", max_Diff / 2);
		}
		
	}
	return 0;
}