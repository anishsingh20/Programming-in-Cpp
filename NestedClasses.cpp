#include<iostream>
using namespace std;

//Nested classes-classes defined inside a class


class Person {
	public:
		 string name;
	
	class Anish {
		public:
			string address;
			string city;
			string country;
			
			
		
				
	};
	//we need to define object of nested class to access its members inside Parent class
	
	Anish a; //object created
	void getadd()
	{
		cout<<"Name: "<<name<<endl<<"Address:"<<a.address<<endl<<"City: "<<a.city<<endl<<"Country: "<<a.country<<endl;
	}
	
	
			
};

int main() {
	Person p;
	//creating object of nested clas outiside Parent class throws error
	//Person::Anish an; //need to use scope resolution operator
	p.a.address="Hari Kunj";
	p.a.city="Dehradun";
	p.a.country="India";
	p.name="Anish";
	p.getadd();
	return 0;
	
}
