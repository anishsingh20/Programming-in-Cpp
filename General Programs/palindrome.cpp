#include<iostream>
#include<string>
#include<cstring> //to use the strlen(char) function

//implementing it using a C type string

using namespace std;

int palindrome(char *a) 
{
	int i=0;
	int j = strlen(a)-1;
	while(i<=j && a[i]==a[j])  {
		//true condition , simply change i and j indices
		i++;
		j--;
	}
		
		
	if(i<j) {
		
		cout<<"Not palindrome"<<endl;
		return 0;
		
		 
	}
	else {
		cout<<"Palindrome"<<endl;
		return 1;
	}
	
		
		
}
//recursive program to find whether a string is palindrome or not-in POSTRORDER traversal
bool PalindromeRec(string exp,int i,int j )
{
	
	
	//base condition-recursion terminates
	if(i>j || exp[i]!=exp[j])	
		return false;
	
	
	if(exp[i]==exp[j])
		return true;
	
	//otherwise simply keep checking for same digits by incrementing i and decrementing j	
	if(i<=j)
	{
		return PalindromeRec(exp,i++,j--);	
	}
		
	
}//Time complexity = O(n), spcae complexity = O(n), for recursive call stack	

int main() {
	
//	palindrome("nitin");
//	palindrome("anish");
	
	cout<<endl;
	
	string str = "raar";
	int i = 0;
	int j = str.size()-1;
	cout<<PalindromeRec(str,i,j);
	return 0;
}
