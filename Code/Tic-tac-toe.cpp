#include <iostream>

using namespace std;
void the_winner(char ,char , char ,int &,int &);

int main()
{ int rows,columns,i;
  int complete_X=0,complete_O=0;
  int num_X=0,num_O=0,period=9;
	char arr [3][3];                               // 2D Array to represent 3 x 3 grid

	for(rows=0;rows<3;rows++)
	  {	for(columns=0;columns<3;columns++)
		 {	cin >> arr[rows][columns];
	       if(arr[rows][columns] == 'X')
			  { num_X++;
		         period--; }
		   else if(arr[rows][columns] == '0')
		   {   num_O++;		   
		       period--;}
		  }
      }
     	
	for(i=0;i<3;i++)
	{  the_winner(arr[i][0],arr[i][1],arr[i][2],complete_X,complete_O);     // checking if there is complete rows
	   the_winner(arr[0][i],arr[1][i],arr[2][i],complete_X,complete_O);     // checking if there is complete columns
	}

	the_winner(arr[0][0],arr[1][1],arr[2][2],complete_X,complete_O);         // checking if there is complete diagonal
	the_winner(arr[0][2],arr[1][1],arr[2][0],complete_X,complete_O);         // checking if there is complete diagonal
	

	if(num_X == num_O+1 && complete_X !=0 && complete_O == 0 && period >=0)
		cout << "the first player won";
	else if(num_X == num_O && complete_X ==0 && complete_O !=0 && period >=0)
		cout << "the second player won";
	else if(num_X == num_O && complete_O == 0 && complete_X == 0 && period != 0)
		cout << "first";
	else if(num_X == num_O +1 && complete_O == 0 && complete_X== 0 && period != 0)
		cout << "second";
	else if( num_X ==5 && complete_O == 0 && complete_X == 0 && period == 0)
		cout << "draw";
	else 
	cout << "illegal";
	return 0;
}

void the_winner(char a,char b , char c,int &Xs,int &Os)
{ 
	if( a == b &&  a == c && a == 'X' )
       Xs++;
	else if(a == b && a == c && a == '0')
		Os++;

}