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
	
	while(*it != ' ')
	{	
		count++;
		it++;
	}
		
		
	reverse(s.begin(),s.begin()+count);
	reverse(s.begin() + count , s.end());
		
		
	
	
	

	
	
	
	
	cout<<s;	

}

int main()
{
	
	string s = "whats up nigga";
	
	ReverseWords(s);	
	return 0;
}
