#include<iostream>

using namespace std;

//1)recursive solution
//2) iterative solution


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


int main() {
	
	int n=5,x;
	int arr[n];
	
//	cin>>n; //size of array
	cin>>x; //element to search
	
	for(int i = 0 ;  i<n ; i++) {
		cin>>arr[i];
	}
	
	int index = BinarySearch(arr,0,n-1,x);
	
	
	if(index==-1)  {
		cout<<"Element not found"<<endl;
	} 
	else 
	{
		cout<<"Element "<<x<<" "<<"found at "<<index+1 <<" "<<"position.";
	}
			
	
	
	return 0;
}
