#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

/*Finding longest length of palindromic subsequence using LCS
1)Simply make a function to find LCS of 2 strings using DP
2) Use function LCS as a subroutine call in another function LPS which simply reverses the string
and passes both of them as arguments in LCS subroutine.

As LCS of the reverse of a string and that string will give us LPS 

*/

//Naive recursive approach to find LCS
int LCS(string a,string reva,int n,int m)
{
	//base case
	if(n==0 || m==0)
		return 0;
		
	else if(a[n-1]==reva[m-1])
		return 1 + LCS(a,reva,n-1,m-1);
		
	else return max(LCS(a,reva,n-1,m),LCS(a,reva,n,m-1));
}


int LCS_DP(string &a,string &b)
{
	int m = a.size();
	int n = b.size();
	int L[m+1][n+1]; //a 2-d table
	
	for(int i = 0 ; i  <= m ; i++)
	{
		for(int  j = 0 ; j <= n;j++)
		{
			if(i==0 || j==0)
				L[i][j] = 0;
			
			//if same char found-increase the length by 1
			else if(a[i-1]==b[j-1])
				L[i][j] = L[i-1][j-1] + 1;
				
			else L[i][j] = max(L[i-1][j],L[i][j-1]);
				
		}
	}
	
	//max length stored in last index
	return L[m][n];
}
//T(n) = O(mn) which is very efficient



//function to find length of longest palindromic subseq where we reverse the string and pass it to LCS function
int LPS(string a)
{
	string rev = a;
	reverse(rev.begin(),rev.end());
	
	return LCS_DP(a,rev);
}
//T(n) = O(n*n) quadratic , very efficnet




int main()
{
	string a = "cbbd";
	
	cout<<LPS(a);
	
	return 0;
}
