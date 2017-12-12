#include<iostream>
// use of this keyword-

using namespace std;

//this pointer in cpp is used to refer to invoke a object or store address of a class object
//this pointer - can be used by a 0bject to point/refer and access its own address.

class Person {
	
	private:
		int age;
	public:
	
		void setAge(int age) {
			
			this->age = age;//this used to access the address of object, so that compiler cannot
			//be confused
			//this variale used to retrive the objects's age variable
			
			
		}
		void getage() {
			cout<<"My age is "<<this->setAge(20)<<endl;
		}
		
	
}; 


int main() {
	
	Person p;
	cout<<p.getage();
	return 0;
}
