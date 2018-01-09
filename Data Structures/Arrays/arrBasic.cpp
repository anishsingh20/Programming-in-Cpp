#include<iostream>

using namespace std;

int main() {
	int arr[5]; 
	/*one contigious memory block allocated to the int array at compile time
	 arrays are automatically passed by reference so , the name of the array prints the base address of the array -or add of 1 element of array
	
	Arrays are defined as contiguous blocks of memory, and so any array element will be physically near its neighbors in RAM. This
	greatly benefits from modern CPU caching methods.
	
	Elements of array can be accessed in constant time at a specific location by using the subscript notation eg-arr[0] 
	*/
		
	for(int i=0;i<5;i++) {
		
		
		cout<<"Address of "<<i+1<<" element: "<<arr+i<<endl; //add of array elements
		
	}
	

	
return 0;
	
}
