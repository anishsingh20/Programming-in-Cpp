#include<iostream>

using namespace std;


#define n 5
//SELECTION SORT in C++
//TIME COMPLEXITY-O(n^2) of SELCETION SORT-nested loops
//NOTE-The number of swap operations are minimized in general in SELECTION SORT
//Selection sort makes O(n) swaps which is minimum among all sorting algorithms mentioned above.
void SelectionSort(int  *arr,int size) {
	
	for(int i = 0 ; i < size; i++ ) {
		int min = i;
		
		for(int j=i+1 ; j < size ; j ++ ) {
			
			if(arr[j] < arr[min]) {
				
				min = j;
				swap(arr[i],arr[min]);	
					
			}
		
		}
	}
	
	for(int i=0;i<size;i++) {
		cout<<arr[i]<<"\t";
	}
	
		
}



int main () {
	

	int arr[n];
	cout<<"Enter elements in array "<<endl;
	for(int i=0;i<n;i++) {
		
		cin>>arr[i];
	}
	
	SelectionSort(arr,n);
	
	
}
