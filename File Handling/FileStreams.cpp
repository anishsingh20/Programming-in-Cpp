#include<iostream>
#include<fstream>

//Program on File handling and opening and closing connections to a file stream
using namespace std;


int main()
{
	//creating an object of class fstream to read or write to a file
	fstream file;
	file.open("anish.txt",ios::in | ios::out | ios::trunc);
	
/*trunc is used in case if a file is not already existing, then it will create a new file for us, but if the file is already existing then
it will simply remove the contents of the file, and create a new copy
*/	

	if(!file.is_open())
	{
		cout<<"Error!, file not opened"<<endl;
	}
	else
	{
		cout<<"File successfully opened"<<endl;
		
		//closing the connection to the file using .close() method
		file.close();
	}
	
	
	return 0;
}
