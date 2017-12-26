#include<iostream>

using namespace std;


int findLargest(int *arr,int low,int high ) {
	
	int max;
	//if array has size 1
	if(low==high) {
		return arr[low];
	}
	
	else {
		max = findLargest(arr,low+1,high);
		
		if(arr[low]>max) {
			return arr[low];
		}	
		else {
			return max;
		}
		
	}
	
	
}


int main() {
	
	int arr[5]={1,2,3,4,10};
	
	cout<<findLargest(arr,0,4;
	
	
	return 0;
}
