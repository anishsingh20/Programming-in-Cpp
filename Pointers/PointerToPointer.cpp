#include<iostream>

using namespace std;

//POINTERS TO POINTERS

int main() {
	
	int x=10;
	
	int *p=&x; //stores address of x;
	
	int **p1=&p;//stores or points/refers to address of p
	int ***p2=&p1;//stores and points/refers to address of p1
	
	cout<<&x<<endl;//address of x
	cout<<*p<<endl; //prints value at address stored in p ie value of x=10
	cout<<&p<<endl;//address of p
	cout<<*p1<<endl;//prints value at address stored in p1 i.e add of p and prints the value stored in p i.e address of x
	cout<<&p1<<endl;//address of p1
	cout<<*p2<<endl;//prints address of p pointer
	
	cout<<**p2<<endl;//prints the address of x
	
	cout<<"**p1= :"<<**p1<<endl;//value of x
	
	**p1=20;
	
	cout<<"value of x is :"<<x<<endl;
	
	cout<<"***p2=:"<< ***p2<<endl;//prints value of x
	
	***p2=25;
	
	cout<<"Value of x now is :"<<x<<endl;
	
	
	
	return 0;
}
