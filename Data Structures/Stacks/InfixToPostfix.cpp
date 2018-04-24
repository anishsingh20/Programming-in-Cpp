//infix to postfix conversion-using stack

#include<iostream>
#include<stack>
#include<string>

using namespace std; //pulling every function defined in std namespace to global namespace

//function to convert infix to postfix
string InpixToPostfix(string exp);

//function to check if a operator has higher precedence than other
int checkHighPrecedence(char opt1, char opt2);

//function to verify if the char is operator or not
bool isOperator(char c);

//function to check is the scanned input if operand or not
bool isOperand(char c);

//function to conver infix to postfix
string InfixToPostfix(string exp) 
{
	//declaring a stack from STL
	stack<char> S;
	string postfix =  " " ; //postfix exp as empty string
	
	//scanning character from left to right
	for(int i=0;i<exp.length();i++) 
	{	
	//if delimitter continue
		if(exp[i]==' ' || exp[i]==',') continue;
		
		//if operator being scanned has lower or equal precedence than alraedy in stack , 
		//pop all with higher precedence
		// push low precedence into stack
		else if(isOperator(exp[i])) {
			while(!S.empty() && S.top()!='(' && checkHighPrecedence(S.top(),exp[i]) ) {
				postfix += S.top(); //add higher precedence opt to postfix expression
				S.pop(); //pop higher precedence opt from stack	
			}
			//push lower precedence scanned opt to stack
			S.push(exp[i]);
		}
		
		//if scanned char is a opening brace= push it to stack
		else if(exp[i]=='(') {
			S.push(exp[i]);	
		}
		
		//if an operand , add it to postfix exp
		else if(isOperand(exp[i])) {
			postfix += exp[i];
		}
		
		//if scanned char is a right brace
		//pop all from stack and add to postfix until found a opening brace on TOS
		
		else if(exp[i]== ')') {
			while(!S.empty() && S.top()!='(') {
				postfix += S.top();
				S.pop();
				
			}
			S.pop();
		}
	} //end Loop
	
	//Now pop all elements from stack until stack is empty
	while(!S.empty()) {
		postfix += S.top();
		S.pop();
		
	}
	
	return postfix;
		
}


bool isOperand(char c) {
	if(c >='0' &&  c <= '9') return true;
	if(c>= 'a' && c<='z') return true;
	if(c>= 'A' && c<= 'Z') return true;
	
	return false;
}

bool isOperator(char c) {
	if(c == '+' || c == '-' || c == '*' || c=='/' || c ==' $' )
		return true;
		
		
	return false;
}

//function to assign weights to operators

int optWeight(char op)  {
	
	int weight=-1;
	switch(op) {
		case '+':
		case '-':
			weight=1;
			break;
			
		//higher weight to mul and division
		case '*' :
		case '/':
			weight=2;
			break;
		case '$' :
			weight=3;
			break;
	}
	return weight;
}

//to verify whether an operator is right associative or not
int IsRightAssociative(char op)
{
	if(op == '$') return true;
	return false;
}



int checkHighPrecedence(char opt1, char opt2)
{
	//getting weights of the operator arguments
	int optWt1=optWeight(opt1);
	int optWt2 = optWeight(opt2);
	
	if(optWt1==optWt2) {
		if(IsRightAssociative(opt1)) return false;
		else return true;
	}
	
	return optWt1 > optWt2 ? true:false ;	
}



//the main function
int main() {
	
	string infix;
	cout<<"Enter the infix empression" <<endl;
	
	getline(cin,infix);
	string postfix = InfixToPostfix(infix);
	
	cout<<"The postfix expression is :"<<postfix<<endl;
	
	
	
	
	return 0;
}


