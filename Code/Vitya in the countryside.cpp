#include <iostream>
#include <string>

using namespace std;

int main ()
{
	int n,i;
	int arr[100];
	cin >> n;

	for(i=0;i<n;i++)
	  cin >> arr[i];

	if(arr[i-1] == 15)
		cout << "DOWN";
	else if(arr[i-1] == 0)
		cout << "UP";
	else if(arr[i-1] < arr[i-2] && n>1)
		cout << "DOWN";

	else if(arr[i-1] > arr[i-2] && n>1)
	 cout << "UP";

	else
		cout << "-1";
	
return 0;
}