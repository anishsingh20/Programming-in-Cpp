#include<iostream>

//Finding number of occurences of a number in an sorted array using Binary Search

using namespace std;

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
	
	int arr [] = {1,2,2,2,3,3,6,7,9};
	
	
	//finding the index of the first occurecne of searched number
	int firstOcc = BinarySearch(arr,sizeof(arr)/sizeof(arr[0]), 2 , true);
	
	if(firstOcc==-1) {
		
		cout<<"0 occurence."<<endl;
	}
	
	else {
		//findind the index of the last occurence of the searched number
		int lastOcc = BinarySearch(arr,sizeof(arr)/sizeof(arr[0]), 2 , false);
		
		cout<<"Count of occurence is :"<<(lastOcc-firstOcc +1)<<endl;
	}
}
