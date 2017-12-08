#include<iostream>

using namespace std;

class Person {
	public :
		Person() {
			cout<<"Constructor of base class"<<endl;
		}
		~Person() {
			cout<<"Destructor of Base class"<<endl;
		}
	
};


class Student : public Person {
	public:
		Student() {
			cout<<"Constructor of derived class"<<endl;
		}
		~Student() {
			cout<<"Destructor of derived class"<<endl;
		}
	
};


int main() {
	
	Student s;//object created-constructor called
	
	
	return 0;
	
}
