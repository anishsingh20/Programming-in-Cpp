#include<iostream>
#include<stack>


//SINGLY LINKED LIST
using namespace std;

struct Node {
	int data;
	struct Node *next;
};




//function to check is a list is Palindrome or not - i.e its revrerse is equal to itself or not
//using a stack

void traverse(struct Node *head) {
	
	while(head!=NULL) {
		cout<<head->data<<"-->";
		head=head->next;
	}
	cout<<"Null";
	
}


int Palindrome(struct Node *head,stack<int>&s) 
{
	//stack to store all datd items of the list
	
	int flag=0;
	
	if(head==NULL  && s.empty()) {
		cout<<"Empty "<<endl;
		return 0;
	}
	
	else 
	{
		//trversing the list
		struct Node *temp=head;
		while(temp!=NULL) { //T(n) = O(n)
			
			
			if(temp->data == s.top()) 
			{
				
				flag = 1;
				
				s.pop(); //O(1)
				
			}
		
			
			
			temp=temp->next;
			
		}
		
		if(!s.empty()) {
			
			flag = 0;
			cout<<"Not palindrome"<<endl;
		}
		//if stack is empty
		else {
			flag = 1;
			cout<<"Palindrome list."<<endl;
		}
	}
		
	return flag;	
}
//TIME COMPLEXITY  =  O(n)
	   	


	   	
	   	
int main() {
	
	stack<int>s;
		
	//allocating memory in heap;	
	struct Node *n1  = new Node();
	struct Node *n2  = new Node();
	struct Node *n3  = new Node();
	struct Node *n4  = new Node();	
	
	
	n1->data=2;
	n1->next=n2;
	n2->data=1;
	n2->next = n3;
	n3->data=1;
	n3->next = n4;
	n4->data = 2;
	n4->next = NULL;
	
	struct Node *temp=n1;
	//pusing all items inside the stack
	while(temp!=NULL) {
		
		s.push(temp->data);
		temp=temp->next;
	}

		
	
	traverse(n1);
	cout<<"\n"<<endl;
	
	cout<<Palindrome(n1,s);

	return 0;	
}
