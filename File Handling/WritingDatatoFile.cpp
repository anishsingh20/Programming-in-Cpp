#include<iostream>
#include<fstream>

//Program on File handling and opening and closing connections to a file stream
using namespace std;

//writing data to a file using oftream class object simply like a stream opt


int main()
{
	ofstream file("anish.txt"); //opeing connection to file using object of oftream class
	
	if(!file.is_open())
	{
		cout<<"File not found"<<endl;
	}
	
	else
	{
		cout<<"file found"<<endl;
		
		file << "1) Anish Singh Walia is a Data scientist."<<endl;
		
		file << "2) Anish loves data analytics and statistics."<<endl;
		file << "3) Anish loves to blog too."<<endl;
		
		
		// simultaneously reading data from file
		
		ifstream file("anish.txt");
		
		while(file.good())
		{
			string line;
			getline(file,line);
			
			cout<<line<<endl;
		}
		
		
		file.close();
	}
	
	return 0;
}
