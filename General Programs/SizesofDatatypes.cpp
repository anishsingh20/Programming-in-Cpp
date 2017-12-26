#include<iostream>

using namespace std;

int main() {
	
	cout<<sizeof(int)<<endl; //4 bytes
	cout<<sizeof(char)<<endl;//1 byte
	cout<<sizeof(long unsigned int)<<endl; //4 bytes
	cout<<sizeof(float)<<endl;  //4 bytes
	cout<<sizeof(double)<<endl; // 8 bytes
	cout<<sizeof(long double)<<endl;// 16 bytes

//	int arr[4] = {3,2,4,10};
//	int *ptr;
//	ptr= &arr[1]; //pointer refers to the second array element-2 and stores it mem aaddress
//	cout<<sizeof(*ptr)<<endl; //print the size of the value of ptr i.e integer size-4bytes
//	cout<<*ptr<<endl;//print 2
//	*ptr=10; //indirect manipulation of value of arr[1]
//	cout<<arr[1]; //now value of arrays's arr[1] updated	
//	
	
	
	
	return 0;
	
}
