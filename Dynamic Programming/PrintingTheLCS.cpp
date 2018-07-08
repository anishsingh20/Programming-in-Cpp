#include<iostream>


using namespace std;

//Program to print the LCS using DP


//DP solution-efficient)By making a 2-D table which contains the length of subsequence-
void PrintLCS(string &a,string &b,int m,int n)
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
	int LCSlen =  L[m][n];
	
	//getting the length of LCS
	//making the array to store the common letters
	string LCS(LCSlen+1,'\0');
	
	int i = m , j = n;
	
	while(i > 0 && j >0)
	{
		if(a[i-1]==b[j-1])
		{
			LCS[LCSlen-1] = a[i-1];
			i--; j--; LCSlen--;
		}
		
		//go in direction of larger value
	 	if(L[i-1][j] > L[i][j-1])  
		 	i-- ;
		 	
		 else j--;
		
		
	}
	
	
	cout<<LCS;
}




int main()
{
	string a  = "AGGTAB";
	string  b = "GXTXAYB";
	
	int n = a.size();
	int m = b.size();
	
	PrintLCS(a,b,n,m);
	
}
