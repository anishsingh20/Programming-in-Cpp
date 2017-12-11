#include<iostream>
#include<string>
#include<stack>

# define max_size 101
 
using namespace std;

//declaring stack array
int Stack[max_size];
int top=-1; //initially

//declaring stack operations
void push(int x) {
	if(top==max_size-1) {
		cout<<"Sorry!, the stack is full"<<endl;
	}
	//push into stack
	cout<<"Enter element to insert"<<endl;
	cin>>x;
	//first increment top pointer and push element
	Stack[++top] = x;
	
	
}


void pop() {
	
	if(top==-1) {
		cout<<"Stack is empty"<<endl;
		return;
	}
	
	//pop and then decrement top
	cout<<"Deleted number is: "<<Stack[top]<<endl;
	top--;
}

bool isEmpty() {
	if(top==-1) return true;
	
	return false;
}

void display() {

	if(isEmpty()) {
		cout<<"ERROR: stack is empty! "<<endl;
	}
	else if(!isEmpty()) {
	
		int i;
		cout<<"Stack :"<<endl;
		for(i=top;i>=0;i--) {
			
			cout<<Stack[i]<<endl;
	} 
     }
	
}

void Top() {
	
	if(top==-1) cout<<"Stack is empty"<<endl;
	if(top==max_size-1) cout<<"Stack is full"<<endl;
	
	 cout<<Stack[top]<<endl;
	
}


int main () {
	
	int choice;
	
	while(true) {
		cout<<"-----------------MENU---------------"<<endl;
		cout<<"1)Insert\n2)Delete\n3)Print top\n4)Display stack\n5)Exit"<<endl;
		cin>>choice;
			switch(choice) {
				case 1:
					int data;
					push(data);
					break;
				case 2:
					pop();
					break;
				case 3:
					Top();
					break;
				case 4:
					display();
					break;
				default:
					exit(0);
					break;
			}
			
	}
	
	return 0;
}
