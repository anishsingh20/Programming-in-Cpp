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
	   	

Node *reverseList(struct Node *head)
{
	Node *curr=head,*prev=NULL,*next;
	
	if(!head)  return NULL;
	
	while(curr)
	{
		next = curr->next;
		curr->next = prev; //making backwards link
		prev = curr;
		curr = next;
		
	}
	
	
	if(prev!=NULL)	head = prev;
	
	return head;
}

bool compareLists(Node *headA,Node *headB)
{
	if(!headA || !headB) return false;
	if(headA==NULL && headB==NULL)	return true;
	
	while(headA && headB)
	{
		if(headA->data != headB->data){
			return false;
			break;
		}
		
		headA = headA->next;
		headB = headB->next;
	}
	
	return true;
	
	
}


//main function to check if list is palindrome
bool CheckPalindrome(struct Node *head)
{
	if(head==NULL)	return true;
	
	//reverse of list
	struct Node *new_head = reverseList(head);
	
	//if the lists on reversal are same
	if(compareLists(head,new_head))
		return true;
		
	else	return false;
		  
}	   	
	   	
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
	n4->data = 4;
	n4->next = NULL;
	
//	struct Node *temp=n1;
//	//pusing all items inside the stack
//	while(temp!=NULL) {
//		
//		s.push(temp->data);
//		temp=temp->next;
//	}
//
//		
//	
//	
//	cout<<"\n"<<endl;
//	
//	cout<<Palindrome(n1,s);
	
	cout<<CheckPalindrome(n1);

	
	return 0;	
}
