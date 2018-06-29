#include<iostream>


using namespace std;

//Program to print the LCS using DP


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
			else if(a[i]==b[j])
				L[i][j] = L[i-1][j-1] + 1;
				
			else L[i][j] = max(L[i-1][j],L[i][j-1]);
				
		}
	}
	
	//max length stored in last index
	return L[m][n];
}
//T(n) = O(mn) which is very efficient

