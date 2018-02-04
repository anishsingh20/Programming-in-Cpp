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


void PalindromeStack(string s,stack <char>&p) 
{
	
	
	
	//pushing contents of string to stack
	for(int i=0 ; i < s.length() ;  i++)  //O(n)
	{
		p.push(s[i]); //O(1)
		
	}
	
	//comparing the expression and top of stack
//	for(int i = 0 ; i < s.length()  ; i++)
//	{
//		if(s[i] == p.top()) 
//		{
//			
//			p.pop();
//			
//		}
//	}

	int i=0;
	while( i < s.length() && s[i]==p.top())	  //O(n)
	{
		p.pop(); //O(1)
		i++;
		
	}
	
	if(p.empty()) {
		cout<<"Palindrome string."<<endl;
	}
	
	else {
		cout<<"Not a palindrome string."<<endl;
	}
	
     } //Time complexity = O(n) -linear time


int main() {
	
	stack<char>c;
	string s;
	
	getline(cin,s);
	
	
	PalindromeStack(s,c);
	
	
	
	return 0;
}
