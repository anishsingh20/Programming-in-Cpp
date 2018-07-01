#include<iostream>

using namespace std;



//Using Dp
int MaxSumDp(int arr[],int size)
{
	int dp[size];
	
	//for case when first item is negetive
	dp[0] = arr[0] > 0 ? arr[0]  : 0;
 	dp[1] = max(arr[0],arr[1]);
	int maxSum = arr[0];
	
	for(int i = 2 ; i < size ; i++)
	{
		dp[i]  = max(dp[i-1],dp[i-2]+arr[i]);
	}
	
	for(int i = 0 ; i < size ; i++)
	{
		if(maxSum < dp[i])
		{
			maxSum = dp[i];
		}
	}
	
	return maxSum;
}
//T(n) = O(n), space  = O(n) for the aux array



//Iterative solution
int MaxSum(int arr[],int size)
{
	int mSum = 0,curSum = 0;
	for(int i = 0 ; i < size; i++)
	{
		curSum = 0;
		for(int j = i ; j < size ; j+=2)
		{
			curSum += arr[j];
			
			if(curSum > mSum)
				mSum = curSum;
		}
	}
	
	return mSum;
}//T(n) = O(n*n) , and space = O(1)


//int MaxSumSimple(int arr[],int size)
//{
//	int curSum = arr[0] ;
//	int mSum = INT_MIN;
////
//	for(int i = 2 ; i < size ; i++)
//	{
//		curSum = max(arr[i]+curSum,arr[i-1]);
//		
//		mSum = max(mSum,curSum); 
//	}
//	
//	return mSum;
//	
//	
//}

int main()
{
	int arr[] = {1,2,3,6,7};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<MaxSum(arr,size);

	cout<<endl;
	cout<<MaxSumDp(arr,size);
	
	return 0;
}
