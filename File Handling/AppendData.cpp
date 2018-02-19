#include<iostream>
#include<fstream>

using namespace std;

//Program to appned data to a file and also reading and writing data to and from file using fstream


int main()
{
	fstream file("anish.txt", ios::in | ios::out | ios::app); //setting read, write and append modes of ios class
	//append will create a new file, if the file being opened does not exists
	
	if(!file.is_open())
	{
		cout<<"File not found"<<endl;
	}
	else
	{
		cout<<"Writing data to file"<<endl;
		
		//now as many time we re-run the program the below statement is goind to be appended to the file
		file << "Hi I am Anish."<<endl;
		cout<<file.tellp();
		cout<<file.tellg();
		
		
		file.close();
	}
}
