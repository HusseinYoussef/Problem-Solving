#include <iostream>
#include <string>

using namespace std;
 
int main ()
{  int N,M,i;
   int Domino_row=0,Domino_coulmn=0,Num=0;
    cin>>M>>N;                                   // Domino is 2 x 1 (Fixed)
	if(M>=1 && N>=M && N<=16)
	 {    
		 if(M>1)
	     {
	        Domino_row = N;
			if(M % 2 ==0)
             {  Domino_coulmn = M / 2 - 1;
			    Num = Domino_coulmn*N; }
			else 
			  {	Domino_coulmn = M / 2 - 1;
			    Num = Domino_coulmn*N; 
			  for(i=1;i<N;i+=2)
				  Num++;
               	} 

          }

	     else
			 for(i=1;i<N;i+=2)
				  Num++;
	  }	  

	cout << Num+Domino_row << endl;
 return 0;
}