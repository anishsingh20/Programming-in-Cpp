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


//Method-1 Linear method with linear comparisons
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



//Method 2  - DIVIDE AND CONQUER based on TOURNAMENT METHOD
//Divide the array into two parts and compare the maximums and minimums of the the two parts to 
//get the maximum and the minimum of the the whole array.
struct minMax FindMaxMinDivide(int *arr,int low,int high)
{
	struct minMax p,mml,mmr;
	//if size of array is 1
	if(low==high)
	{
		p.maxi = p.mini  = arr[low];
		return p;
	}
	
	//if size of array is 2
	if(high == low+1)
	{
		if(arr[low] < arr[high])
		{
			p.maxi = arr[high];
			p.mini = arr[low];
		}
		else
		{
			p.maxi = arr[low];
			p.mini = arr[high];
		}
		
		return p;
		
	}
	
	//otherwise find the middle index.
	int mid = low + (high-low)/2;
	
	 mml = FindMaxMinDivide(arr,low,mid);//left half
	 mmr = FindMaxMinDivide(arr,mid+1,high);//right half
	
	//now comparing the minimums in left and right subarrays
	if(mml.mini < mmr.mini)
	{
		p.mini  = mml.mini;
	}
	
	else 
		p.mini = mmr.mini;
	
	
	//comparing the maximums in left and right halves
	if(mml.maxi > mmr.maxi)
		p.maxi = mml.maxi;
		
	else 
		p.maxi = mmr.maxi;
	
	
	return p;
	
} //TIME COMPLEXITY  = 2T(n/2) + 2 and after solving this recurrence relation T(n) =  O(logn)



/*Method 3- compare in pairs-
algorithm-
If n is odd then initialize min and max as first element.
If n is even then initialize min and max as minimum and maximum of the first two elements respectively.
For rest of the elements, pick them in pairs and compare their
maximum and minimum with max and min respectively.
*/

struct minMax minMaxCompare(int *arr,int n)
{
	struct minMax m;
	int i=0;
	
	//if array has even number of elements
	if(n%2==0)
	{
		if(arr[0]>arr[1])
		{
			m.maxi = arr[0];
			m.mini = arr[1];
		}
		
		else
		{
			m.maxi = arr[1];
			m.mini = arr[0];
		}
		
		//set i = 2 for the loop
		i = 2;
	}
	
	//if odd no of elements-
	/* If array has odd number of elements then 
    	initialize the first element as minimum and 
    	maximum */
	else
	{
		m.maxi = arr[0];
		m.mini = arr[0];
		
		i=1; //setting the starting index for loop
		
	}
	
	
	while(i < n-1)
	{
		if(arr[i] > arr[i+1])
		{
			if(arr[i] > m.maxi)
			{
				m.maxi  = arr[i];
				
			}
			
			if(arr[i+1] < m.mini)
				m.mini  = arr[i+1];
			
		}
		
		else
		{
			if(arr[i+1] > m.maxi)
				m.maxi = arr[i+1];
			if(arr[i] < m.mini)
				m.mini = arr[i];
		}
		
		i = i +  2;
		
	}
	
	
	return m;
}

int main()
{
	int arr[] = {1000, 11, 445, 1, 330, 3000};
	int size = sizeof(arr)/sizeof(arr[0]);
//	struct minMax p  =  findMinMax(arr,0,size-1);
	struct minMax c  = minMaxCompare(arr,size-1);
	
	cout<<c.maxi<<endl;
	cout<<c.mini<<endl; 
}
