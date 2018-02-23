#include<stdio.h>
#include<conio.h>


//program to do binary search in c-recursive implementation

//selection sort has minimum number of swaps

void Swap(int *a,int *b)
{

	int temp = *a;
	*a = *b;
	*b = temp;
	

}


void SelectionSort(int *arr, int size)
{

	for(int i = 0; i < size;i++)
	{
		int min = i;
		
		for(int j = i+1 ; j<size;j++ )
		
		{
			if(arr[j] < arr[i])
			{
				min = j;
				Swap(&arr[min],&arr[i]);
			}
		}
	}
	
		for(int i=0;i<size;i++) {
		printf("%d\t",arr[i]);
	}
}


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
	int arr[] = {50,40,10,20,30};
	
	int size = sizeof(arr)/sizeof(arr[1]);
	
	SelectionSort(arr,size);
	printf("\n");
	
	
	
	printf("%d",BinarySearch(arr,10,0,size));
}
