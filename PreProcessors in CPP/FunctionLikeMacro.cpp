#include<iostream>

using namespace std;


//macro which finds the greater of 2 numbers
#define MAX(a,b) ((a<b) ? b:a)

//FUNCTION LIKE MACROS-which can take arguments just like a function


int main()
{
	cout<<MAX(10,20);
	return 0;
}
