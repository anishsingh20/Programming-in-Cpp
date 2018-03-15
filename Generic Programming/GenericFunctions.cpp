#include<iostream>


using namespace std;


//GENERIC finctions and template keyword to generate a general data type

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
