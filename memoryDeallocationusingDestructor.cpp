//destructor example
#include<iostream>
#include<string>

using namespace std;


class human 
{
	public:
		human(int iage,string iname) { //constructor
			
			 //pointers to a memory location/dynamic memory allocation
			name = new string;
			age = new int;
			
			*age = iage; //assigning value to the pointers
			*name= iname;
			
			
			
			
			cout<<"Default Constructor is called"<<endl;
		}
		 
	
		
		void introduce()
		 {
		 	//accessing value of pointer using value operator *
		 	cout<<"Hello I am" <<" " << *name << " "<<"and my age is" << *age<<endl;
		 }
  		
  		~ human()  { //destructor
		
			 delete name; //deallocating memory allocated to the class variables
			 delete age; 
			 cout<<"All resources released"<<endl;
			
			
		}
  		
  		
	private:
		int *age;
		string *name;
	
	
};


 main() {
	 
	 human *obj; //pointer to object of type human
	 obj = new human(20,"Anish"); //memory block allocated to the object in the HEAP memory
	 
	 
	 //destructor not called as object is not deleted
	obj->introduce();
	
	//deallocating the memory allocated to the object
	delete obj;
        	 
return 0;	
}
