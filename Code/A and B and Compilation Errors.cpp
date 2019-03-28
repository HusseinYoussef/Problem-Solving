#include <iostream>
#include <map>

using namespace std;

int main()
{   
	int error_num, i, error1, error2;
	int arr1[100010];
	int arr2[100010];
	map<int, int>mainmp;
	map<int, int>checkmp;
//******************************
	cin >> error_num;

	for (i = 0; i < error_num; i++)
	{
		cin >> arr1[i];
		mainmp[arr1[i]]++;
	}

	for (i = 0; i < error_num-1; i++)
	{
		cin >> arr2[i];
		checkmp[arr2[i]]++;
	}

	for (i = 0; i < error_num; i++)
		if (checkmp[arr1[i]] != mainmp[arr1[i]])
			error1 = arr1[i];

	mainmp.clear();
	for (i = 0; i < error_num - 2; i++)
	{
		cin >> arr1[i];
		mainmp[arr1[i]]++;
	}

	for (i = 0; i < error_num-1; i++)
		if (checkmp[arr2[i]] != mainmp[arr2[i]])
			error2 = arr2[i];

	cout << error1 << endl << error2;
	return 0;
}