#include<iostream>

//Finding number of occurences of a number in an sorted array using Binary Search

using namespace std;


//Merge sort to sort the given array

void Merge(int arr[],int start,int mid , int end)
{
	int i,j,k;
	int nl,nr;
	
	//number of elements in L and R arrays
	nl = (mid-start) + 1;
	nr = (end-mid);
	
	mid = (start + (end -start)/2 );
	//new arrays to store the left and right subarrays
	int l[nl],r[nr];
	
	
	//copying items to the subarrays from the orig array
	for(i = 0 ; i < nl ; i++) {
		l[i] = arr[start+i];
	}
	
	for(j= 0 ; j< nr ; j++) {
		
		r[j] = arr[mid + 1 + j];
	}
	
	i=0,j=0,k=start;
	
	
	while( i < nl && j < nr ) {
		
		if(l[i] < r[j]) 
		{
			
			arr[k] = l[i];
			i++;
			
			
		}
		
		else {
			
			arr[k] = r[j];
			j++;
			
		}
		k++;
		
	}
	
	//now copying the left overs in new sorted array
	while( i < nl ) 
	{
		arr[k] = l[i];
		i++;
		k++;
	}

	while( j < nr ) 
	{
		arr[k] = r[j];
		j++;
		k++;
	}	
	
}

void MergeSort(int arr[],int start,int end) {
	
	
	
	if(start < end) {
		
		int mid = (start + (end - start)/2 ) ;
		
		MergeSort(arr,start,mid);
		
		MergeSort(arr,mid+1,end);
		
		Merge(arr,start,mid,end);
	}
}




//Binary search can also be used to find first and last occurences of a repeating number in an array

int BinarySearch(int arr[],int n , int x , bool searchFirst)
{
	int l = 0;
	int h = n-1;
	int result = -1;
	while(l <= h)
	{
		int mid = (l + (h-l)/2);
		
		if(arr[mid]==x) 
		{
			result = mid;
			
			//if want to search for first occurence or a repeating no
			if(searchFirst) {
				//search only in the lower indices
				 h = mid-1;
			}
			//if want to search for the last occurence of a repeating number
			else {
				//search only in the higher indices or right subpart of array
				 l = mid + 1;
			}
		}
		
		//search in higher indices or right subpart of array
		else if(arr[mid] <= x)  l = (mid + 1); 
	
		//search in lower indices or left subpart of array
		 else h =  (mid-1);
		
	}
	
	return result;
}


int main () {
	
	int arr [] = {15,10,2,9,2,8,15,2,3};
	
	
	//sorting the array to apply binary search
	
	MergeSort(arr, 0 , sizeof(arr)/sizeof(arr[0])-1 );
	
	cout<<"Sorted array is:"<<endl;
	
	for(int i = 0 ; i < sizeof(arr)/sizeof(arr[0]);i++) {
		
		cout<<arr[i]<<endl;
	}
	
	//finding the index of the first occurecne of searched number
	int firstOcc = BinarySearch(arr,sizeof(arr)/sizeof(arr[0]), 15 , true);
	
	if(firstOcc==-1) {
		
		cout<<"0 occurence."<<endl;
	}
	
	else {
		//findind the index of the last occurence of the searched number
		int lastOcc = BinarySearch(arr,sizeof(arr)/sizeof(arr[0]), 15 , false);
		
		cout<<"Count of occurence is :"<<(lastOcc-firstOcc +1)<<endl;
	}
}
