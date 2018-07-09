#include<iostream>
#include<stack>
using namespace std;

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
		
	return 0;
}


string InfixToPostfix(string infix)
{
	infix = '(' + infix + ')';
	string output="";
	int len = infix.size();
	stack<char>s;
	
	for(int i = 0 ; i < len; i++)
	{
		//if operand-add it to the postfix expression
		if(isalpha(infix[i]) || isdigit(infix[i]))
			output += infix[i];
			
		//if opening brace then push it to stack
		else if(infix[i]=='(')
			s.push(infix[i]);
			
		else if(infix[i]==')')
		{
			while(s.top()!='(')
			{
				output += s.top();
				s.pop();
			}
			
			//remove ( from stack
			s.pop();
		}
		
		//if operator is found
		else
		{
		
			if(isOperator(s.top()))
			{
				while( getPriority(infix[i]) <= getPriority(s.top()))
				{
					output += s.top();
					s.pop();
				}
				
				//push current lower priority operator on stack
				s.push(infix[i]);
					
			}	
		}
			
	}
	
	return output;
	
}


int main()
{
	string s= InfixToPostfix("A*B+C/D");
	cout<<s;
	return 0;
}
