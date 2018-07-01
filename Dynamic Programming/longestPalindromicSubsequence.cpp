#include<iostream>

using namespace std;

/*Finding longest length of palindromic subsequence using LCS

*/

//Naive recursive approach to find LCS
int LCS(char *a,char *reva,int n,int m)
{
	//base case
	if(n==0 || m==0)
		return 0;
		
	else if(a[n-1]==reva[m-1])
		return 1 + LCS(a,reva,n-1,m-1);
		
	else return max(LCS(a,reva,n-1,m),LCS(a,reva,n,m-1));
}



//function to find length of longest palindromic subseq where we reverse the string and pass it to LCS function
int LPS(char *a)
{
	//reverse of string a
	char *rev;
	int i = 0,j = strlen(a)-1;
	int size = strlen(a);
	int sizerev;
	
	while(i<=j)
	{
		rev[i++] = a[j--]; 
	}
	
	sizerev = strlen(rev);
	
	int len = LCS(a,rev,size,sizerev)
	
	return len;
}



int main()
{
	
	
	return 0;
}
