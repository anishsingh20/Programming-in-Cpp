#include<iostream>

using namespace std;


//EXPLICIT SPECIALIZATION for generic classes



//class which can work for any data type
template<class T> class Info{

	T x;
	
	public:
		Info(T x)
		{
			this->x = x;
		}
		
		
		void display()
		{
			cout<<"Generic class displays,x = "<<x<<endl;
		}

};



//class which will work specifically for integer data type only-Note
//we need to declare this class in this manner with template argument
template<> class Info <int> {
	
	int x;
	
	public:
		Info(int x)
		{
			this->x = x;
		}
		
		
		void display()
		{
			cout<<"The product is: "<<x*x<<endl;
		}



};

int main()
{
	Info<string> obj1("anish");
	
	Info <int> obj2(2);
	
	Info <float> obj3(34.22);
	
	
	obj2.display();
	
	obj1.display();
	
	obj3.display();
	
	return 0;
	
}
