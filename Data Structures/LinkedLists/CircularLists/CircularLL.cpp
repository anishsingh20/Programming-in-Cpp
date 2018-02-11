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
		
		cout<<curr->data;
		cout<<"-->";
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
	if(*head==NULL) {
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
} //TIME COMPLEXITY=O(n),SPACE COMPLEXITY = O(1)



//3)Function to insert at tail of CLL

void InsertLast(struct CLLNode** head,int data) {
	struct CLLNode* new_node=  new CLLNode();
	struct CLLNode* tail = *head;
	
	new_node->data= data;
	new_node->next = new_node;
	
	if(*head==NULL) {
		*head = new_node;
		return;
	
	}
	
	while(tail->next!=*head) {
		tail = tail->next;
	}
	
	
	tail->next = new_node;
	new_node->next = *head;
	
	return;
} //TIME COMPLEXITY = O(n) , SPCAE COMPLEXITY = O(1)


//function to insert at random position
void InsertPos(struct CLLNode** head,int pos ,int data) {
	struct CLLNode* new_node = new CLLNode();
	struct CLLNode* temp = *head;
	struct CLLNode* temp1;
	
	new_node->data = data;
	new_node->next = new_node;
	
	//if list is empty or inseeting at first position
	if(pos==1 || head==NULL) {
		
		*head=new_node;
	}
	
	else {
		int k=1;
		while( (k<pos) && temp->next!=*head)
		{
			k++;
			temp1 = temp;//node previous to temp
			temp=temp->next;
		}
		temp1->next = new_node;
		new_node->next = temp ; 
		
		
	}
}


//4) Deleting a node at head
void DelFirst(struct CLLNode **head) {
	struct CLLNode* tail = *head;
	struct CLLNode* temp=*head;//node to delete
	
	if(*head==NULL){
		cout<<"List Empty"<<endl;
		return;
	}
	
	//traversing till end of list
	while(tail->next!=*head) {
		tail=tail->next;
	}
	
	tail->next = temp->next;
	//moving head to point to next node
	*head=temp->next;
	cout<<"Deleted: "<<temp->data<<endl;
	delete(temp);
} //TIME COMPLEXITY = O(n), SPACE COMPLEXITY = O(1)


//5)Deleting a node at tail of CLL

void DelLast(struct CLLNode** head){
	struct CLLNode* tail = *head;
	struct CLLNode* prev;
	
	if(*head==NULL) {
		cout<<"List Empty"<<endl;
		return;
	}
	
	//traversing till 2nd last node
	while(tail->next!=*head) {
		prev = tail;//prev is always the node previous to tail
		tail=tail->next;
	}
	//updating next pointer of prev node to point to head of List
	prev->next = *head;
	cout<<"deleted : "<<tail->data<<endl;
	delete(tail);
	
}


void DelPos(struct CLLNode** head,int pos) {
	struct CLLNode* curr= *head;
	struct CLLNode *temp,*temp1 = *head;
	
	if(*head==NULL) {
		cout<<"List Empty"<<endl;
		return;
	}
	
	if(pos==1)
	{
		while(curr->next!=*head) {
			curr=curr->next;
	}
	
	curr->next = temp->next;
	//moving head to point to next node
	*head=temp->next;
	cout<<"Deleted: "<<temp->data<<endl;
	delete(temp);
	
	} 
	
	
	//position other than front of list
	else {
		int k=1;
		while((k<pos) && curr->next!=*head){
			k++;
			temp1=temp;//node previous to temp
			temp = temp->next;
			
		}
		
		temp1->next = temp->next;
		cout<<"Deleted : "<<temp->data<<endl;
		delete(temp);
		
		
	}
}

//Sorted insertion in a Circular linked list

