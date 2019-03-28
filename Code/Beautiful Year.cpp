#include <iostream>
#include <string>

using namespace std;

int main ()
{ int i,j,distinct_num;  
  bool distinc_exist,exit=true ;
  string year;
  int arr[4];

	cin >> year;                      // taking the year as a string (array of chars each index has 1 number)

	arr[0]=year[0]-48;        
	arr[1]=year[1]-48;                     // putting each number in 1 index in a new array
	arr[2]=year[2]-48;                      
	arr[3]=year[3]-48;

while(exit)
{  distinct_num=0;                  // <<<<<< Reintialize to 0 to avoid infinie loop
                                    // exits only when Distinct number is 4
	if(arr[3] < 9)
		arr[3]++;
	else
	{  arr[3] = 0;
	  
	    if(arr[2] < 9)
			arr[2]++;
		else
		{  arr[2] = 0;

             if(arr[1] < 9)
				 arr[1]++;
			 else
			 {
				 arr[1]=0;
				 if(arr[0] < 9)
					 arr[0]++;
			 }
		}
	}

	
	for(i=0 ; i<year.length();i++)                                   
	{   distinc_exist = false;

	     for(j=i+1; j<year.length();j++)
		 {
		    if(arr[i]==arr[j])
			{ distinc_exist = false;
			  break;
		    }                                                         // Nested loops to get the Distinct number
		   
			else
			{
				distinc_exist = true;
				if(i ==2 && arr[2] != arr[1] && arr[1] != arr[0])
				distinct_num++;
			}
		 } 
	  
	  if(distinc_exist)
		  distinct_num++;	
	}                                                                  

 if(distinct_num == 4)
  exit=false;
}
if(distinct_num == 4)
	{ for(i=0 ; i<4 ; i++)
	   cout <<arr[i];
	}
	else
		cout<< "error "<< distinct_num<<endl;


return 0;
}