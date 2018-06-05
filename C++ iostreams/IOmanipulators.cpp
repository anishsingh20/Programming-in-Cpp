#include<iostream>
#include<iomanip>


using namespace std;

/*Program to demonstrate various manipulators of input and output streams
Most general use of manipulator to manipulate or modify output stream is endl 
Other examples include hex,oct,dec, setw(),setfill() , setprecision() etc
*/

int main()
{
	
	cout<< setw(10) << setfill('#') << setprecision(4) << oct << 100.3344;
	return 0;
}


