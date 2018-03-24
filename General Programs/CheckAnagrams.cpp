#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

/*Program to check whether to strings are anagrams or not-

1)Sort the strings.
2)Them compare the sorted strings.

*/
int Partition(char arr[],int start, int end) {
	
	char Pivot = arr[end]; //PIVOT is the right most element of array
	
	int Pindex  =  start; //Pindex initially set to start index of array
	
	//trversing the array
	for(int i = start ; i < end ; i++) 
	{
		if(arr[i] <= Pivot) {
			swap(arr[i],arr[Pindex]);
			Pindex++;
		}	
	}

	swap(arr[end],arr[Pindex]);//swapping PIVOT and element at Pindex
	
	return Pindex;//now at the end Pindex is the index of the PIVOT
}



/*To avoid the worse Case i.e when rearrangements results in unbalanced partitions on left and right of PIVOT
Complexity of Quick sort which results in T(n) = O(n^2) , we use randomized quick sort algorithm, in which
we can select any random element of the array as PIVOT element. This reduces the prob of worst case to 0 , and increases the probability of 
average case complextiy i.e O(nlogn)
*/
int RandomizedPartition(char arr[],int start, int end)  {
	
	//choosing a random number between start and end index of array as Pivot index
	int Pindex = start  + ( std::rand() % ( end - start + 1 ) );
	
	swap(arr[Pindex],arr[end]);
	
	return Partition(arr,start,end);
	
}

//passing address of a vector as argument
void QuickSort(char arr[],int start, int end) {
	
	
		if(start>=end) return;
		
		int Pindex = RandomizedPartition(arr,start,end); //calling partition function to rearrange the elements of array in such a way that 
		// left half has <= PIVOT elements, right half elements > PIVOT.
		
		//recursively calling Quicksort on left half of array
		QuickSort(arr,start,Pindex-1);
		
		//recursively calling Quicksort on right half of array
		QuickSort(arr,Pindex+1,end);
	
}


bool CheckAnagram(char *a,char *b)
{
	int la = strlen(a);
	int lb = strlen(b);
		
	if(la!=lb)
		return false;
	
	//sorting the strings
	QuickSort(a,0,la-1);
	QuickSort(b,0,lb-1);
	
	for(int i = 0 ; i <  la;i++)
	{
		if(a[i]!=b[i])
			return false;
	}
	
	return true;
}

int main()
{
	
	char a[] = "anish";
	
	char b[] = "isnah";
	
	cout<<CheckAnagram(a,b);
	
}
