#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main ()
{
	int i=0,steps,lower;
	string home,end;
	char current;
	cin >> home >> end;
     
	
	if(abs(home[0]-end[0]) > abs(home[1]-end[1]))
	 {	steps = abs(home[0]-end[0]);
	     lower = abs(home[1]-end[1]);
	 }
	else
	 {  steps = abs(home[1]-end[1]); 
	     lower = abs(home[0]-end[0]);
	   }
	
	cout << steps << endl;
	if(end[0] > home[0])                                      // Right Area
	{    
         if(end[1] > home[1])                              
		 {current = home[1] + lower;
		     for(i=0;i<steps;i++)
			   {   if(i<lower)                                // Right Up
				    { cout << "RU" << endl;
			           continue;}
			   else if(current == end[1])
				  { 
				   cout << "R" << endl;
			       }
			   else
				   cout << "U" << endl;
			    }			 
		 }
		 else if(end[1] < home[1])                            // Right Down
		 {current = abs(home[1] - lower);
		     for(i=0;i<steps;i++)
			   {   if(i<lower) 
				   {cout << "RD" << endl;
			         continue;}
                  else if(current == end[1])
				   cout << "R" << endl;
				  else 
					  cout << "D" << endl;
			    }	
		 }
		 else                                                 // Only Right
		  {
		    for(i=0;i<steps;i++)
			   cout << "R" << endl;                 
		  }    		
	}	

	else if(end[0] < home[0])                                 // Left Area
	{   
	  if(end[1] > home[1])                                    // Left Up
		 {current = home[1] + lower;
		     for(i=0;i<steps;i++)
			   {   if(i<lower)                                
				  { cout << "LU" << endl;
			          continue;}
			     else if(current == end[1])
				   cout << "L" << endl;  
				 else 
					 cout << "U" << endl;
			    }			 
		 }
		 else if(end[1] < home[1])                            // Left Down                            
		 {current = abs(home[1] - lower);
		     for(i=0;i<steps;i++)
			   {   if(i<lower) 
				  { cout << "LD" << endl;
			        continue;}
			     else if(current == end[1]) 
				   cout << "L" << endl;    
				 else 
					 cout << "D" << endl;
			    }			 
		 }
		 else                                                // Only Left
		  {
		    for(i=0;i<steps;i++)
			   cout << "L" << endl; 
   }	 }
	     
	else                                                    // Only Column
	{
	   if(end[1] > home [1])                               // Up
		   for(i=0;i<steps;i++)
	          cout << "U" << endl;
	   else                                                // Down
		   for(i=0;i<steps;i++)
			   cout << "D" << endl;   
	}
return 0;
}