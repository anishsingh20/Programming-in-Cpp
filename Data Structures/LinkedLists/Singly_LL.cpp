#include<iostream>
#include<stack>
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

struct Node *head = NULL;

int listlength(struct Node *head) {
	struct Node *current = head;
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
	
	Node *prev,*del_node;
	prev=head;
	
	
	//loop to keep track of the prev node to the node to be deleted to adjust the next pointer of prev node
	for(int i=1;i<pos-1;i++)
	{
		prev=prev->next;
	}
	
	//or 

	
	del_node=prev->next;
	prev->next=del_node->next;
	//prev->next=curr->next;
	return del_node->data;
	
	delete(del_node);//deallocating memory
}





	
//a single function to handle all delete cases	
int DelNodePos(int pos) {
	Node *temp=head;
	Node *prev;
//	cout<<"Enter position to delete: "<<endl;
//	cin>>pos;
	if(pos<=0) {
		cout<<"Enter a valid index"<<endl;
		return 0;
	}
	
	
	if(pos==1) {
		
		head = head->next; //head points to 2nd node
			
	}
	
	//case which will handle all other posotions and the last node deletion too
	else {
		int k = 1;
		
		while ((temp!=NULL) && (k<pos)) {
			k++;
			prev = temp;
			temp=temp->next;
			
		}
		
		//updating the next pointer of prev node
		
		prev->next=temp->next;
	}
	
	return temp->data;
	delete(temp);
	
	
}


//a function to remove duplicates from a sorted linked list
Node* RemoveDuplicates(Node *head) //O(n)-TIME COMPLEXITY
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    Node *temp;
    Node *temp1;
    //traversing and finding duplicate elements in list
    temp=head;
    while(temp->next!=NULL) {
        temp1=temp->next;
        if(temp->data == temp1->data) {
            
            
            temp->next = temp1->next;
            delete(temp1);
            
        }
        else {
        	temp=temp->next;
	}
	
        	
        
    }
    
    return head;
        
}	



//a function to remove a duplicate node from an unsorted List

void RemoveUnsortedDup(struct Node *head) {
	
	Node *temp = head;
	Node *temp1;
	
	//traversing the list
	while(temp->next!=NULL) {
		temp1 = temp;
		
		while(temp1->next!=NULL) 
		{
			//if duplicate is found in the next position, then delete it
			if(temp->data == temp1->next->data) 
			{
				Node *dup = temp1->next;
				temp1->next = dup->next;
				delete(dup);
			}
			
			//otherwise simply mode temp1 to next node
			else {
				temp1=temp1->next;
			}
			
		}
		
		temp=temp->next;
	
	}

}// TIME COMPLEXITY-O(N^2)
	
	
//list should be sorted	
bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    Node *temp=head;
    Node *temp1=head;//temp1 is a node which is always ahead of temp
    
    if(head==NULL){
    return false;
    }
    
    
        //traversing the list and checking for cycles
      while(temp->next!=NULL && temp1!=NULL){
      	temp=temp->next;
      	temp1=temp1->next->next; //one node ahead
      	
      	
      	//if temp and temp1 pointers have same addresses
      	if(temp1==temp) {
      		cout<<"Has a cycle"<<endl;
      		return true;
	      }
	     
      }
      
      return false;
}         
         
	 
//function to insert in a Sorted linked list
void sortedInsert(struct Node** head,int data) {
	struct Node *new_node = new Node();//allocating memory
	struct Node *curr = *head;
	
	new_node->data = data;
	
	//case1 if list is empty or if new_node has smaller data then one at head of LL
	if( *head==NULL) {
		new_node->next = *head;
		*head = new_node;
	
	}
	//insertion at beginning of list
	else  if( (*head)->data > data ) 
	
	{
		new_node->next = *head; //or curr
		*head  = new_node;
		
	}
	
	
	//CASE-3: 2 methods, when data  > curr->data
	else {
		
		
		
		//METHOD-1
		struct Node *prev = NULL;
		while(curr->next!=NULL && curr->data < data) {
			prev = curr;
			curr=curr->next;
		}
		
		if(curr->next == NULL && curr->data < data) {
			new_node->next = NULL;
			curr->next = new_node;
			
		}
		
		else {
			
			prev->next = new_node;
			new_node->next = curr;
		}
		
		
		
	//METHOD-2	
	//we traverse the list only if new node has larger data
	/* LOGIC
	find the appropriate node after 
   	which the input node (let 9) is to be inserted. 
   	To find the appropriate node start from head, 
   	keep moving until you reach a node GN (10 in
   	the below diagram) who's value is greater than 
   	the input node.

	*/	
/* Locate the node before the point of insertion */	
	
//		while(curr->next!=NULL && curr->next->data < data) {
//		
//			curr=curr->next;
//		}
//		
//		//new node has larger data then curr , so new node will be inserted after curr node
//		new_node->next = curr->next;
//		curr->next = new_node;	
//		
//	}


	


	
	}	
}



