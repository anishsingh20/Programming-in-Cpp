#include<iostream>
#include<fstream>

using namespace std;

//reading data from a file using ifstream class


int main()
{
	//creating an object of class ifstream
	ifstream file("anish.txt");
	
	if(!file.is_open())
	{
		cout<<"File not found"<<endl;
	}
	
	else 
	{
		
		//file.good() is a method which checks if flags such as eof bit, bad bit , good bit are set or not
		//so when file ends and eof flag is set,we come out of loop
		while(file.good())
		{
			//store read data in this variable line
			string line;
			//reading entire line using getline()
			
			getline(file,line);
			
			cout<<line<<endl;	
		}
		
		
		file.close();
	}
	
	
	return 0;
}
