#include<iostream>

using namespace std;

/*array rotation
1)Rotating one by one
2)Reversal algorithm
*/


void reverseArr(int arr[],int start,int end)
{
	while(start < end)
	{
		swap(arr[start++],arr[end--]);
		
	}
}

void RotateSimpleClock(int arr[],int d,int n)
{
	reverseArr(arr,n-d,n-1);
	
	reverseArr(arr,0,n-d-1);
	
	reverseArr(arr,0,n-1);
	
	for(int i = 0 ; i < n ; i++)
	{
		cout<<arr[i]<<" ";
	}
}


void RotateSimpleAntiClock(int arr[],int d,int n)
{
	reverseArr(arr,0,d-1);
	
	reverseArr(arr,d,n-1);
	
	reverseArr(arr,0,n-1);
	
	for(int i = 0 ; i < n ; i++)
	{
		cout<<arr[i]<<" ";
	}
}


void Rotate(int arr[],int d,int n)
{
	int temp[d];
	//copying items in a temp array
	for(int i = 0 ; i < d; i++)
	{
		temp[i] = arr[i];
		
	}
	
	for(int i = 0 ; i < n ;i++)
	{
		arr[i] = arr[i+d];
	}
	
	for(int i = 0 ; i < d ; i++)
	{
		arr[n] = temp[i];
	}
	
	for(int i = 0 ; i < n ; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	
}

void leftRotateByOne(int arr[],int n)
{
	int temp = arr[0],i;
	
	for(i = 0 ; i < n-1 ;i++)
	{
		arr[i] = arr[i+1];
	}
	
	arr[i] = temp; //now first element is added to the last
}


void RightRotateByOne(int arr[],int n)
{
	int temp = arr[n-1],i;
	
	for(i = n-1 ; i > 0 ; i--)
	{
		arr[i] = arr[i-1];
	}
	
	arr[i] = temp;
	
}
void RotateEffi(int arr[],int d,int n)
{
	for(int i = 0 ; i < d;i++)
		RightRotateByOne(arr,n);
		
	for(int j = 0 ; j < n ; j++)
	{
		cout<<arr[j]<<" ";
	}
}
//T(n) = O(n*d)

rotate()
int main()
{
	int arr[]  = {1,2,3,4,5,6,7};
	int size = sizeof(arr)/sizeof(arr[0]);
	RotateSimpleClock(arr,2,size);
	cout<<endl;
	
	int arr1[]  = {1,2,3,4,5,6,7};
	RotateSimpleAntiClock(arr1,2,size);
	return 0;
}
