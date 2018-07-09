#include<iostream>

using namespace std;

//array rotation

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

int main()
{
	int arr[]  = {1,2,3,4,5,6,7};
	int size = sizeof(arr)/sizeof(arr[0]);
	RotateEffi(arr,3,size);
	return 0;
}
