#include<iostream>
#include<math.h>
using namespace std;


int main() {
	
	int arr[5],*ptr;
	
	cout<<*&arr<<endl; //address of first element in array
	cout<<&arr<<endl;//address of first element in array
	cout<<arr<<endl;//address of first element in array
	
	
	cout<<"&arr + 1 = "<<&arr+1<<endl; // address of complete array incremented by 5*4 bytes 
	cout<<"arr+1 = "<<arr+1<<endl;//address of 2 element of array - incrmented by 4 bytes as it is an integer array
	
	
	cout<<&ptr<<endl;
	cout<<&ptr+1<<endl;//prints address of pointer with increment of 4 
	cout<<&ptr+2<<endl;
	cout<<&ptr+3<<endl;
	//a pointer has size 8 bytes on a 64 bit machine, so &ptr+1 will print =hex addr of pointer + next 8 bytes
	
//	int i=1;
//	while(i)
//	{
//		i++;
//	}
//	i=i/2;
//	int size = log(i);
//	cout<<size;
//	return 0; 
}
