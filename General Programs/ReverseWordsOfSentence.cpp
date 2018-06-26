#include<iostream>
#include<stack>
#include<algorithm>


using namespace std;

//program to reverse Words of a sentence


void ReverseWords(string &s)
{
	int j = s.size()-1;
	reverse(s.begin(),s.end());
	
	string::iterator it = s.begin();
	
	int count  = 0 ;
	
	//iterating till first word's end
	while(*it != ' ')
	{	
		it++;
	}
		
		
	reverse(s.begin(),it);
	reverse(it , s.end());
		
		
	
	
	

	
	
	
	
	cout<<s;	

}

int main()
{
	
	string s = "hello world!";
	
	ReverseWords(s);	
	return 0;
}
