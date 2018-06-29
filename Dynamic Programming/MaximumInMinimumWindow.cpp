#include<iostream>

using namespace std;

//program for finding maximum in minimum window of sie 1 to n(size of array)

//Brute force-O(n*n*n) considering each window one by one.


void MaxInMinWindow(int arr[],int size)
{
	
	//window i starting from 1 to n
	for(int i = 1 ; i <= size ; i++)
	{
		int MaxofMin = INT_MIN;
		
		for(int j = 0 ; j  <= size-i ; j++ )
		{
			//minimum in current window
			int minInWin = arr[j];
			for(int k = 1 ; k < i ;k++)
			{
				//minimum of current window
				if(arr[j+k] < minInWin)	
					minInWin = arr[j+k];
			}
			
			//updating max of minimum window
			if(minInWin > MaxofMin)
				MaxofMin = minInWin;
		}
		
		cout<<MaxofMin<<" ";
	}
}

//T(n) = O(n*n*n)-ineffcient

// Driver program
int main()
{
    int arr[] = {10, 20, 30, 50, 10, 70, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    MaxInMinWindow(arr,n);

	return 0;
}
