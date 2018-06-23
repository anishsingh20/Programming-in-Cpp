#include<iostream>


using namespace std;

int Max(int a,int b , int c)
{
    if(a >= b && a >= c) return a;
    
    else if(b >= a && b >= c) return b;
    
    else return c;
}   
    
    
    
    
//simplified method to find maximum sum of continious subarray-
int maxSumSubarraySimple(int nums[],int size)
{
	int curSum = nums[0];
	int maxSum = nums[0];
	
	for(int i = 1; i < size ; i++)
	{
		curSum = max(nums[i],nums[i]+curSum);
		
		maxSum = max(maxSum,curSum);
	}
	
	return maxSum;
}    
    
int maxSubArrayDnQ(int nums[],int start,int end)
{
     int leftBorderSum = 0,rightBorderSum = 0 , maxLeftBorderSum = INT_MIN , maxRightborderSum = INT_MIN;
        
        //base case
        if(start==end)
        {
            return nums[start];
        }        
        
        
        int mid = start + (end-start)/2;
        
        int leftSum = maxSubArrayDnQ(nums,start,mid);
        int rightSum = maxSubArrayDnQ(nums,mid+1,end);

        for(int i = mid ; i >= start ; i--)
        {
            leftBorderSum += nums[i];
            
            if(leftBorderSum > maxLeftBorderSum)
            {
            	maxLeftBorderSum = leftBorderSum;
            
	    }
                    
        }
        
        
        for(int j = mid+1 ; j <= end ; j++)
        {
            rightBorderSum += nums[j];
            
            if(rightBorderSum > maxRightborderSum )
            {
            	maxRightborderSum = rightBorderSum;
            	
	    }
                    
        }
        
        return Max(leftSum,rightSum,max(maxLeftBorderSum,maxRightborderSum));
}
    
    
int maxSubArray(int arr[],int n) {
        
        return maxSubArrayDnQ(arr,0,n-1) ;
       
        
}
    
    
int main()
{
	int arr[] = {-1,2,3,-2};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
//	cout<<maxSubArray(arr,size);

	cout<<maxSumSubarraySimple(arr,size-1);
}
