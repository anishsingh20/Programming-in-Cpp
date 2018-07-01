#include<iostream>
#include<algorithm>

using namespace std;


string longestPalindrome(string s) {
        
        string rev = s;
        int m = s.size();
        int n = rev.size();
        reverse(rev.begin(),rev.end());
        
    int L[m+1][n+1]; //a 2-d table
	
	for(int i = 0 ; i  <= m ; i++)
	{
		for(int  j = 0 ; j <= n ;j++)
		{
			if(i==0 || j==0)
				L[i][j] = 0;
			
			//if same char found-increase the length by 1
			else if(s[i-1] == rev[j-1])
				L[i][j] = L[i-1][j-1] + 1;
				
			else L[i][j] = L[i-1][j-1];
				
		}
	}
        
        int len = L[m][n];
        
        string LPS(len+1,'\0');
        
        int i = 0 ,j = 0;
        while(i < m   && j < n )
        {
            if(s[i]==rev[j])
            {
                LPS[len-1] = s[i];
                i++; j++; len--;
            }
            
            else if(L[i+1][j] > L[i][j+1] ) i++;
            
            else j++;
        }
        
        return LPS;
        
}
//T(n) = O(n*n) efficient,similar to printing LCS
    
    
int main()
{
	
	cout<<longestPalindrome("nitin");
	return 0;
}
