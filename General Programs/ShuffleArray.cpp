#include<iostream>


using namespace std;

/*Program to shuffle an array of size 2n, into format a1 b1 a2 b2 a3 b3 a4 b4 etc without using extra memory.
This problem is similar to the queue interleaving problem- eg 1 2 3 4 5 6 7 8  = 1 5 2 6 3 7 4 8.
*/


void ShuffleArray(int *arr,int l , int h)
{
	//finding mid index 
	int mid = l + (h-l)/2; //mid index
	int prev= l +(mid-l)/2;//
	
	//base case
	if(l==h) return;
	
	cout<<mid<<" "<<prev<<endl;
	
	for(int k = 0 , i = prev  ; i < mid  ; i++,k++)
	{
		swap(arr[i],arr[mid+k]);
	}
	
	ShuffleArray(arr,l,mid);//recursively call the function on lower half
	
	ShuffleArray(arr,mid+1,h);//recursively call the function on right half
}

int main()
{
	int arr[] =  {1,2,3,4,5,6,7,8};
	int size  = (sizeof(arr)/sizeof(arr[0]));
	
	ShuffleArray(arr,1,size);
	
	for(int i = 0 ; i < size ; i++)
	{
		cout<<arr[i]<<" ";
	}
	
}
