#include<iostream>

//CIRCULAR LINKED LIST IMPLEMENTATION- NO NODE points to a NULL pointer, LAST NODE POINTS TO THE HEAD NODE

using namespace std;


typedef struct CLLNode {
	int data;
	struct CLLNode* next;
};


//1)Function to traverse the circular linked list and return the count of elements

//TIME COMPLEXITY =  O(n) , SPCAE COMPLEXITY = O(1) , for creating a temp node 
int traverseCLL(struct CLLNode* head) {
	CLLNode* curr=head;
	int count= 0;
	if(head==NULL) {
		return 0;
	} 
	
	do{
		cout<<"-->";
		cout<<curr->data;
		curr=curr->next;
		count++;
		
	} while(curr!=head);
	
	return count;
}


//2) Function to insert a node at head
void InsertFirst(CLLNode **head,int data) {
	struct CLLNode* new_node = new CLLNode();
	struct CLLNode* tail = *head;
	
	new_node->data= data;
	//initially new node next points to itself
	new_node->next = new_node;
	//if list is empty
	if(head==NULL) {
		*head= new_node;
		return;
	}
	
	new_node->next = *head;
	//traversing the list till end to update the tail and connect it with the new node
	while(tail->next != *head) {
		tail=tail->next;
	}
	tail->next = new_node;
	//now head is new node
	*head = new_node;
	return;	
}



	
	
	
	
	
}


//3)Function to insert at tail of CLL

void InsertLast(struct CLLNode** head,int data) {
	
}


//4) Deleting a node at head

void DelFirst(struct CLLNode **head) {
	
}


//5)Deleting a node at tail of CLL

void DelLast(struct CLLNode** head){
	
}


int main() {
	
	struct CLLNode *head = new CLLNode();
	struct CLLNode* sec = new CLLNode();
	struct CLLNode* third = new CLLNode();
	head->data = 10;
	sec->data=20;
	third->data=30;
	
	head->next = sec;
	sec->next = third;
	third->next = head;
	cout<<traverseCLL(head);
	
	
	 
	
	return 0;
	
}
