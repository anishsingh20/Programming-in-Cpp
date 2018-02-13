#include<iostream>

using namespace std;


//using boolalpha flag to output true ot false if input is true or false
//Boolean values can be input/output using the words "true" and "false".

int main()
{
	bool boolval;
	cin.setf(ios::boolalpha);
	
	cout.setf(ios::boolalpha);
	
	cin>>boolval; //if input is true - output true
	cout<<boolval;
	
	
	return 0;
}
