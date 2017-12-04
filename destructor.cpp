//constructors example
#include<iostream>

using namespace std;


class human 
{
	public:
		human() { //constructor
			age=20;
			name="Anish";
			cout<<"Default Constructor is called"<<endl;
		}
		
		~ human()  { //destructor
		 
		 cout<<"Destructor is called as object of class is deleted and memory allocated to the object is released"<<endl;
		 age=10;
		 name="Mrinal";
			
		}
		
		void introduce()
		 {
		 	cout<<"Hello I am" <<" " << name << " "<<"and my age is" << age<<endl;
		 }
  		
	private:
		int age;
		string name;
	
	
};


int main() {
	 
	 human *obj; //pointer to object of type human
	 obj = new human; //memory block allocated to the object in the HEAP memory
	 
	 
	 //destructor not called as object is not deleted
	obj->introduce();
	
	//deallocating the memory allocated to the object
	delete obj;
        	 
	
}
