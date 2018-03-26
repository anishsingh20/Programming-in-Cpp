#include<iostream>

using namespace std;

/*Program to find Ceil and floor of a key in an sorted array.
2 approaches-
a)Linear search
b)Divide and Conquer- similar to Binary Search
*/

int ceil=0,floor=0;

//using divide and conquer
void FindCeilFloor(int *arr,int key,int low,int high)
{
	//base case
		if(low > high)
			return;


		

		int mid = low + (high-low)/2;
		
		if(arr[mid]==key)
		{
			ceil = floor = arr[mid];
			
		}
		
		if(arr[mid] > key)
		{
		//search for ceil and floor in left subarray
			ceil = arr[mid];
			FindCeilFloor(arr,key,low,mid-1);
		
			
		}
	
		if(arr[mid] < key )
		{
			floor = arr[mid];
			FindCeilFloor(arr,key,mid+1,high);
			
		}
	
}

int main()
{
	int arr[] = {1,5,10,15,20,100,250};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	FindCeilFloor(arr,190,0,size-1);
	
	cout<<"The floor "<<floor<<" and the ceiling is ."<<ceil<<endl;
}
