#include<iostream>
#include<vector>

using namespace std;

//Program to find the starting and ending index of subarray whose sum equals K


void subarraySum(vector<int>& nums, int k) {
        
      int count = 0 ;
        
        for(int i = 0 ; i < nums.size(); i++)
        {
            int sum = 0 ;
            for(int j = i ; j < nums.size(); j++)
            {
                sum += nums[j]; //the cumalative sums of each subarray
                if(sum == k)
                {
                	cout<<i<<","<<j<<endl;
                	
		}
                        
            }
        }
        
        
    }
//T(n) = O(n*n),space = O(1)



int main()
{
	vector<int> v;
	
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	
	subarraySum(v,3);	
	
}


