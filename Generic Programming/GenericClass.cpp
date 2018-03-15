#include<iostream>

using namespace std;


//Generic classes-classes which can work wiht multiple different datatypes

template <class t1,class t2> class Info{

	t1 x;
	t2 y;
	
	int counter;
	
	public:
		//constructor declaration
		Info(t1 x , t2 y,int z)
		{
			this->x = x;
			
			this->y = y;
			
			counter=z;
		}
		
		
		void display()
		{
			cout<<x<<" "<<y<<" "<<counter;
			cout<<endl;
		}



};


int main()
{
	//creating objects
	Info <int,string> obj1(20,"anish",100);
	
	Info <float,double> obj2(10.22,9.998,200);
	
	obj1.display();
	
	obj2.display();
	
}


