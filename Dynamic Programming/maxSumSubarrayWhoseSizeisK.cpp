#include<iostream>

using namespace std;


//program to find maximum subarray sum whose size equals k

int maxSum(int arr[],int size,int k)
{
    int Max = 0,curMax;
     for(int i = 0 ; i < (size-k) ; i++)
     {
    
        curMax = 0;
        for(int j = i ; j <= k ; j++)
        {
            curMax += arr[j];
        
            if(curMax > Max)
                 Max = curMax;
        }
        
     }
    
    return Max;     
}   

int minSum(int arr[],int size,int k)
{
    int Min = INT_MAX,curMin;
     for(int i = 0 ; i <= (size-k) ; i++)
     {
    
        curMin = 0;
        for(int j = i ; j < i+k ; j++)
        {
            curMin += arr[j];
        
            if(curMin < Min)
                 Min = curMin;
        }
        
     }
    
    return Min;     
}   


int main()
{
	int arr[] = {3,4,6,7,-10};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<maxSum(arr,size,2);
	
	cout<<endl<<minSum(arr,size,2);
	
	return 0;
}
