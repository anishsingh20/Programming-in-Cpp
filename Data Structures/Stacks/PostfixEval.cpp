//postfix evaluation

#include<iostream>
#include<stack>
#include<string>

using namespace std;

//declaring functions

//1) function to get the result

int getResult(string postfix);

//function to perform the operation between the 2 popped operands
int performOps(char opt,int opd1,int opd2);

//check if the scanned int is an operand
bool isOperand(char opd);

//check if the scanned char is a operator
bool isOperator(char c);



int getResult(string postfix) 
{
	//defining a stack from STL
	stack<int> S;
	
	//scanning form left to right of the expression
	for(int i = 0; i< postfix.length();i++) {
		
		//if delimitter then continue
		if(postfix[i]== ' ' || postfix[i]==',') continue;
		
		//if operator is scanned , then pop 2 operands from top of stack and 
		//perform the ops and push the result back to stack
		else if(!S.empty() && isOperator(postfix[i])) {
			
			//pop 2 operands
			int operand1 = S.top() ; S.pop();
			int operand2 = S.top() ; S.pop();
			
			//performing the operation and getting result
			int result = performOps(postfix[i],operand1,operand2);
			
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
	
	return S.top(); //result stored at top of stack
}


int performOps(char opt,int opd1,int opd2) {
	if(opt=='+') return opd1+opd2;
	if(opt=='-') return opd1-opd2;
	if(opt=='*') return opd1*opd2;
	if(opt=='/') return (opd1/opd2);
	
	else cout<<"Error"<<endl;
	return -1;
}	




bool isOperator(char c) {
	if(c == '+' || c == '-' || c == '*' || c=='/' || c ==' $' )
		return true;
		
		
	return false;
}


bool isOperand(char opd) {
	if(opd>='0'&& opd<='9') return true;
	
	else false;
}





int main(){
	string expression;
	cout<<"Enter the postfix expression:"<<endl;
	getline(cin,expression);
	
	int result = getResult(expression);
	
	cout<<"The result of "<<expression<<  " is :"<<result<<endl;
	return 0;
}
