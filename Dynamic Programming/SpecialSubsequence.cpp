#include<iostream>
#include<vector>
#include<cctype>
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
	
	for(int i = 0 ; i < len ; i++)
	{	
		subs ="";
		for(int j = 1 ; j <= len-i; j++)
		{
			subs = s.substr(i,j);
//			subs = Uppercase(subs);
			sub.push_back(subs);	
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
	
//	string upper = Uppercase(s);
//	
//	int upp = SpecialSub(upper);
//	
//	
//	cout<<lower+upp; 
//	

	cout<<lower;
}

int main()
{
//	SpecialSubMain("ab");
	cout<<Uppercase("anish",1,2);
	
}
