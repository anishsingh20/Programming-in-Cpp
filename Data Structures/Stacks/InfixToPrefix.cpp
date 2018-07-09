#include<iostream>
#include<stack>
#include<algorithm>
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

string infixToPostfix(string infix)
{
    
    int l = infix.size();
    stack<char> char_stack;
    string output;
 
    for (int i = 0; i < l; i++) {
 
        // If the scanned character is an 
        // operand, add it to output.
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];
 
        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (infix[i] == '(')
            char_stack.push('(');
 
        // If the scanned character is an
        // ‘)’, pop and output from the stack 
        // until an ‘(‘ is encountered.
        else if (infix[i] == ')') {
 
            while (char_stack.top() != '(') {
                output += char_stack.top();
                char_stack.pop();
            }
 
            // Remove '(' from the stack
            char_stack.pop(); 
        }
 
        // Operator found 
        else {
             
            if (isOperator(char_stack.top())) {
                while (getPriority(infix[i])
                   <= getPriority(char_stack.top())) {
                    output += char_stack.top();
                    char_stack.pop();
                }
 
                // Push current Operator on stack
                char_stack.push(infix[i]);
            }
        }
    }
    return output;
}
 
 

 
string infixToPrefix(string infix)
{
    /* Reverse String
     * Replace ( with ) and vice versa
     * Get Postfix
     * Reverse Postfix  *  */
    int l = infix.size();
 
    // Reverse infix
    reverse(infix.begin(), infix.end());
 
    // Replace ( with ) and vice versa
    for (int i = 0; i < l; i++) {
 
        if (infix[i] == '(') {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
            i++;
        }
    }
 
    string prefix = infixToPostfix(infix);
 
    // Reverse postfix
    reverse(prefix.begin(), prefix.end());
 
    return prefix;
}

int main()
{
	string s = "(A*B+C/D)";
	cout<<infixToPostfix(s);
	return 0;
}
