#include<iostream>
#include<vector>

using namespace std;

//the 2 arrays have equal sizes
int MedianInUnion(vector<int> &v1,vector<int>&v2)
{
	int i = v1.size()-1,j=v2.size()-1;
	int k = i + j -1 ;
	
	
	
	while(i>=0 && j>=0)
	{
	
		v1[k--] = (v1[i] >= v2[j]) ? v1[i--] : v2[j--];		
		
	}	
	
	while(j>=0)
            v1[k--] = v2[j--];
         
	
	int start = 0;
	int end = k;
	
	int mid = start + (end-start)/2;
	for(int i  = start; i < end; i++)
	{
		cout<<v1[i]<<" ";
	}
	
	return v1[mid] ;  
            
	
			
}

int main()
{
	vector<int>v1;
	vector<int>v2;
	
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(5);
	v1.push_back(1);
	
	v2.push_back(9);
	v2.push_back(7);
	v2.push_back(6);
	v2.push_back(10);
	
	MedianInUnion(v1,v2);
}
