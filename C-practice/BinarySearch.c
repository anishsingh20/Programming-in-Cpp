#include<stdio.h>
#include<conio.h>


//program to do binary search in c-recursive implementation

int BinarySearch(int *arr,int data,int low,int high)
{
	//base condition
	if(low<high)
	{
		int mid = low + (high-low)/2;
		
		if(arr[mid]==data)
			return mid;
			
		//otherwise recur to left half and find
		if(arr[mid]>=data)
			return	BinarySearch(arr,data,low,mid-1);
		else
			return BinarySearch(arr,data,mid+1,high);
		
	}
	
	else
		return -1;
}

int main()
{
	int arr[] = {10,20,30,40,50};
	
	printf("%d",BinarySearch(arr,9,0,4));
}
