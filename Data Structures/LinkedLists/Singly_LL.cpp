#include<iostream>

//SINGLY LINKED LIST
using namespace std;

struct Node {
	int data;
	struct Node *next;
};



/*BASIC OPERATIONS- 1)INSERTION-Insertion at beginning-O(1) , insertions at end-O(n) , insertion in middle-O(n)
		    2)DELETION-front,tail and intermediate positions
		    3)TRAVERSAL	-O(n)
*/


//Function to traverse the list and return the count of items in LL

struct Node *head;

int listlength(struct Node *head) {
	Node *current = head;
	int count = 0 ;
	while(current!=NULL) {
		count++;
		cout<<current->data<<" | "<<"\t";
		current=current->next;
	}
	return count;
	

}


//iterative solution-returns the new updated head of reversed list
Node* reverseList() {
	Node *prev=NULL,*curr,*nextnode;
	curr=head;
	
	while(curr!=NULL) {
		nextnode=curr->next;
		curr->next=prev;
		
		prev=curr;
		curr=nextnode;
		
	}
	head=prev;
	return head;	
	
}


void InsertList(int data, int pos) {
	
	struct Node *temp,*temp1; //temp pointers to be used in operations
	
	struct Node *new_node = new Node(); //creating a new Node dynmically at runtime and allocating memory in HEAP using new() function
	int k=1;
	temp=head;
	new_node->data = data;
	
	if(pos==1) { //insertion at beginning- update the head and next pointer of new_node
		
		new_node->next=temp;
		head=new_node;
		
	}
	
	else {
		//this condition will work for both insertion at middle and insertion at last
		while((temp!=NULL) && (k<pos) ){
			k++;
			temp1=temp; //temp1 is the node previous to temp node
			temp=temp->next;
		}
		//more optimal way-
		
		temp1->next=new_node;
		new_node->next=temp;
	}
}

//only for deletion at beginning -O(1)
int DelFront() {
	
	Node *temp=head;
	head=head->next;
	return temp->data;
	delete(temp); //disposing temp
	
	
}

//function to delete last node -O(n)
int DelLast() {
	Node *prev=head,*tail;
	
	while(prev->next->next!=NULL) {
		prev = prev->next; //prev is the 2nd last node
	}
	tail=prev->next;
	prev->next=NULL;
	return tail->data;
	delete(tail);
}



//function to delete at an intermediate position
int DelPos(int pos) {
	
	Node *prev,*curr;
	curr=head;//node to delete
	int k=1;
	
	while(k<pos) {
		k++;
		prev=curr;
		curr=curr->next;
	}
	prev->next=curr->next;
	return curr->data;
	
	delete(curr);
	
}
	
	
int main() {
	
		
	//allocating memory in heap;	
//	struct Node *head=new Node();
//	struct Node *sec=new Node();
//	
//	
//	
//	head->data=10;
//	head->next=sec;
//	sec->data=20;
	InsertList(1,1);
	InsertList(10,2);
	InsertList(15,3);
	InsertList(25,4);
	
	cout<<listlength(head);
	
	cout<<endl;
	
	reverseList();
	
	cout<<"List reversed:"<<endl;
	

	cout<<listlength(head);
			
	return 0;	
}





