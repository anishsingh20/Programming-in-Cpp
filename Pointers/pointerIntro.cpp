#include<iostream>
#include<string>

using namespace std;


int main() {
	
	int *ptr; //declaring a pointer
	int a=10;
	
	ptr = &a; //ptr stores the address of a
	
	cout<<"address of a is :"<<&a<<endl;
	cout<<"Value of ptr :"<<ptr<<endl;
	
	
	
	*ptr=100;//value of a modified
	
	cout<<"value of a is modified as :"<<a<<endl;
	
	return 0;
	
	
	
}
