#include<stdio.h>
#include<conio.h>


//merge sort implementation in C

void SortedMerge(int *arr,int low,int mid ,int high)
{
	int nl,nr;
	
	
	nl = (mid - low + 1); //number of elements in left sub array
	
	nr = (high - mid); //number of elements in right subarray
	
	int arr_left[nl], arr_right[nr];
	
	
	
	//copying items to left and right subarrays from original parent array
	for(int l=0;l<nl;l++)
	{
		arr_left[l] = arr[low+l];
	}
	
	for(int m=0;m<nr;m++)
	{
		arr_right[m] = arr[mid+m+1];
	}
	
	
	int i=0,j=0,k=low;
	
	
	//sorting and merging the 2 auxillary subarrays into 1
	while(i < nl && j < nr)
	{
		if(arr_left[i] < arr_right[j])
		{
			arr[k] = arr_left[i];
			i++;
			k++;
		}
		
		else
		{
			arr[k] = arr_right[j];
			j++;
			k++;	
		}
	}
	
	while(i<nl)
	{
		arr[k] = arr_left[i];
			i++;
			k++;	
	}
	
	while(j<nr)
	{
		arr[k] = arr_right[j];
			j++;
			k++;	
	}
	
	
}


void MergeSort(int *arr,int low,int high)
{
	if(low<high)
	{
		int mid = low + (high-low)/2;
		
		//first recursively diving the array into smaller parts 
		MergeSort(arr,low,mid);
		MergeSort(arr,mid+1,high);
		
		SortedMerge(arr,low,mid,high);
	}
}

int main()
{
	
	int arr[] = {100,90,15,-100,1,35,200};
	
	int high = sizeof(arr)/sizeof(arr[1]);
	
	MergeSort(arr,0,high-1);
	
	for(int i= 0 ; i<high;i++)
	{
		printf("%d->\t",arr[i]);
	}
	
	return 0;
}
