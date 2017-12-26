#include<iostream>

using namespace std;


#define n 5


//BUBBLE SORT function- takes argument as an array(pointer) and the size of array

//TIME COMPLEXITY-O(n^2) of BUBBLE SORT-nested loops
void BubbleSort(int  *arr,int size) {
	
	for(int i = 0 ; i < size; i++ ) {
		for(int j=i+1 ; j < size ; j ++ ) {
			
			if(arr[i]>arr[j]) {
				
				swap(arr[i],arr[j]);
			}	
		}
	}
	
	for(int i=0;i<size;i++) {
		cout<<arr[i]<<"\t";
	}
	
		
}

int main() {
	int arr[n];
	cout<<"Enter elements in array "<<endl;
	for(int i=0;i<n;i++) {
		
		cin>>arr[i];
	}
	
	BubbleSort(arr,n);
	
//	for(int i=0;i<n;i++) { // O(n)
//		
//		for(int j=i+1 ;j<n;j++) {  
//			//O(n(n-1)) - executes n*(n-1) times
//			if(arr[i]>arr[j]) { //for sorting in ascending order
//				
//				swap(arr[i],arr[j]);
//			}
//		}
//	}
	
	
	
//	cout<<"Sorted array is: "<<endl;
//	for(int i=0 ;i<n;i++) {
//		cout<<arr[i]<<"\t";
//	}
	
	return 0;
}
