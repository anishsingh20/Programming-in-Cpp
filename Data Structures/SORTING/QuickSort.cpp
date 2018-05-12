#include<iostream>
#include<vector>
#include<algorithm>


# define n 6 //size of vector-DYNAMIC ARRAY


using namespace std;
/*PROGRAM FOR QUICK-SORT
TIME COMPLEXITY- WORST CASE - O(n^2) , BEST CASE/AVG CASE - O(nlogn)
SPACE COMPLEXITY - BEST CASE/AVG CASE = O(logn) -recursive call stack , WORSE CASE  = O(n) 
Much more effcient space wise, than MERGE SORT
ALGORITHMIC STRATEGY- DIVIDE AND CONQUER

1)QUICK sort is the best sorting approach for all practical problems, due to its efficiency.
2)Quick sort is an IN-PLACE sorting algorithm, i.e it requires constant amount of extra memory ,sorting without any extra space requirement.
3)Also in worst case scenario of O(n^2) is often ignored due to the RANDOMIZED VERSION OF QUICK SORT which gives the highest probability of O(nlogn)

Another thing is that it does not requires to create new AUX arrays like in Merge Sort to divide the problem into subproblems. 
It does all the re-arrangements in the same array itself. This makes it save some extra memory as compared to MERGE SORT



*/


//passing address of a vector as argument
int Partition(vector<int> &arr,int start, int end) {
	
	int Pivot = arr[end]; //PIVOT is the right most element of array
	
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



/*To avoid the worse Case i.e when the array is completely sorted-when rearrangements results in unbalanced partitions on left and right of PIVOT
Complexity of Quick sort which results in T(n) = O(n^2) , we use randomized quick sort algorithm, in which
we can select any random element of the array as PIVOT element. This reduces the prob of worst case to 0 , and increases the probability of 
average case complextiy i.e O(nlogn)
*/
int RandomizedPartition(vector<int> &arr,int start, int end)  {
	
	//choosing a random number between start and end index of array as Pivot index
	int Pindex = start  + ( std::rand() % ( end - start + 1 ) );
	
	swap(arr[Pindex],arr[end]);
	
	return Partition(arr,start,end);
	
}

//passing address of a vector as argument
void QuickSort(vector<int> &arr,int start, int end) {
	
	
		if(start>=end) return;
		
		int Pindex = RandomizedPartition(arr,start,end); //calling partition function to rearrange the elements of array in such a way that 
		// left half has <= PIVOT elements, right half elements > PIVOT.
		
		//recursively calling Quicksort on left half of array
		QuickSort(arr,start,Pindex-1);
		
		//recursively calling Quicksort on right half of array
		QuickSort(arr,Pindex+1,end);
	
}


int main() {
	
	vector<int> vec(n);	//vector of size n

	//input elements of array
	for(int i = 0 ; i < n ; i++) {
		cin>>vec[i];
		 //insertion from end of vector
	}
	

	
	QuickSort(vec,0,vec.size()-1);
	
	cout<<"Sorted vector is :"<<endl;
	
	vector<int>::iterator i;
	
	for(i = vec.begin(); i != vec.end();i++) {
		cout<<*i<<"\t";
	}
	
	
	return 0;
}
