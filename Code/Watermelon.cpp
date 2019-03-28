#include <iostream>
#include <string>

using namespace std;

int main()
{
  int weight ;
  cin>>weight;
  if(weight>=1 && weight<=100)
   {    
     if(weight % 2 == 0 && weight !=2)
	    cout<<"YES";
     else
	     cout<<"NO";
    }
return 0;
}