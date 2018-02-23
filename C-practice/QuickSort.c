#include<stdio.h>
#include<conio.h>
#include<math.h>



//program to implement quick sort in C

int random(int min,int max)
{
	int range = max - min +1; //range
	int x  = (rand() % range + min );
	
	return x;  
	
}

void Swap(int *a,int *b)
{

	int temp = *a;
	*a = *b;
	*b = temp;
	

}


//implementing randomized quick sort by choosing pivot element as random element, instead of last element
int RandomizedQuickSort(int *arr,int low,int high)
{
	//choosing random pivot element
	int Pindex = random(low,high);
	
	Swap(&arr[Pindex],&arr[high]);
	

	
	return Partition(arr,low,high);
}

int Partition(int *arr,int low,int high)
{
	 
	
	int Pivot = arr[high];//pivot as last element
	int Pindex  = 0; //the index of Pivot element after sorting
	
	for(int i = 0 ; i < high; i++)
	{
		if(arr[i] < Pivot )
		{
			//swap arr[i] and arr[Pindex]
			Swap(&arr[i],&arr[Pindex]);
			Pindex++;
		}
	}
	
	Swap(&arr[Pindex],&arr[high]);
	
	return Pindex;
	
}


void QuickSort(int *arr,int low,int high)
{
	
	if(low < high)
	{
		int pIndex = Partition(arr,low,high);
		
		//recursively partition the lower sub array
		QuickSort(arr,low,pIndex-1);
		
		//recursively partiton the higher right end subarray
		QuickSort(arr,pIndex+1,high);
		
	}
}


int main()
{

	int arr[] = {100,90,15,-100,1,35,200};
	
	int high = sizeof(arr)/sizeof(arr[1]);
	
	QuickSort(arr,0,high-1);
	
	for(int i= 0 ; i<high;i++)
	{
		printf("%d->\t",arr[i]);
	}
	
	return 0;
	
}

