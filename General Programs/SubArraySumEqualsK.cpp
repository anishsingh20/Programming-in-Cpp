#include<iostream>
#include<vector>

using namespace std;

//program to find number of  subarrays whose sum equals K

//brute force appraoch
//int subarraySum(vector<int>& nums, int k) {
//        
//       
//       int count = 0 ; 
//        for(int i = 0 ; i < nums.size() ; i++)
//        {
//            for(int j = i+1 ; j < nums.size(); j++)
//            {
//                int sum = 0 ;
//                for(int m = i ; m < j ; m++)
//                {
//                    sum += nums[m];
//                    
//                    if(sum == k)
//                    	count++;    	
//                }
//            }
//            
//        }
//        
//        return count;
//}

int subarraySum(vector<int>& nums, int k) {
        
      int count = 0 ;
        
        for(int i = 0 ; i < nums.size(); i++)
        {
            int sum = 0 ;
            for(int j = i ; j < nums.size(); j++)
            {
                sum += nums[j];
                if(sum == k)
                        count++;
            }
        }
        
        return count;
    }
//T(n) = O(n*n),space = O(1)

int main()
{
	vector<int> v;
	
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	
	cout<<subarraySum(v,2);	
	
}
