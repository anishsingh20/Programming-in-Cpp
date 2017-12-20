#include<iostream>

using namespace std;



int main() {
	int *ptr;
	int x = 10;
	ptr = &x;//ptr stores address of x| points to the location of x in stack
	*ptr=20; //value of x updated
	
	cout<<ptr<<endl;//prints the address of x in stack
	cout<<x<<endl; //prints the updated value of x
	cout<< *ptr; //value of x
	return 0;
}
