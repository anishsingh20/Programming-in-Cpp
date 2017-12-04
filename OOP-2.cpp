#include<iostream>

using namespace std;

class human{
	
	public:
	
	string name;
	void introduce();
	
	
};


//scope resolution operator-used to define the class methods outside the class
void human :: introduce() 
{
	cout<<"Hello"<<" " <<human :: name <<endl;
}


int main ()
{
	human obj1;
	obj1.name="Anish";
	obj1.introduce();

	human *obj2 = new human; //pointer method of creating an dynamic object stored in HEAP section of memory
	obj2->name="Mrinal";
	obj2->introduce();
	cout<<obj2; //displays the address of memory in heap	
	
	return 0;
}
