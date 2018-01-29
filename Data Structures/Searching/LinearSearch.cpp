#include<iostream>
#include<algorithm>
using namespace std;

//Linear search program- TIME COMPLEXITY-O(n)

//one by one match data with array elements , if data matches , return its index , otherwise keep searching and matching
//Linear search is rarely used practically.

//other search algorithms such as the binary search algorithm and hash tables allow significantly faster searching comparison to Linear search.
int n=5;
int LinearSearch(int *arr,int data) {
	
	for(int i = 0; i < n ; i++)
	{
		if(arr[i]==data)
		{
			return i;
		}
		
		return -1;
		
	}
	
	
	
}

int main() {
	
	

	int data,arr[n];
	cin>>data;
	for(int i = 0; i < n ; i++) {
		cin>>arr[i];
		
	}
	
	cout<<LinearSearch(arr,data);
	
	
	return 0;
}
