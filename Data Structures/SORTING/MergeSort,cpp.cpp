#include<iostream>

using namespace std;

//MERGE SORT-DIVIDE AND CONQUER algorithm
//TIME COMPLEXITY- O(nlogn)

//2 functions
//1) MergeSort(arr,l,m,r)-to divide into 2 subarrays and sort them
//2) Merge(int arr,l,r) - To recursively merge the 2 sorted halves of arrays

void MergeSort(int arr[],int l ,int m,int r) {
	int i,j,k=0;
	//i is the index of left subarray
	//j index in right subarray
	//k-index of new sorted merged array
	
	int nL = m-l + 1; //number of elements in left subarray
	int nR =  r-m; //number of elements in right subarray
	
	int L[nL], R[nR];//initialize sub arrays
	
	//traversing the left and right arrays
	while(i<nL && j<nR) {
		
		if(L[i] < R[j] )   {
			A[k] = L[i];
			i++;
			k++;
			
		}
		else {
			A[k]==R[j];
			j++;
			k++;
		}
	}
	
	//if left subarray has left overs,then copy them to A[k]
	while(i != nL) {
		A[k]=L[i];
		i++;
		k++;
		
	}
	while(j!=nR) {
		A[k]=R[j];
		j++;
		k++;
	}
	
}





void Merge(int arr[],int l, int r) 
{
	if(l<=r) {
		int mid = (l + (r-l)/2 ) ;
		
		//Call Merge on left subarray
			Merge(arr,l,mid);
			
		//call Merge on right subarray 
			Merge(arr,mid+1,r);
			
			//Merge the two halves sorted in step 2 and 3:
			MergeSort(arr,l,mid,r);
	}
	
}

 
