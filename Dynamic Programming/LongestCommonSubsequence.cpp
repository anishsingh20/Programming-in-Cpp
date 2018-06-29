#include<iostream>


using namespace std;
/*longest common subsequence problem-
1)Brute force - T(n) = O(n*2^n)

2)recursion - T(n) = O(2^n)- has overlapping subproblems which are computed repetedly.

3)DP = T(n) = O(n*n) -Most efficient
*/

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
	string a  = "anish";
	string  b = "manish";
	
	int n = a.size();
	int m = b.size();
	
	cout<<LCS(a,b,n,m);
	return 0;
}
