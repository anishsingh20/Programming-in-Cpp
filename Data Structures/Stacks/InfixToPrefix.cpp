#include<iostream>


/*Algorithm-
1) Reverse the given infix expression.
2) Obtain the postfix expression of the modified infix expression.
3) Now reverse the postfix expression obtained, which will give us the Prefix expression.
*/

bool isOperator(char c)
{
	return (!isdigit(c) && isalpha(c));
}

int getPriority(char c)
{
	if(c=='+' || c=='-')
		return 1;
	else if(c=='*' || c=='/')
		return 2;
		
	else if(c=='^')
		return 3;
}


string InfixToPostfix(string infix)
{
	infix = '(' + infix + ')';
	string output;
	int len = infix.size();
	
	
}
using namespace std;

int main()
{
	return 0;
}
