#include<iostream>
#include<map>

//program to find longest repeated substring

using namespace std;

string LongestRepeatedSubstr(string s)
{
	int size = s.length();
	string sub;
	map<string,int>m;
	for(int i = 0 ; i < size ; i++)
	{
		sub = "";
		for(int j = 1 ; j <= size-i ; j++)
		{
			sub = s.substr(i,j);
			
			//if substring found again, simply increase the count;
			if(m.find(sub)==m.end())
			{
				m[sub] = 1;
			}
			
			
			//otherwise,if not found insert it in map with count as 1
			else m[sub]++;
		}
		
	}
	
		map<string,int>::iterator it;
		int max = 0;
		string str="\0";
		for(it =  m.begin();it!=m.end();it++)
		{

			if((it->first).length()>max && it->second > 1)
			{
				max = (it->first).length();
				str = it->first;
			}
		}
	
	return str;
	
	
}

int main()
{
	string str = "abcpqrabpqpq";
	
	cout<<LongestRepeatedSubstr(str);
	return 0;
}
