#include<iostream>

using namespace std;


class Person{
	
	int x;
	
	public:
		Person() { 
			x = 0;
		}
		
		int fun()
		{
			return this->x;
			
		}
		
		
		//this pointer is unavailable for static member functions, as static members function can be called without using class object.
		//works fine
		void fun2()
		{
			cout<<"member function"<<endl;
			cout<<this->fun();
		}
		
		//static member function
		static void fun3(Person &obj);
	
};


//static member function can be defined outside class and don't need an object to called. 

void Person::fun3(Person &obj)
		{
			cout<<"static member function"<<endl;
			
			//this->fun(); //produces error
			
			
			//works fine
			cout<<obj.fun();
			
		}



int main()
{
	Person a;
	a.fun2();
	
	Person::fun3(a);
	return 0;
}
