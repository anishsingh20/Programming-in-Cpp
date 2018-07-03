#include<iostream>
#include<string.h>
#include<cstdlib>

using namespace std;


//Brute force , Dynamic programming using a 2-D boolean matrix which keeps true or false for substring
 
string longestPalindrome(string s) {
        
   int n = s.length();
  int longestBegin = 0;
  int maxLen = 1;
  bool table[1000][1000] = {false};
  for (int i = 0; i < n; i++) {
    table[i][i] = true;
  }
  for (int i = 0; i < n-1; i++) {
    if (s[i] == s[i+1]) {
      table[i][i+1] = true;
      longestBegin = i;
      maxLen = 2;
    }
  }
  for (int len = 3; len <= n; len++) {
    for (int i = 0; i < n-len+1; i++) {
      int j = i+len-1;
      if (s[i] == s[j] && table[i+1][j-1]) {
        table[i][j] = true;
        longestBegin = i;
        maxLen = len;
      }
    }
  }
  return s.substr(longestBegin, maxLen);
	
	
       
}
//T(n) = O(n*n)

bool isPalindrome(string s)
{
	int i = 0 , j = s.size()-1;
	
	while(s[i]==s[j])
	{
		i++;
		j--;
	}
	
	if(i < j) return false;
	
	else return true;
}

int LongestPalindromicSubstring(string a)
{
	int maxCount=0;
	int size = a.size();
	for(int i = 0 ; i < size ; i++ )
	{
		
		for(int j = i ;  j <= size ; j++)
		{
				
			string sub = a.substr(i,j);
			if(isPalindrome(sub) && sub.size() > maxCount)
			{
				maxCount = sub.size();
			
			}
				
		
		}
	}
		
	return maxCount;
}

//brute force
string PrintLongestPalindromicSubstring(string a)
{
	int maxCount=0;
	int size = a.size();
	string subst=" ";
	for(int i = 0 ; i < size ; i++ )
	{
		
		for(int j = i ;  j <= size ; j++)
		{
				
			string sub = a.substr(i,j);
			if(isPalindrome(sub) && sub.size() > maxCount)
			{
				maxCount = sub.size();
				subst = sub;
			}
				
		
		}
	}
	
	return subst;
}
//O(n*n*n)


int main()
{
//	string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
//	cout<<PrintLongestPalindromicSubstring(s);
//	cout<<endl;
//	cout<<LPS_DP(s);
	
	


	return 0;
}
