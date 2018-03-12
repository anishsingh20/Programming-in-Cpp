#include<iostream>
#include<fstream>
#include<cstring>


//program to read and write to a binary file using read() and write() methods

using namespace std;

class Person{
	
	int age;
	string name;
	
	public:
	Person() {
		name="noname";
		age=0;
	}
	
	Person(string name, int age)
	{
		this->name = name;
		this->age  = age;
	}
	
	
	void introduce()
	{
		cout<<"The name is "<<name<<" and age is "<<age<<endl;
	}
};



int main()
{
	Person Anish("Anish",20);
	Person Anish2;
	
	//creating file object
	fstream file("AnishBin.bin",ios::binary | ios::in | ios::out | ios::trunc);
	
	if(!file.is_open())
	{
		cout<<"Connection to file could not be done"<<endl;
	}
	else
	{
		//writing a block of data to the binary file
		//write() function takes argument as data to write and the stream size of the data which is being written
		file.write(  (char*)&Anish,sizeof(Person) );
		
		//now reading data from file
		//first setting the read position to 0
		file.seekg(0);
		
		
		while(!file.eof())
		{
			//reading data from file and storing it in the object
			file.read((char*)&Anish2,sizeof(Person) );
		}
		
		Anish.introduce();
		cout<<endl;
		Anish2.introduce();
	
	
	
		file.close();
		
	}
		
	

}
