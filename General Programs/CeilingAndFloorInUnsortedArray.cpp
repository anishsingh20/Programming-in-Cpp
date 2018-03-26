#include<iostream>


using namespace std;


/*Program to find Ceiling and floor in an unsorted array
Algorithm-
The idea is to traverse array and keep track of two distances with respect to x.
1) Minimum distance of element greater than or equal to x.
2) Minimum distance of element smaller than or equal to x.
Finally print elements with minimum distances.


*/
int f=0 ,c=0;

void floorAndCeil(int *arr,int key, int n)
{
    
    
 
    // Distances of current floor and ceiling
    int fDist = INT_MAX, cDist = INT_MAX;
 
    for (int i=0; i<n; i++)
    {
        // If current element is closer than
        // previous ceiling.
        if (arr[i] >= key && cDist > (arr[i] - key))
        {
           c = arr[i];
           cDist = arr[i] - key;
        }
 
        // If current element is closer than
        // previous floor.
        if (arr[i] <= key && fDist > (key - arr[i]))
        {
           f = arr[i];
           fDist = key - arr[i];
        }
    }
    
    
}//Time complexity = O(n) and space complexity = O(1)


int main()
{
	int arr[ ] = {9,1,23,2,10,8};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	floorAndCeil(arr,20,size-1);
	
	cout<<"Floor is: "<<f<<endl;
	cout<<"Ceiling is: "<<c<<endl;
}
