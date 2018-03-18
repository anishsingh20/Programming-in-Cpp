#include<iostream>

using namespace std;

//Reference in C++-function which take argument as a reference

int f(int &x,int c)
{
	c = c-1;
	if(c==0) return 1;
	
	x = x+1;
	cout<<x<<" "<<c<<endl;
	
	return x*f(x,c);
}

/*explanation
	
	f(5,5) = 3024 is answer
	   |
	f(6,4)*6 = 9*8*7*6
	   |
	f(7,3)*7 = 9*8*7
	   |
	f(8,2)*8 = 9*8
	  |
	f(9,1)*9 =  1*9
	  |
	  1(base condition reached-leaf node of recursion tree)
	
	
	
*/
int main()
{
	int x = 5;
	cout<<f(x,x); //outputs 3024
	
	
}
