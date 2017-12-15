#include<iostream>

using namespace std;

//Implementation of Local classes-Classes defined inside a function

//function prototyping-forward declaration
void getClass();

int main(){
	getClass();
	return 0;
	
}


void getClass() {
	class Person {
		public:
			string name;
			int age;
			void getdetails() {
				
				cout<<"Name: "<<name<<endl<<"Age is :"<<age<<endl;
			}
	};
	
	//Class object and the members of class can only be used inside the function as it has a local block scope
	Person p;
	p.name="Anish";
	p.age=20;
	p.getdetails();
	
}

