#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

using namespace std;

//function to transform a string to uppercase in ranges
string Uppercase(string s,int start , int end)
{
	string up = s;
	transform(up.begin()+start, up.begin()+end, up.begin()+start, ::toupper);
	
	return up;

}

int SpecialSub(string s)
{
	vector<string>sub;
	int len = s.length();
	string subs="";
	for(int i = 0 ; i < len ; i++)
	{	
		subs ="";
		for(int j = 1 ; j <= len-i; j++)
		{
			subs = s.substr(i,j);
			sub.push_back(subs);	
		}
	}
	
	string up=s;
	string ups ="";
	for(int i = 0 ; i < len ; i++)
	{	
		ups="";
		for(int j = 1 ; j <= len-i; j++)
		{
			ups = s.substr(i,j);
			string upper = "";
			int len = ups.size();
		
			for(int k = 0;k < len;k++)
			{
				for(int l = 1; l <= len-i ;l++)
				{
					upper = Uppercase(ups,k,l);
			
					sub.push_back(upper);	
				}
			
			}
			
			
	
		}
		
	
		

	}
	
	for(int i = 0 ; i < sub.size();i++)
	{
		cout<<sub[i]<<" ";
	}
	
	return sub.size();
}



void SpecialSubMain(string s)
{
	int lower = SpecialSub(s);
	
	cout<<lower;
	
}


int binomEfficient(int n,int k)
{
	int res = 1;
	
	if(n==k)
		return 1;
	if(k==1)
		return n;
		
	//if  k > n-k then  k = n-k as // Since C(n, k) = C(n, n-k)
	if( k > n-k)
		k = n-k;
	
	//calculating C(n,k) =  n!/ (n-k)! * k!
	for(int i = 0 ; i < k ; i++)
	{
		res *= (n-i);
		
		res /=  (i+1);
	}
	
	return res;
		
} //Time complexity = O(k) and aux space  = O(1)


//void Special(string s)
//{
//	int i=0;
//	int j=1;
//	cout << s.substr(i,j);
//	j++;
//	Special(s.substr)
//}




int main()
{

	SpecialSubMain("ab");

	
	cout<<num;

}
