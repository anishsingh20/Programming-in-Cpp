#include<iostream>

using namespace std;

//Virtual destructors

class Person {
	public:
		Person(){
			cout<<"Person called"<<endl;
		}
		virtual ~Person() {
			cout<<"Person deleted"<<endl;
		}
};

class Anish : public Person {
	public:
		Anish() {
			cout<<"Anish called"<<endl;
			
		}
		
		~Anish(){
			cout<<"Anish deleted"<<endl;
		}
};

int main ()
{
	Anish *a= new Anish();
	//first constructor of Parent goes into stack, followed by Child class. And when memeory is deallocated in LIFO fashion
	// first child class object is destructed, followed by the parent class
	cout<<"\n"<<endl;
	cout<<"Deleting from Stack"<<endl;
	cout<<"\n";
	Person *p = a ;//creating a pointer of type Person which refers to pointer of type Anish class
	delete(p); // will automatically delete derived class
	return 0;
}
