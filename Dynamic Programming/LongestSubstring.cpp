#include<iostream>
#include<set>

using namespace std;



bool CheckUnique(string s, int start,int end)
{
	set<char>a;
	
	for(int i = start ; i < end ; i++)
	{
		//if item already found in set return false
		if( a.find(s[i]) != a.end()) return false;
		
		else a.insert(s[i]);
 	}
 	
 	return true;

}


//brute force-checking all possible sub strings, and checking if they are unique
int lenOfSubstring(string s)
{
	int n  = s.size();
	int len = 0 ;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = i+1 ; j <= n ; j++)
		{
			if(CheckUnique(s,i,j))  len = max(len,j-i);
		}
	
		
	}
	
	return len;
	
}
//T(n) = O(n*n*n)-inefficient solution-


//using sliding window concept.
int lengthOfLongestSubstring(string s) {
        
       set<char>a;
        
       int i = 0,j = 0 ;
        int len = 0;
        int n = s.size();
        while(i < n && j < n)
        {
            //if set does not containes a char, we simply insert it
            if(a.find(s[j]) == a.end())
            {
            	
                a.insert(s[j++]);
                
                len = max(len,j-i);
            }
            
            //if already exists, then remove a item from set
            else
            {
                a.erase(s[i++]);
            }
                
        }
        
        return len;
        
}//T(n) = O(2n),S(n) = O(n)


int main()
{
	
	
	cout<<lengthOfLongestSubstring("AABEBCDD");
	
	cout<<endl<<lenOfSubstring("AABEBCDD");
	return 0;
}
