#include<iostream>


using namespace std;

int *RemoveItem(int *a,int val,int size)
{
	int i=0;
	int count=0;
	for(int i = 0 ; i < size; i++)
	{
		if(a[i]!=val)
			a[count++] = a[i];
		
	}
	
	return *a;
}

int main()
{
	int arr[]  =  {1,2,3,3,5,2};
	
	return 0;
}
