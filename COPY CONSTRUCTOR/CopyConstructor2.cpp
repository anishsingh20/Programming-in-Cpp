#include<iostream>


using namespace std;

class Empty {
	
	int *x;
	public:
	Empty()
	{
		cout<<"Constructor called"<<endl;
	}

	Empty(int i)
	{
		cout<<"Parametric constructor called"<<endl;
		*(this->x) = i;
	}
		
	Empty(const Empty &e)
	{
		x = new int(*e.x);
		cout<<"Copy constructor called"<<endl;
	}
	
	void get()
	{
		cout<<x<<endl;
	}
	
};

	
int main()
{

Empty e ; //defauly constructor called

Empty t(20);//parametric constructor called

Empty c(t); //copy constructor is called


e.get(); //outputs garbage value

t.get(); //prints 20 at a different address

c.get(); //prints 20 //at a different address




	
	
}
