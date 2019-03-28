#include <iostream>
#include <string>

using namespace std;

int main()
{
   int n,i;
   string wordy;
    cin>>n;
	i=0;
 
  do
  {
     cin>>wordy;
	  cout<<endl;
     if(wordy.length()>10)
	  cout<<wordy.at(0)<<wordy.length()-2<<wordy.at(wordy.length()-1)<<endl;
	 else
		 cout<<wordy<<endl;
	 i++;
   }while(i<n);
 

return 0;
}