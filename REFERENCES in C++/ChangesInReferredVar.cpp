#include<iostream>


using namespace std;

//when we use a referece to refer to a variable, changes made to the reference var is reflected in referred var and vice versa is also true i.e
//changes made to the referred var makes changes in the reference variable too.

int main()
{
	int x = 20;
	
	int &ref = x; //now ref and x both have same addresses
	
	cout<<"Address of ref is "<<&ref<<", and address of x "<<&x<<" are same."<<endl;
	
	
	ref = 30; //updates x too as ref refers to x;
	
	cout<<"x ="<<x<<endl;
	
	x = 100; //updates ref variable too, as ref referes to x and both x and ref have same addresses;
	
	cout<<"reference variable ref is,= "<<ref<<endl;
	
	
	
	


	
}
