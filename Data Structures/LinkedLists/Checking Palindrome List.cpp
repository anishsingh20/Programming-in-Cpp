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
	   	

struct ListNode* reverseList(struct ListNode *head) {
        
    if(!head) return NULL;
        
        struct ListNode *curr=head,*prev=NULL,*next;
	

	
	while(curr)
	
	{
		next = curr->next;
		curr->next = prev; //making backwards link
		prev = curr;
		curr = next;
		
	}

	return prev;
}


bool isPalindrome(struct ListNode* head) {
        
        if(head==NULL||head->next==NULL)
            return true;
        struct ListNode* slow=head;
        struct ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
//        slow->next=reverseList(slow->next);//reversing the next half of list
//        slow=slow->next;//slow now points to the element next to mid

	struct node *mid = reverseList(slow->next);
	slow->next = NULL;
	
        while(mid!=NULL){
        	
            if(head->val!=mid->val)
                return false;
            head=head->next;
            mid=mid->next;
        }
        return true;
}	
	   	
int main() {
	
	stack<int>s;
		
	//allocating memory in heap;	
	struct Node *n1  = new Node();
	struct Node *n2  = new Node();
	struct Node *n3  = new Node();
	struct Node *n4  = new Node();	
	
	
	n1->data=1;
	n1->next=n2;
	n2->data=2;

	n2->next = n3;
	n3->data=1;
	n3->next = NULL;
	
	cout<<isPalindrome(head);
	
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


//	cout<<CheckPalindrome(n1);

	
	return 0;	
}
