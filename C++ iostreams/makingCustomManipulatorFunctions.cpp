#include<iostream>
#include<iomanip>

/*program to demonstrate how to build custom manipulator functions
a) these functions can be of 2 types -  one with a parameter like setw(),setprecision() etc
b) other manipulator methods can be without any parameter like hex, dec , endl

NOTE-
Manipulator functions should return either reference to ostream class object os istream class and should take a default argument which is passed by reference of type
ostream or istream class like demonstrated below
*/
using namespace std;


ostream& print(ostream &output)
{
	output<<"Hex  value is:" << hex ;
//	output<<"Octal value is: "<< oct<<endl;
//	output<<"decimal value is: "<<dec<<endl;
	
	return output;
}



istream& input(istream &input)
{
	
	
	cout<<"Enter the data:"<<endl;
	
	return input;
}


int main()
{
	int x;
	

	cin>>input>>x;
	
	
	cout<<print<<x;

	return 0;
}
