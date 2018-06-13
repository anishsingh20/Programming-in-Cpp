#include<iostream>
#include<vector>

using namespace std;


//this function returns the new size of the array after removing val
int RemoveItem(int *nums,int val,int size)
{
	
	int count=0;
	for(int i = 0 ; i < size; i++)
	{
		if(nums[i] != val)
		{
			nums[count++] = nums[i];
		}
			
		
	}
	
	return count;
}
	



int main()
{
	int arr[]  =  {1,2,3,3,5,2};
	

	int size = (sizeof(arr)/sizeof(arr[0]));
	
	//ns is the new updated size of the array after removing the items
	int ns = RemoveItem(arr,2,size);
	
	for(int i = 0 ; i < ns ; i++)
	{
		cout<<arr[i]<<endl;
	}
	cout<<endl;
	
	
	
	return 0;
}
