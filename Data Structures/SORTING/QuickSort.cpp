#include<iostream>

using namespace std;
/*PROGRAM FOR QUICK-SORT
TIME COMPLEXITY- WORST CASE - O(N^2) , BEST CASE/AVG CASE - O(nlogn)
ALGORITHMIC STRATEGY- DIVIDE AND CONQUER

QUICK sort is the best sorting approach for all practical problems, due to its efficiency.
Quick sort is an IN-PLACE sorting algorithm, i.e it requires constant amount of extra memory ,sorting without any extra space requirement.
Also in worst case scenario of O(n^2) is often ignored due to the RANDOMIZED VERSION OF QUICK SORT which gives the highest probability of O(nlogn)

Another thing is that it does not requires to create new AUX arrays like in Merge Sort to divide the problem into subproblems. It does all the re-arrangements in the
same array itself. This makes it save some extra memory as compared to MERGE SORT

*/

int Partition(int *arr,int start, int end) {
	
	return Pindex;
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
	
	
	return 0;
}
