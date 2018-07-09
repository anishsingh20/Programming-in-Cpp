#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

//longest repeating subsequence
string LRS(string a,int m)
{
	int table[m+1][m+1];
	
	 for (int i=0; i<=m; i++)
        	for (int j=0; j<=m; j++)
           		 table[i][j] = 0;
	
	for(int i = 1 ; i <= m;i++)
	{
		for(int j = 1 ; j<= m;j++)
		{
			if(i==0||j==0)
				table[i][j] = 0;
				
			else if(a[i-1]==a[j-1] && i!=j)
				table[i][j] = table[i-1][j-1] + 1;
			
			else table[i][j] = max(table[i-1][j],table[i][j-1]);
		}
	}
	
	
	
	int i = m,j=m;
	string lrs= " ";
	while(i>0 && j>0)
	{
		if(table[i][j]==table[i-1][j-1]+1)
		{
			lrs = lrs + a[i-1];
			
			i--;
			j--;
			
		}
		
		else if(table[i][j] == table[i-1][j])
			i--;
			
		else
			j--;
	}
	
	reverse(lrs.begin(),lrs.end());
	return lrs;
}


int main()
{
	
	
	string s1 = "AABEBCDD";
	int len = s1.length();
	
	cout<<LRS(s1,len);	
}
