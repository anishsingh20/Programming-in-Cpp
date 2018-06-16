#include<iostream>

using namespace std;

 string reverseVowels(string s) {
        int i = 0 ;
        int j = s.size()-1;
        
        
        
        while(i<j)
        {
            if(s[i]=='a' || s[i]=='e' || s[i] == 'i' || s[i]=='o' || s[i]=='u')
            {
                if(s[j]=='a' || s[j]=='e' || s[j] == 'i' || s[j]=='o' || s[j]=='u')
                {
                    swap(s[i++],s[j--]);
                }
                else
                {
                    j--;
                }
            }
            
            else
            {
                i++;
               
            }
        }
        
        return s;
    }
    
    
int main()
{
	cout<<reverseVowels("leetcode");
	return 0;
}

