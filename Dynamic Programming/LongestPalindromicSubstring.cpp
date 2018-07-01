#include<iostream>

using namespace std;

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

	cout<<LongestPalindromicSubstring("n");


	return 0;
}
