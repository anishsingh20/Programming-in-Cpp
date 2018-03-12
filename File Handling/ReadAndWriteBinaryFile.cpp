#include<iostream>
#include<fstream>
#include<cstring>


//program to read and write to a binary file using read() and write() methods



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
	
	//creating file object
	fstream file("AnishBin.bin",ios::binary | ios::in | ios::out | ios::trunc);
	
	if(!file.is_open())
	{
		cout<<"Connection to file could not be done"<<endl;
	}
	else
	{
		//writing a block of data to the binary file
		
	}
}
