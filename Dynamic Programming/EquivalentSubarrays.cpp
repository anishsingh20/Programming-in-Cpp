#include<iostream>
#include<set>

//program to find equivalent subarrays

using namespace std;

int maxCount(int arr[],int size)
{
    int count = 0 ;
    set<int>s;
    set<int>sub;//to store subarrays
    for(int i = 0 ; i < size ; i++)
    {
        s.insert(arr[i]);
    }
   
    int dis = s.size();
    
    for(int i = 0 ; i < size; i++)
    {
         
        for(int j = i ; j < size;j++)
        {
            sub.insert(arr[j]);
            if(sub.size()==dis)
                    count++;
        }
        
        //clearing the subarray after one complete check
        sub.erase(sub.begin(),sub.end());
            
    }
    cout<<count<<endl;
    
}

int main()
{
	int arr[]= {2,3,2,1,3};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	maxCount(arr,size);
}

