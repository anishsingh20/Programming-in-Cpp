#include<iostream>


using namespace std;

/*
1)method1 -simplified O(n) time and O(1) space;
2)Using DP with 2 arrays to store max subarray product and min subarray products
3)Brute force-Using 2 loops and checking every subarray possible
*/


int MaxPro(int arr[],int size)
{
    int curMax = arr[0],curMin = arr[0];
    int result = arr[0];
    
    for(int i = 1; i < size ; i++)
    {
        if(arr[i] < 0)
            swap(curMax,curMin);
            
        curMax = max(arr[i],arr[i]*curMax);
        
        curMin = min(arr[i],arr[i]*curMin);
        
        result = max(result,curMax);
    }
    
    return result;
}
//T(n) = O(n)

int MaxProDP(int arr[],int size)
{
	int dpmax[size+1];
	int dpmin[size+1];
	dpmax[0] = arr[0];
	dpmin[0] = arr[0];
	
	int maxPro = arr[0];
	
	for(int i =1 ; i < size ; i++)
	{
		//if negetive input,swap the max and mins of array
		if(arr[i]< 0)
			swap(dpmax[i-1],dpmin[i-1]);
			
		
		//extending the array
		dpmax[i] = max(arr[i],dpmax[i-1]*arr[i]);
		
		dpmin[i] = min(arr[i],dpmin[i-1]*arr[i]);
		
		
		maxPro = max(dpmax[i],maxPro);
	}
	
	return maxPro;
}//T(n) = O(n)

int MaxProBrute(int arr[],int size)
{
	int max = INT_MIN;
	
	int pro;
	
	for(int i = 0  ; i < size; i++)
	{
		pro = 1;
		
		for(int j = i ; j < size; j++)
		{
			pro *= arr[j];
			
			if(pro > max)
				max = pro;
		}
	}
	
	return max;
}

int main()
{
	int arr[] = {0,0,-1,-4};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	cout<<MaxProBrute(arr,size);
	
	return 0;
}