//finding length of a List
int length(struct Node *head) {
	
	int len = 0;
	while(head!=NULL) {
		len++;
		head = head->next;
	}
	
	return len;
	
}


//function to print kth element from the tail-IMP
int printfromTail(Node *head,int postail) {
	Node *temp=head;
	Node *result=head; //a pointer to store the address of kth element from tail
	
	int k=0;
	
	//traversing the list
	while(temp!=NULL) {
		
		
		if(k++ > postail) {
			
			result=result->next;
			
		}
		
		temp=temp->next;
	}
	
	return result->data;
}
	

//function to get Nth node in a list

int getNode(struct Node *head,int pos) 
{

	Node *temp = head;
	int len = length(head); //finding length of list to check for corner cases
	if(pos > len || pos < 0 ) {
		cout<<"Invalid position"<<endl;
		return 0;
	}
	
	else {
		
		
		struct Node *temp1=head; 
		int k=0;
		while(temp!=NULL)
		{
		
			if( ++k < pos) {
				
				
				temp1=temp1->next;
				
			}
			
			temp = temp->next;
		}
		
		return temp1->data;
		
	}
}

//TIME COMPLEXITY = O(n) of traversing the list


//function to get the Middle of a list
int MiddleNode(struct Node **head,int start=0) {
	
	
	if(*head==NULL) 
	{
		cout<<"list enpty"<<endl;
	}
	
	int len = length(*head);
	int mid = (start + (len-start)/2 );
	struct Node *temp=*head;
	for(int i=0;i<mid;i++)
		temp=temp->next;
		
	return temp->data; 

}



	
int main() {
	
	stack<int>s;
		
	//allocating memory in heap;	
//	struct Node *n1  = new Node();
//	struct Node *n2  = new Node();
//	struct Node *n3  = new Node();
//	struct Node *n4  = new Node();	
//	
//	
//	n1->data=2;
//	n1->next=n2;
//	n2->data=1;
//	n2->next = n3;
//	n3->data=1;
//	n3->next = n4;
//	n4->data = 2;
//	n4->next = NULL;



//cout<<printfromTail(head,0);


	sortedInsert(&head,10);
	sortedInsert(&head,9);
	sortedInsert(&head,20);
	sortedInsert(&head,2);
	sortedInsert(&head,51);
	sortedInsert(&head,6);
	sortedInsert(&head,61);
	sortedInsert(&head,5);
	sortedInsert(&head,100);
	
//	
	
	
	
	
//	cout<<printfromTail(head,3)<<endl;
	
//	cout<<getNode(head,3)<<endl;
//	
	cout<<"Middle element is :"<<MiddleNode(&head);


	
		
	//removing duplicates form unsorted list
//	RemoveUnsortedDup(head);
//	cout<<"After duplicate removal"<<endl;
//	cout<<listlength(head)<<endl;



	
	
	
	
//	
//	cout<<"\n";
//	
//	//removing duplicates in a sorted list
//	RemoveDuplicates(head);
//	
//	
//	cout<<listlength(head)<<endl;
//	has_cycle(head);
//	cout<<printfromTail(head,1);
//	
//	cout<<"\n";
//	cout<<endl;
////	cout<<DelPos(2)<<endl;
//	
//	cout<<DelNodePos(1)<<endl;
//	
//		
//	reverseList();
//	
//	cout<<"List reversed:"<<endl;
//	
//
//	cout<<listlength(head);
			
	return 0;	
}





