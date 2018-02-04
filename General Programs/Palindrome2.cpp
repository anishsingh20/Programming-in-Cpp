#include<iostream>
#include<stack>

using namespace std;


//Method-1 :Iterative method

void Palindrome(string s) {
	
	int start = 0 ;
	
	int end = (s.length() - 1);
	
	
	while(start <= end) 
	{
		if(s[start]==s[end]) 
		{
			start++;
			end--;
		}
		
		//if the left and right values don't match , simply break out of while loop and test for base condition
		else {
			break;
		}
		
	}
	
	if(start < end) {
		
		cout<<"Not a palindrome"<<endl;
	}
	
	else 
	{
		cout<<"Palindrome string"<<endl;
	}
}
//T(n)  = O(n)


//Method-2 :using stack


void PalindromeStack(string s) 
{
	stack <char> p;
	
	
	//pushing contents of string to stack
	for(int i=0 ; i < s.length() ;  i++) 
	{
		p.push(s[i]);
		
	}
	
	//comparing the expression and top of stack
	for(int i = 0 ; i < s.length()  ; i++)
	{
		if(s[i] == p.top()) 
		{
			
			p.pop();
			
		}
	}
	
	if(!s.empty()) {
		
		cout<<"Not Palindrome."<<endl;
	}
	
	else cout<<"Palindrome."<<endl;
	
	
}


int main() {
	
	
	string s;
	
	getline(cin,s);
	
	
	PalindromeStack(s);
	
	
	
	return 0;
}
