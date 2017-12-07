#include<iostream>

using namespace std;

struct node { //a node in a LL has 2 fields , data and a next field which stores the address of next node or points to next node
	int data;
	struct node *next; //next is a pointer of type node
};

class stack {
	node *top; //top is a node
	public :
		stack() { //constructor
			top=NULL; //initially
		}
		void push(int n);
		int pop();
		void display();
};

//insertion function
void stack::push(int n) {
	struct node *temp;// temp is a temporary node
	temp = new node; //dynamically allocate memory to temp
	cout<<"Enter data"<<endl;
	cin>>n;
	temp->data=n;
	temp->next=top;
	top=temp;
	
}
	
	
int stack::pop() {
	struct node *temp;
	
	if(top==NULL) {
		cout<<"Stack is empty"<<endl;
	}
	
	else {
		
		temp=top;
		top=top->next;
		cout<<"Deleted data from top is: "<<" "<<temp->data<<endl;
		 //move top to next element in stack
		delete(temp);
	}
	
	
	
}


void stack:: display(){
	struct node *temp;
	temp=new node;
	//start traversing from top
	temp=top;
	
	
	if(top==NULL){
		cout<<"Stack is empty"<<endl;
	}
	
	else{
		
		while(temp!=NULL) {
			
			cout<<endl<<temp->data<<endl;
			temp=temp->next;// traverse to the end of list
			
			
		}
	}
}


int main () {
	
	stack s; //object to access and use stack operation methods
	int choice;
	int data;
	
	while(1) {
		
		cout<<"\n1)Insert\n2)Delete\n3)Display\n4)Exit\n"<<endl;
		cin>>choice;
		
		
		switch(choice) {
			
			case 1: 
				s.push(data);
				break;
			case 2:
				s.pop();
				break;
			case 3:
				s.display();
				break;
			default:
				exit(0);//to exit the entire program
				break;
		
			
	}
}//end while
	
	return 0;
}
