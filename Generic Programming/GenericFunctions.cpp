#include<iostream>


using namespace std;


/*GENERIC finctions and template keyword to generate a general data type-
Generic functions are functions which can operate on any type of data as argument which is passed at compile time.
And to make a generic data type in cpp we use templates
*/


//making a generic data type T
template<typename T>

void display(T x)
{
	cout<<x<<endl;
}

int main()
{
	display(20);

	display("Anish singh walia");
	display(20.335);	
}
