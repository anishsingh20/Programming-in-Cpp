#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>

//program to read and write to a Binary File using get() and put() function

using namespace std;
int main()
{
	fstream file;
	file.open("anish.bin",ios::binary| ios::in | ios::out | ios::trunc);
	
	if(!file.is_open()) 
	{
		cout<<"Error, opening file"<<endl;
	}
	
	else
	{
		//writing to file
		char input[100];
		
		strcpy(input,"Hi, I am Anish");
		
		int len = strlen(input);
		for(int i=0;i<len;i++)
		{
			//writing to the file using put()
			file.put(input[i]);
		}
		
		//now reading from the file
		//first we need to set the reading position to the beginning using seekg()
		
		file.seekg(0);
		
		char ch;
		while(file.good())
		{
			//store read characters in ch var
			file.get(ch);
			
			cout<<ch;
				
			
		}
		
			
	}
	
	
	return 0;
	
}
