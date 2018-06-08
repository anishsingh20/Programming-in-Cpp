#include<iostream>

using namespace std;

//MERGE SORT-DIVIDE AND CONQUER algorithm
//TIME COMPLEXITY- O(nlogn)
/*
a)Merge Sort works better than quick sort if data is accessed from slow sequential memory.
b)Merge Sort is stable sort by nature
c)Merge sort outperforms heap sort in most of the practical situations.
*/



//2 functions
//1) MergeSort(arr,l,m,r)-To merge the 2 halves of arrays in sorted manner
//2) Merge(int arr,l,r) - to divide into 2 subarrays and sort them by calling MergeSort()

//function for merging in sorted manner
void MergeSort(int arr[],int l ,int m,int r) {
	
	int i,j,k;
	int nL = ((m-l) + 1); //number of elements in left subarray
	int nR =  (r-m); //number of elements in right subarray
	
	int L[nL], R[nR];//initialize sub arrays
	
	
	
	
	//copying the array elements to temp arrays L[] and R[]
	
	for(i=0;i<nL;i++)
	{
		L[i] = arr[l+i];
	}
		
	
	for(j=0;j<nR;j++)
	{
		R[j] = arr[m+1+j];
	}
		
		
	 i=0,j=0,k=l;
	//i is the index of left subarray
	//j index in right subarray
	//k-index of new sorted merged array
	
	
	//traversing the left and right arrays
	while(i<nL && j<nR) {
		
		if(L[i] <= R[j] )   {
			arr[k] = L[i];
			i++;
			
			
		}
		else {
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	
	//if left subarray has left overs,then copy them to A[k]
	while(i < nL2) {
		arr[k]=L[i];
		i++;
		k++;
		
	}
	while(j<nR) {
		arr[k]=R[j];
		j++;
		k++;
	}
	
}





void Merge(int arr[],int l, int r) 
{
	if(l<r) {
		//// Same as (l+r)/2, but avoids overflow for
        	// large l and h
		int mid = (l + (r-l)/2 ) ;
		
		//Call Merge on left subarray
			Merge(arr,l,mid);
			
		//call Merge on right subarray 
			Merge(arr,mid+1,r);
			
			//Merge the two halves sorted in step 2 and 3:
			MergeSort(arr,l,mid,r);
	}
	
}

int main() {
	int n=10;
	int ar[n];
	
//	cin>>n;	
	for(int i=0 ; i < n ;i++) {
		cin>>ar[i];
	}
	
	cout<<"sorting the array: "<<endl;
	
	Merge(ar,0,n-1);
	
	cout<<"The sorted array is"<<endl;
	
	for(int i=0 ; i < n ;i++) {
		cout<<ar[i]<<"\t";
	}
	
	
}

 
