#include<iostream>

using namespace std;

class Person
{
	public:
		int age;
		string *name;
		//constructor 
		Person(int age, string name)
		{
			this->age = age;
			this->name = new string(name); //allocating new memory block and entering name inside it
			
		}
		
		void changePerson(string name,int age)
		{
			*(this->name) = name;
			this->age = age;
			
		}	
		
		void introduce()
		{
			cout<<"The person is "<<*name<<" "<<"and his age is "<<age<<endl;
		}
};

	

int main()
{
	Person Anish(20,"Anish");
	
	Anish.introduce();
	
	//making a copy of the object Anish()

	Person newAnish = Anish;
		
	newAnish.introduce();
	
	//changing the name and age
	Anish.changePerson("Anish Singh Walia",21);
	
	Anish.introduce();
	
	
	//both at different addresses
	cout<<"Address of Anish.age object-->"<<&Anish.age<<endl; 
	cout<<"Address of newAnish.age object-->"<<&newAnish.age<<endl;
	
	
	//but without copy constructor both will point to same memory block
	cout<<"address of Anish.name object-->"<<Anish.name<<endl;
	cout<<"address of newAnish.name object-->"<<newAnish.name<<endl;
	
	newAnish.introduce();//without copy constructor it prints the updated name Anish Singh Walia as it is a pointer, but age remains same as it is
	//statically allocated at a different memory location when copied by another object.
	
	return 0;
}
