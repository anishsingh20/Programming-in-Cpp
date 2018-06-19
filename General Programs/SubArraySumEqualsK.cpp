#include<iostream>

using namespace std;

//program to find number of  subarrays whose sum equals K

//brute force appraoch
int subarraySum(vector<int>& nums, int k) {
        
       
       int count = 0 ; 
        for(int i = 0 ; i < nums.size() ; i++)
        {
            for(int j = i+1 ; j < nums.size(); j++)
            {
                int sum = 0 ;
                for(int m = i ; m < j ; k++)
                {
                    sum += nums[m];
                    if(sum == k)
                        count++;
                }
            }
            
        }
        
        return count;
}


int main()
{
	
}
