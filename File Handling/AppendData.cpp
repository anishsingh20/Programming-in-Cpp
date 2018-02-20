#include<iostream>
#include<fstream>
#include<iomanip>

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
		file << "Hi I am Anish Singh Walia."<<endl;
		cout<<file.tellp()<<endl;
		cout<<file.tellg()<<endl;// get position currently set to last position
		
		//we need to manually set get position to 0 to read data from file from beginning
		
		file.seekg(15);
	
		//reading from the file
		while(!file.eof())
		{
			string line;
			
			getline(file,line);
			
			cout<<line<<endl;
			
		}
		cout<<boolalpha<<file.eof();
		
		file.close();
	}
}
