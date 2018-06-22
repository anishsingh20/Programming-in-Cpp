#include<iostream>
#include<stack>
#include<queue>

using namespace std;

/*Program to shuffle an array of size 2n, into format a1 b1 a2 b2 a3 b3 a4 b4 etc without using extra memory.
This problem is similar to the queue interleaving problem- eg 1 2 3 4 5 6 7 8  = 1 5 2 6 3 7 4 8.

1)Using divide and conquer
2) using extra space -using queue interleaving solution
*/

void ShuffleArray(int *arr,int l , int h)
{
	//finding mid index 
	int mid = l + (h-l)/2; //mid index
	int prev= l +(mid-l)/2;//
	
	//base case
	if(l==h) return;
	
	cout<<mid<<" "<<prev<<endl;
	
	for(int k = 1 , i = prev + 1  ; i <= mid  ; i++,k++)
	{
		swap(arr[i],arr[mid+k]);
	}
	
	ShuffleArray(arr,l,mid);//recursively call the function on lower half
	
	ShuffleArray(arr,mid+1,h);//recursively call the function on right half
}
//T(n) = O(nlogn), space  = O(n) for recursion call stack

void Enqueue(queue<int>&q,int data) {
	
	q.push(data); //simply Enqueue data into queue from front
	
}


void display(queue<int>q)
{
	if(q.empty()) {
		cout<<"Queue is Empty"<<endl;
		return;
	}
	
	while(!q.empty()) {
		
		cout<<" | "<<q.front()<< " | ";
		q.pop();
	}	
	
	
}

int Dequeue(queue<int>&q) {
	
	if(q.empty()) {
		cout<<"Queue is empty"<<endl;
		return 0;
	}
	cout<<"\n";
	//now dequeue from the front of queue
	int item=q.front();
	q.pop();
	
	return item;
	
}

void ShuffleArrayUtil(int arr[],queue<int>&q,stack<int>&s)
{
	
	
	int mid =(q.size()/2); //mid index
	
	for(int i = 0 ; i < mid ; i++)
	{
		int item = q.front();
		q.pop();
		s.push(item);
		
	}
	
	while(!s.empty())
	{
		int item = s.top();
		s.pop();
		q.push(item);
		
	}
	
	for(int i = 0 ; i <  mid; i++)
	{
		int item = q.front();
		q.pop();
		q.push(item);
		
	}
	
	for(int i = 0 ; i < mid;i++)
	{
		int item = q.front();
		q.pop();
		s.push(item);
		
	}
	
	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
		
		q.push(q.front());
		q.pop();
	}
	
	display(q);
	
	
	
}

void ShuffleUsingQueue(int arr[])
{
	queue<int>q;
	stack<int>s;
	
	//populating queue
	
	int size = sizeof(arr)/sizeof(arr[0]);
	if(q.empty())
	{
		for(int i = 0 ;  i < size-1 ; i++)
		{
			q.push(arr[i]);
		}
		
	}
	
	
	ShuffleArrayUtil(arr,q,s);
}



int main()
{
	int arr[] =  {1,2,3,4,5,6,7,8};
	int size  = (sizeof(arr)/sizeof(arr[0]));

	
	ShuffleUsingQueue(arr);
	
	
}
