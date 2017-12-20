#include<iostream>

using namespace std;

int main () {
	
	int *ptr,**ptr2, a=10;
	ptr=&a;//ptr stores address of a
	ptr2=&ptr; //ptr2 stores address of ptr, *ptr now print value at ptr
	//-ptr++;
	
	cout<<"Address of a "<<&a<<endl;//address of a
	cout<<"Value of var a i.e *ptr = "<<*ptr<<endl; //value of var a, where ptr is referencing/pointing to as ptr stores the address of var a.
	cout<<"Address of ptr :i.e &ptr= "<<&ptr<<endl;//address of ptr in memory
	cout<<"value stored in ptr, ie address of a,ptr =  "<<ptr<<endl;
	cout<<"Address of ptr2 : &ptr2= "<<&ptr2<<endl;// address of **ptr2 in memory
	
	cout<<"Value of ptr i.e address of a -*ptr2 = :"<<*ptr2<<endl;//addrerss of ptr where ptr2 is pointing.
	cout<<"value stored in ptr2, i.e address of ptr "<<ptr2<<endl;
	return 0;
	
	
	
}
