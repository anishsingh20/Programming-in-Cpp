#include<iostream>


using namespace std;

class Empty {
	
	int *x;
	int y;
	public:
	Empty()
	{
		cout<<"Constructor called"<<endl;
	}

	Empty(int i)
	{
		cout<<"Parametric constructor called"<<endl;
		y = i;
		
	}
		
//	Empty(const Empty &e)
//	{
//		x = new int((*e.x) ) ;
//		cout<<"Copy constructor called"<<endl;
//	}
	
	void get()
	{
		cout<<"y is: "<<y<<endl;
		
	}
	
};

	
int main()
{

Empty e ; //default constructor called

Empty t(20);//parametric constructor called -  CONVERSION CONSTRUCTOR

t = 100; //changing the value of x; 



//Empty c(t); //copy constructor is called

cout<<sizeof(Empty)<<endl;
e.get(); //outputs garbage value

t.get(); //prints 20 at a different address

//c.get(); //prints 20 //at a different address




	
	
}
