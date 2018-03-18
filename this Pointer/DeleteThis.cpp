#include<iostream>

using namespace std;

/*  destructor and this pointer-

'delete this' inside a destructor or any member function 
only works for objects created using new keyword.

*/
class Person{
	
	int x;
	
	public:
		Person() { 
			
			cout<<"Constructor called"<<endl;
			x = 0;
		}
		
		void destroy()
		{
			cout<<"destructor called"<<endl;
			delete this;
		}
		
	
};

int main()
{
	//works fine
	Person *a = new Person();
	Person b;
	
	b.destroy();//produces undefined behavior
	
	//works fine- as object is allocated using new operator	
	a->destroy();
	
	
	
	
}
