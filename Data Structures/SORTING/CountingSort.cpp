#include<iostream>
#include<cstring>

#define RANGE 255
//ascii range 

using namespace std;

/*Counting sort which is a non-comparison based sorting technique used for data which is in a specific range.
ALGORITHM-
1)It  works by counting the number of distinct objects (kind of hashing)
2)Then making a count array to store the count of each object.
3)Then performing some airthmetic to calculate the position of each object in output sequence.

4)COUNTING SORT is a STABLE SORTING ALGORITHM.
5)TIME COMPLEXITY  = O(n+k) , S(n) = O(n+k) , n=no of items to sort, k  = range of data
6)It is only efficient when the range of data is significantly equivalent to the number of items to sort.
i.e it is highly inefficient when the range of data is very large than the number of objects to be sorted.
7) COunting sorts beats the lower bound of comparison based sorting algorithms with comparisons proportional to O(nlogn), whereas in Counting sort
it is proportional to O(n).
*/


void CountSort(char *arr)
{
	//the output array will have sorted array
	char output[strlen(arr)];
	
	//create a count array to store count of all objects
	//here range represents the ASCII range
	int count[RANGE+1],i;
	memset(count, 0, sizeof(count));
	
	//store count of each character
	for(i = 0 ; arr[i] ; i++)
	{
		++count[arr[i]];
	}
	                               
	//updating count with the sum of previous counts of elements
	for(i = 1; i<=RANGE;i++)
	{
		count[i] += count[i-1]; 
	}
	
	//building the output array
	for(i=0; arr[i] ; ++i)
	{
		output[count[arr[i]]-1] = arr[i];
		--count[arr[i]];
	}
		
	
	for(i=0;arr[i];++i)
		arr[i] = output[i];
		
}


int main()
{
	char c[] = "zdecdea";
	
	
	
	//sorting a char array within range 0 to 255
	CountSort(c);
	
	cout<<c;
	

	
	
	
	
	
}
