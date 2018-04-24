//postfix evaluation

#include<iostream>
#include<stack>
#include<string>
#include<math.h>

using namespace std;

//declaring functions

//1) function to get the result
double getResult(string postfix) ;

double getResultPrefix(string prefix);

//function to perform the operation between the 2 popped operands
double performOps(char opt,double opd1,double opd2);

//check if the scanned int is an operand
bool isOperand(char opd);

//check if the scanned char is a operator
bool isOperator(char c);


//for postfix expression evaluation, we scan form left to right
double getResult(string postfix) 
{
	//defining a stack from STL
	stack<double> S;
	
	//scanning form left to right of the expression
	for(int i = 0; i < postfix.length();i++) {

	
	
		
		//if delimitter then continue
		if(postfix[i]== ' ' || postfix[i]==',') continue;
		
		//if operator is scanned , then pop 2 operands from top of stack and 
		//perform the ops and push the result back to stack
		else if(!S.empty() && isOperator(postfix[i])) {
			
			//pop 2 operands
			double operand1 = S.top() ; S.pop();
			double operand2 = S.top() ; S.pop();
			
			//performing the operation and getting result
			double result = performOps(postfix[i],operand1,operand2);
			
			//pushing the result to stack
			S.push(result);
			
			
			
		}
		
		
	//if the scanned element is a operand-push it to stack
		else if (isOperand(postfix[i])) {
			//extract numeric operand from expression
			int operand = 0;
			//checking if the scanned expression is digit
			if(isdigit(postfix[i])) {
				//the below expression converts string operand to integer operant to do calculation 
				operand = (postfix[i]-'0');
			}
			
			//pushing operand on to stack
			S.push(operand);
		}
	}
	
	//top of stack contains the result so we return it.
	return S.top(); //result stored at top of stack
}



//for prefix evaluation, we scan from the right to left
	
double getResultPrefix(string prefix) 
{
	//defining a stack from STL
	stack<double> S;
	

	//for prefix evaluation, we scan from the right to left i.e the operands
	for(int i = prefix.size()-1; i >= 0 ;i--)
	{
	
		
		//if delimitter then continue
		if(prefix[i]== ' ' || prefix[i]==',') continue;
		
		//if operator is scanned , then pop 2 operands from top of stack and 
		//perform the ops and push the result back to stack
		else if(!S.empty() && isOperator(prefix[i])) {
			
			//pop 2 operands
			double operand1 = S.top() ; S.pop();
			double operand2 = S.top() ; S.pop();
			
			//performing the operation and getting result
			double result = performOps(prefix[i],operand1,operand2);
			
			//pushing the result to stack
			S.push(result);
			
			
			
		}
		
		
	//if the scanned element is a operand-push it to stack
		else if (isOperand(prefix[i])) {
			//extract numeric operand from expression
			int operand = 0;
			//checking if the scanned expression is digit
			if(isdigit(prefix[i])) {
				//the below expression converts string operand to integer operant to do calculation 
				operand = (prefix[i]-'0');
			}
			
			//pushing operand on to stack
			S.push(operand);
		}
	}
	
	//top of stack contains the result so we return it.
	return S.top(); //result stored at top of stack
}


double performOps(char opt,double opd1,double opd2) {
	
	if(opt=='+') return opd1+opd2;
	if(opt=='-') return abs(opd1-opd2);
	if(opt=='*') return opd1*opd2;
	if(opt=='/') return (opd1/opd2);
	
	else cout<<"Error"<<endl;
	return -1;
}	




bool isOperator(char c) {
	if( c == '+' || c == '-' || c == '*' || c=='/' )
		return true;
		
		
	return false;
}


bool isOperand(char opd) {
	if(opd>='0'&& opd<='9') return true;
	
	else false;
}





int main()
{
	string expression;
	cout<<"Enter the prefix expression:"<<endl;
	getline(cin,expression);
	
	double result = getResultPrefix(expression);
	
	cout<<"The result of "<<expression<<  " is :"<<result<<endl;
	return 0;
}
