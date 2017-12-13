#include<iostream>

using namespace std;

int main() {
	int a=10;
	int *ptr=&a; //ptr refers a and stores its mem address
	
	cout<<a<<endl;   //value of a
	cout<<&a<<endl;  //mem address of a-Hexadecimal
	cout<<*&a<<endl; // value of a =10
	cout<<*ptr<<endl;//value of a =10
	cout<<&ptr<<endl;//address of ptr variable
	cout<<&*ptr<<endl;//address of a as value of *ptr=10 and address of 10 is add of a
	cout<<*&ptr<<endl;// address of a, as &ptr is address of ptr and ptr stores the mem address of a as value 
	return 0;
}
