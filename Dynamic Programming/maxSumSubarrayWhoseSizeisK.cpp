#include<iostream>

using namespace std;


//program to find maximum subarray sum whose size equals k

int maxSum(int arr[],int size,int k,int i=0)
{
    int Max = 0,curMax;
     for(int i = 0 ; i <= (size-k) ; i++)
     {
    
        curMax = 0;
        for(int j = i ; j < i+k ; j++)
        {
            curMax += arr[j];
        
            if(curMax > Max)
                 Max = curMax;
        }
        
     }
    
    return Max;     
}   


int main()
{
	int arr[] = 
	return 0;
}
