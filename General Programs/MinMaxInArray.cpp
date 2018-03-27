#include<iostream>

using namespace std;

/* Program to find min-max in an array
1) linear method
2)Divide and conquer 
*/


struct minMax{
	
	int mini;
	int maxi;
} p;


//MEthod-1 Linear method with linear comparisons
struct minMax findMinMax(int *arr,int low,int high)
{
	
	p.maxi = arr[0];
	p.mini = arr[0];
	
	//if size of array is 1
	if(low==high)
	{
		p.mini = p.maxi = arr[0];
		return p;
	}
	
	
	//if size of arr is 2
	if(arr[0]>arr[1])
	{
		p.maxi = arr[0];
		p.mini = arr[1];
	}
	else{
		p.maxi = arr[1];
		p.mini = arr[0];
	}
	
	
	//otherwise simply search for minimum and maximum
		
		for(int i = 2 ; i < high ; i++)
		{
			if(arr[i] < p.mini)
			{
				p.mini = arr[i];
			}
			
			if(arr[i] > p.maxi)
			{
				p.maxi = arr[i];
			}
		}
		
	
	
	return p;
} 

//TIME COMPLEXITY = O(n),In the above implementation, 
//worst case occurs when elements are sorted in descending order and best case occurs when elements are sorted in ascending order


int main()
{
	int arr[] = { 12,9,1,10,12,15,6};
	int size = sizeof(arr)/sizeof(arr[0]);
	struct minMax p  =  findMinMax(arr,0,size-1);
	
	cout<<p.maxi<<endl;
	cout<<p.mini<<endl; 
}
