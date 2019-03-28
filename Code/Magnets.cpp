#include <iostream>

using namespace std;

int main()
{
	int n,i,groups_num=1;                  // Groups num started with 1 

	cin >> n;
int* arr = new int[n];

for(i=0;i<n;i++)
{	cin >> arr[i];

    if(i>0)
   	 { if(arr[i] != arr[i-1])             // comparing each element with the previous one
	   groups_num++; }  	
}

 cout << groups_num;

 delete []arr;
 return 0;
}