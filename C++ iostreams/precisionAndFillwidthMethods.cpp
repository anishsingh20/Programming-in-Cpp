#include<iostream>
#include<iomanip>

using namespace std;

/*Program to demonstarte the use of precision(),width(),fill() methods belonging to ios class
1) precision() method can be used to print/display only particular sequence on a floating point number, cannot work on normal integers
*/

int main()
{
	cout.precision(4); //precision
	cout<<122.112<<endl;//outputs-122.1
	
	//width method - to fill the empty width of a character, integer or number
	
	cout.width(20);
	cout.fill('*');
	
	cout.setf(ios::left);
	
	//for output to be left justified - we can use left flag
	cout<<"Anish"<<endl;
	
	return 0; 
}
