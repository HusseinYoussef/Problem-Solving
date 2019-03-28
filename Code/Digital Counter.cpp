#include <iostream>
#include <string>

using namespace std;

int main ()
{ int coin_L,coin_R;
	string digital;
	int arr[2];

	cin >> digital;

	arr[0] = digital[0] -48;
	arr[1] = digital[1] -48;

/* Code Below consist if-else statments
    To determine number of (possible) broken sticks & possible number may appear in each digit */
//***************************************************************************
	if(arr[0] == 8)
	     coin_L = 1;
	else if(arr[0] == 7)
	      coin_L=5;
	else if(arr[0] == 6 || arr[0] == 9 || arr[0] == 0)
	      coin_L=2;
	else if(arr[0] == 3)
	      coin_L=3;
	else if(arr[0] == 4)
	      coin_L=3;
	else if(arr[0] == 1)
	      coin_L=7;
	else if(arr[0] == 2)
	      coin_L=2;
	else 
	      coin_L=4;


	if(arr[1] == 8)
	      coin_R=1;
	else if(arr[1] == 7)
	      coin_R=5;
	else if(arr[1] == 6 || arr[1] == 9 || arr[1] == 0)
	      coin_R=2;
	else if(arr[1] == 3)
	      coin_R=3;
	else if(arr[1] == 4)
	      coin_R=3;
	else if(arr[1] == 1)
	      coin_R=7;
	else if(arr[1] == 2)
	      coin_R=2;
	else 
	      coin_R=4;
//***************************************************************************	
	 
	cout << coin_R * coin_L;       // number of goods = number of coincidence of left digit * num of coincidence of right digit stick
	
return 0;
}