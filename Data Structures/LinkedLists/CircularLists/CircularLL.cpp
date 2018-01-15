#include<iostream>

//CIRCULAR LINKED LIST IMPLEMENTATION- NO NODE points to a NULL pointer, LAST NODE POINTS TO THE HEAD NODE

using namespace std;


typedef struct CLLNode {
	int data;
	struct CLLNode* next;
};


//1)Function to traverse the circular linked list and return the count of elements
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
