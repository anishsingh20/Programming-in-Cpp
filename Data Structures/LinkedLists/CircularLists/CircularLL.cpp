#incliude<iostream>

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
		cout<<curr->data<<"-->";
		curr=curr->next;
		count++;
		
	} while(curr!=head);
	
	return count;
}


int main() {
	
	return 0;
	
}
