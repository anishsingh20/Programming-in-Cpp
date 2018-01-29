#include<iostream>

using namespace std;

//1)recursive solution
//2) iterative solution

//TIME COMPLEXITY=O(logn)
//SPACE COMPLEXITY- a) for iterative imp = O(1), for recursive imp= O(logn) for function call stack


int BinarySearch(int arr[],int l,int r , int x) {
	
	if(r>=l) {
		
		//finding the middle index
		int mid  = (l + (r-l)/2 );
		
		//element found
		if(arr[mid]==x) {
			return mid;
		}
		
		//move to the left half and recude the search space as x is amller the middle element 
		if(arr[mid] > x  ) {
			
			return BinarySearch(arr,l,mid-1,x);
			
		}
		
		//move to the right half of the array
		return BinarySearch(arr,mid+1,r,x);
		
	}
	
	else {
		return -1;
	}
}


//Iterative implementation

int Binary(int arr[],int l, int r , int x ) {
	
	while(r>=l) {
		// Same as (l+r)/2, but avoids overflow for
        	// large l and h
		int mid = (l + (r-l)/2 );
		
		if(arr[mid]==x) return mid;
		
		if(arr[mid] < x) l = mid+1; //search in right half-reduce search space
		
		if(arr[mid]>x) r = mid-1; //search in left half
	}
	
	//if not found return -1
	return -1;
}


//function to sort the array
void bubblesort(int arr[],int n) {
	
	for(int i = 0 ; i< n ; i++) {
		for(int j = i+1 ; j < n; j++) {
			
			if(arr[i] > arr[j]) {
				
				swap(arr[i],arr[j]);
				
			}
		}
	}
	
} //time complexity = O(n^2) - 2 loops


int main() {
	
	int n=5,x;
	int arr[n];
	
//	cin>>n; //size of array
	cin>>x; //element to search
	
	for(int i = 0 ;  i<n ; i++) {
		cin>>arr[i];
	}
	
	
	//sorting the array in ascending arder, if it is unsorted
	bubblesort(arr,n);
	
	cout<<"Sorted array is :"<<endl;
	
	for(int i = 0 ;  i<n ; i++) {
		cout<<arr[i]<<"\t";
	}
	
	cout<<"\n";
	
	int index = Binary(arr,0,n-1,x);
	
	
	if(index==-1)  {
		cout<<"Element not found"<<endl;
	} 
	else 
	{
		cout<<"Element "<<x<<" "<<"found at "<<index+1 <<" "<<"position.";
	}
			
	
	
	return 0;
}
