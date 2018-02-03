#include<iostream>

using namespace std;

//program to find number of occurences of a a number in a sorted array using Binary search


//function to sort an array-QUICK SORT


//function to partiton the array into 2 parts

#define n 8

int Partition(int *arr,int start,int end) {
	
	int Pivot = arr[end];
	int Pindex = start;
	
	for(int i =start;i<end ;i++) 
	{
		
		
		if( arr[i] <= Pivot) 
		{
			
			swap(arr[i],arr[Pindex]);
			Pindex++;	
		}
		
	}
	
	swap(arr[Pindex],arr[end]);
	
	return Pindex;
	
	
}


void QuickSort(int *arr,int start, int end) 
{
	
	if(start < end) {
		
		int Pindex = Partition(arr,start,end);
		
		QuickSort(arr,start,Pindex-1);
		
		QuickSort(arr,Pindex+1 ,end);
		
	}
	
}





//function to search for occurences in an array using Binary search

int BinarySearch(int *arr , int start, int end, int x ) 
{	
	int count= 0;
 	if(start <= end )
	{
		
		int mid = (start + (end-start)/2 );
		
		//coounting the occurences of a number
		for(int i=start;i<end;i++)
		{
								
			if(arr[i]==x)
			{
						
				count++;
			}
		}
					
		
		if(x==arr[mid]) 
		{
			
			return count;
		}
	
		if(x > arr[mid]) {
					
			return BinarySearch(arr,mid+1,end,x);
			
		}
		
		return BinarySearch(arr,start,mid-1,x);		
		
	}
	
}



int main () {
	
	int arr[n]={10,12,15,10,10,1,4,10};
	
	
	//sorting the array
	QuickSort(arr,0,n-1);
	
	for(int i=0;i<n;i++) {
		cout<<arr[i]<<"\t";
	}
	
	cout<<endl;
	cout<<BinarySearch(arr,0,n-1,10);
	
	
	
	return 0;
}


