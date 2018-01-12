#include<iostream>

using namespace std;

/*GENERIC POINTER or VOID POINTER

 it is a type of pointer which does not  correspond to a particular datatype
 1)A void pointer has no type 
 2)A void pointer cannot be dereferenced as it does not correspond and map to any datatype 
 3)Also void pointers do not allow pointer airthmetic 
 4)Void pointers can point to any memory chunk
 5)Hence the compiler does not know how many bytes to increment/decrement when we attempt pointer arithmetic on a void pointer.

*/

int main() {
	
	int a=100;
	int *p = &a; //base address of a
	
	void *p1;
	
	
	p1 = p;
	
	cout<<p1<<endl; //prints the base address of a 
 
	
	 
	
//	cout<<*p1; //produces error as we cannot dereference a void pointer as it does not map to any particular type
	
	return 0;
}
