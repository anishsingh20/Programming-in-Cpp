#include<iostream>
#include<set>

using namespace std;

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
            	cout<<s[j]<<endl;
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
	
	
	cout<<lengthOfLongestSubstring("abcbcad");
	return 0;
}
