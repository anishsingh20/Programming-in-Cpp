#include<iostream>
#include<cstring>

#define RANGE 255
//ascii range

using namespace std;

/*Counting sort which is a non-comparison based sorting technique used fot data which is in a specific range.
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
	for(i = 0 ; arr[i];i++)
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
