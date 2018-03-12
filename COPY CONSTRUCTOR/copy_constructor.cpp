#include<iostream>

//COPY CONSTRUCTOR- it is simply a overloaded constructor which is called or used when we copy a object of type class to another object , inorder to
//copy the data members of class to new temp object

//due to copy constructor both the objects will contain the member values at different locations and maintain different values-whether the member values
//are statically allocated or dynamically allocated during runtime

//COPY CONSTRUCTOR-takes parameter as a reference to object of class Person , it should be always constant

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
		
		//COPY CONSTRUCTOR-takes parameter as a reference to object of class Person , it should be always constant
		Person(const Person &p)
		{
			cout<<"calling copy constructor"<<endl;
			name = new string(*p.name); //allocating a new memory block to the pointer name member of class, so that the copied object can
			//contain the name variable at a different location 
			age =  (p.age); 
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

	Person newAnish = Anish; //copy constructor is called here
		
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
