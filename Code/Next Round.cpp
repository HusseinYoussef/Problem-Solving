#include <iostream>
#include <string>

using namespace std;

int main()
{
   int n,k,i,counter=0;
    cin>>n>>k;
	cout<<endl;
	int score[n];

	if(n>=k)
	 {  for(i=0;i<n;i++)
			cin>>score[i];
	  } 
	cout<<endl;

	for(i=0;i<n;i++)
	   {	if(score[i]>=score[k-1] && score[i] > 0)        // the k-th player in the 4th position in the array
 			counter++;
	      }
	cout<<counter;
return 0;
}