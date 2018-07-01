#include<iostream>


using namespace std;
/*longest common subsequence problem-
1)Brute force - T(n) = O(n*2^n)

2)recursion - T(n) = O(2^n)- has overlapping subproblems which are computed repetedly.

3)DP = T(n) = O(n*n) -Most efficient
*/



//DP solution-efficient)By making a 2-D table which contains the length of subsequence-
int LCS_DP(string &a,string &b,int m,int n)
{
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




//recrsive implementation
int LCS(string &a,string &b,int n,int m)
{
	
	
	//base case when we reach start of strings
	if(m==0 || n==0)
		return 0;
	
	//if found common chars
	else if(a[n-1]==b[m-1]) 
		return 1 + LCS(a,b,n-1,m-1);
	
	//if not common seq found
	else
		return max(LCS(a,b,n-1,m),LCS(a,b,n,m-1));
		
	
	
	
		
	
} //T(n) = O(2^n) exponential algorithm-and so a string of length n has 2^n different possible sub-seq.


int main()
{
	string a  = "cbbd";
	string  b = "dbbc";
	
	int n = a.size();
	int m = b.size();
	
	cout<<LCS(a,b,n,m);
	cout<<endl;
	cout<<LCS_DP(a,b,n,m);
	return 0;
}