void SortedInsert(struct CLLNode **head,int data) 
{
	
	struct CLLNode *new_node = new CLLNode();
	new_node->data = data;
	new_node->next = new_node;

	struct CLLNode *curr = (*head);

	struct CLLNode *prev;	
	
	
		
	//CASE1-if List is empty
	if( (*head) == NULL) {
		
		(*head) = new_node;
		
	}
	
	// CASE2-insertion at beginning
	else if(data < (*head)->data) 
	{
		//tail a pointer to last node
		CLLNode *tail = *head;
		while(tail->next != (*head) ) {
			tail = tail->next;
		
		}
		
			new_node->next = *head;
			tail->next = new_node;
			*head = new_node;
			
	}
		
		
	//CASE3 -Insertion at end or intermediate position- 2 METHODS
	//we simply nedd to find the appropiate node after which the new_node has to be inserted
	else {
		
		
		//METHOD-1
		while(curr->next!=(*head) && curr->data < data)  {
			
			prev = curr; //node prev to curr
			curr = curr->next; 
		}
		
		//now curr has data which is  > data
		
		//if curr is last node and curr->data < data
		if(curr->next == (*head) && curr->data < data ) {
			
			new_node->next = (*head);
			curr->next = new_node;
	
			
		}
		
		
		//CASE-4 :(prev->data < data < curr->data ) -insertion in middle
		//otherwise new_node inserted between prev and curr. 
		else {
			prev->next = new_node;
			new_node->next = curr;
			
		}
		
		
		
	//METHOD-2
//		//curr is the node after which new node has to be inserted
//		while(curr->next != *head && curr->next->data < data) {
//				
//				curr=curr->next;
//				
//			}
//			
//		new_node->next = curr->next;
//		curr->next = new_node;
			
			
	}
			 
			
}

//function to find the length of circular list
int LengthList(struct CLLNode *head)
{
	int count = 0;
	struct CLLNode *temp = head;
	if(head==NULL)
	{
		return 0;
	}
	
	else {
		
		while(temp->next != head)
		{
			count++;
			temp=temp->next;
		}
		
	}
	
	return count;
}


//function to split the circular list into 2 halves
void DivideCList(struct CLLNode *head)
{
	struct CLLNode *headA,*headB,*temp=head,*prev;
	if(head==NULL) return ;
	
	int len = LengthList(head); //finding length of CLL
	headA = head;
	
	int l =0, h= (len-1);
	int mid = (l + (h-l)/2); //middle index

	
	//traversing till mid index of list
	for(int i=0 ; i <= mid ;i++)
	{
		cout<<temp->data<<"-->";
		prev = temp; //pointer to the node prev of temp
		temp = temp->next;
	}
	
	prev->next = headA; //made the 1 circular sublist -left sublist


	cout<<endl;
	
	//head of right sublist pointing to temp pointer
	headB = temp;

		
	
	cout<<"Data in right half of sublist is-:"<<endl;
	
	while(temp != head)
	{
		cout<<temp->data<<"-->";
		temp=temp->next;
	}
	
	temp->next = headB; //second right circular sublist made
	
}



int main() {
	
//	struct CLLNode *head = new CLLNode();
//	struct CLLNode* sec = new CLLNode();
//	struct CLLNode* third = new CLLNode();
//	head->data = 10;
//	sec->data=20;
//	third->data=30;
//	
//	head->next = sec;
//	sec->next = third;
//	third->next = head;
//	cout<<traverseCLL(head);


	struct CLLNode* head = NULL;
	
//	InsertFirst(&head,100);
//	
//	InsertFirst(&head,10);
//	InsertFirst(&head,20);
//	InsertLast(&head,40);
//	
//	InsertFirst(&head,90);
//	
//	InsertLast(&head,200);

	
	SortedInsert(&head,100);
	SortedInsert(&head,10);
	SortedInsert(&head,5);
	SortedInsert(&head,15);
	SortedInsert(&head,1);
	SortedInsert(&head,1200);
	SortedInsert(&head,20);	
	SortedInsert(&head,1300);	
	SortedInsert(&head,12);	
		
		
	traverseCLL(head);
	cout<<"\n";
	
	cout<<"The sublists are-:"<<endl;
	DivideCList(head);
	
	
//	DelLast(&head);
	
//	traverseCLL(head);
	

	
	
	
	
	
	
//	DelLast(&head);
	
//	traverseCLL(head);	
	
	 
	
	return 0;
	
}
