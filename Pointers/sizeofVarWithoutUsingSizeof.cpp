#include<iostream>

using namespace std;


//a function to print the size in bits
//int size()
//{
//  int a = 1;
//  int size = 1;
//  while(a<<=1)
//    size++;
//  return size;
//}


int main () {
	
	 long double a;
	
	//Idea is to calculate the address difference between two consecutive variables- the difference would be the size of that variable type
	
	cout<<"Address of a :"<<&a<<endl;
	cout<<"Address of a+1,i.e address of a incremented by 4 bytes :" << &a+1<<endl;//ie address of a incremented by 4 bytes
	int sizeof_int = (char*)((&a)+1) - (char*)(&a);
	cout<<sizeof_int<<endl;
	

//----------------METHOD-2-USING ARRAYS------------------

cout<<"Size of a variable by method 2- "<<endl;
long double arr[2];
int size1 = ( (char*)&arr[1] - (char*)&arr[0] );

cout<<size1<<endl;

//cout<<"Size in bits :"<<size()<<endl;	
	
//NOTE-Also only character type and arrays are guaranteed to be laid out continously in memory, i,e memory allocated to them is contigious memory alloc
/*a+1 is a pointer to a[1], and a decays to a pointer to a[0]. So it calculates the difference in chars between a pointer to a[1] and a pointer to a[0]. 

That is, the number of chars occupied by a[0].

Ss it necessary to type caste that to char *,I mean why can't we use int * for that? 
  	 	
If you use int* then the result will be 1. It shouldn't be surprising that (a+1) - a == 1.



*/







	return 0;
	
	
}
