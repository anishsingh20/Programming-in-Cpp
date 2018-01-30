#include<iostream>
#include<vector>
#include<algorithm>


# define n 6 //size of array


using namespace std;
/*PROGRAM FOR QUICK-SORT
TIME COMPLEXITY- WORST CASE - O(n^2) , BEST CASE/AVG CASE - O(nlogn)
ALGORITHMIC STRATEGY- DIVIDE AND CONQUER

1)QUICK sort is the best sorting approach for all practical problems, due to its efficiency.
2)Quick sort is an IN-PLACE sorting algorithm, i.e it requires constant amount of extra memory ,sorting without any extra space requirement.
3)Also in worst case scenario of O(n^2) is often ignored due to the RANDOMIZED VERSION OF QUICK SORT which gives the highest probability of O(nlogn)

Another thing is that it does not requires to create new AUX arrays like in Merge Sort to divide the problem into subproblems. It does all the re-arrangements in the
same array itself. This makes it save some extra memory as compared to MERGE SORT

*/

int Partition(int *arr,int start, int end) {
	
	int Pivot = arr[end]; //PIVOT is the right most element of array
	
	int Pindex  =  start; //Pindex initially set to start index of array
	
	//trversing the array
	for(int i = start ; i < end ; i++) 
	{
		if(arr[i] <= Pivot) {
			swap(arr[i],arr[Pindex]);
			Pindex++;
		}	
	}
	
	swap(arr[Pindex],Pivot);//swapping PIVOT and element at Pindex
	
	return Pindex;//now at the end Pindex is the index of the PIVOT
}

void QuickSort(int *arr,int start, int end) {
	
	if( start < end ) {
		
		int Pindex = Partition(arr,start,end); //calling partition function to rearrange the elements of array in such a way that 
		// left half has <= PIVOT elements, right half elements > PIVOT. 
		
		//recursively calling Quicksort on left half of array
		QuickSort(arr,start,Pindex-1);
		
		//recursively calling Quicksort on right half of array
		QuickSort(arr,Pindex+1,end);
	}
}


int main() {
	
	int arr[n];//array with n elements	

	//input elements of array
	for(int i = 0 ; i < n ; i++) {
		cin>>arr[i];
		 //insertion from end of vector
	}
	
	QuickSort(arr,0,n-1);
	
	cout<<"Sorted array is :"<<endl;
	
	for(int i = 0 ; i < n ; i++) {
		cout<<arr[i]<<"\t";
		 
	}
	
	
	return 0;
}
