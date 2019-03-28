#include <iostream>

using namespace std;

int main ()
{
	int test_num,i,angle;

cin >> test_num;

for(i=0 ; i< test_num;i++)
{
	cin >> angle;
  if(360%(180-angle) == 0)        // since the sum of all exterior angles = 360
	  cout << "YES" << endl;      //  the exterior = 180 - given angle
  else 
	  cout << "NO" << endl;
}

return 0;
}