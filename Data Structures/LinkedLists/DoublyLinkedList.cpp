#include<iostream>


//Doubly linked list program
using namespace std;

struct Node{
	int data;
	struct Node  *next;
	struct Node *prev;
};




struct Node* head  = new Node() ;

void InsertPos(struct Node **head,int data,int pos);
		
Node* traverse(struct Node *head);
		
int delPos(int pos);
		


void InsertHead(int data) {
	
	Node *new_node = new Node();
	
	new_node->data = data;
	
	new_node->next = head;
	new_node->prev= NULL;
	
	head->prev = new_node;
	
	head = new_node;
	
}

void InsertLast(struct Node** head , int data) {
	
	Node *new_node = new Node();
	
	Node *temp = *head;
	
	new_node->data= data;
	
	while(temp->next != NULL) {
		temp = temp->next;
	}
	new_node->prev = temp;
	temp->next = new_node;
	new_node->next = NULL;
	
}


//fuction to handle both insertion at last and intermediate position
void InsertPos(int pos,int data) {
	
	Node *new_node = new Node();
	
	Node *temp = head;
	
	new_node->data= data;
	int k=1;
	while( (k < pos-1) && temp->next!=NULL ) {
		k++;
		temp=temp->next; //temp is the node next to which we want to insert a new node
	}
	
	new_node->next = temp->next;
	new_node->prev = temp;
	
	temp->next->prev = new_node;
	temp->next = new_node;
}


//void InsertPos( int data,int pos) {
//	struct Node *new_node ,*temp;
//	new_node = new Node(); //allocating a new memory block to node dynamically in HEAP
//	
//	
//	
//	new_node->data = data;
//	
//	if(!new_node) {
//		cout<<"Memory Error"<<endl;
//		return;
//	}
//	int k = 1;
//	
//	 
//	if(pos==1) {
//		
//		
//		
//		new_node->next = head;
//		new_node -> prev = NULL;
//		head->prev = new_node;
//		head = new_node;
//		
//		return;
//		
//		
//		
//		
//		
//	}
//	
//	
//	
//	temp=head;
//	
//		
//		while(( k < pos-1) && (temp->next!=NULL)) {
//			
//			temp=temp->next;
//			k++;
//			
//		
////		
////		if(k!=pos) {
////			cout<<"Enter appropiate position to insert"<<endl;
////		}
//		
//		new_node->next=temp->next;
//		new_node->prev= temp;
//	
//		temp->next->prev= new_node;
//		
//		temp->next=new_node;
//		return;
//		
//		
//		
//	
//		
//		
//		
//	}
//}

int  delHead() {
	Node *temp;
	temp=head;
	if(head==NULL) {
		cout<<"List is empty"<<endl;
	}
	
	else {
		
		head = temp->next;
		head->prev = NULL;
	
	}
	
	return temp->data;
	delete(temp);
	
	
}


int delPos(int pos) 
{
	Node *temp,*temp1;
	int k=1;
	temp= head;
	if(pos<=0) {
		cout<<"Not a valid index"<<endl;
	} 
	
	if(pos==1) {
		
		head= head->next;
		head->prev = NULL;
		return temp->data;
		delete(temp);
	}
	
	//traversing the list
	while((k < pos) && temp->next!=NULL) {
		
		
		temp=temp->next;
		k++;
		
	}
	
	temp1 = temp->prev;
	temp1->next = temp->next;
	temp->next->prev = temp1;
	
	return temp->data;
	delete(temp);
	
	
	
	

	
	
	
}


Node* traverse(struct Node *head) {
	
	struct Node *temp=head;
	int count=0;
	
	while(temp!=NULL) {
		
		
		cout<<"<-->"<<temp->data;
		temp=temp->next;
		count++;
		
		
	}
	cout<<"->NULL"<<endl;
	cout<<"Count of items is :"<<count<<endl;
	
	
	
	return head;
	
}


//FUNCTION TO PRINT DATA IN REVRESE ORDER - THE LIST IS NOT REVERSED- we are just traversing till end and with the help of prev pointer we print the data by
//again traversing from tail to head node
void ReverseData(Node *head)
{
    Node *temp = head;
   if(head==NULL) 
   {
   	cout<<"List empty!"<<endl;
       
   }
   
   //traversing till end of list
    while(temp->next!=NULL) 
    {
        temp = temp->next;
    }
    
    cout<<"NULL";
    while(temp->prev!=NULL) 
    {
    	cout<<"<-->"<<temp->data;
    	temp=temp->prev;
    	
    }
    
    cout<<"->NULL"<<endl;
        

}//TIME COMPLEXITY-O(n)


//function to insert data in sorted manner in DLL
/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/




Node* SortedInsert(Node **head,int data)
{
    // Complete this function
   // Do not write the main method. 
    
    struct Node *new_node = new Node();
    struct Node* temp = *head;
    new_node->data = data;
    
    //case when List is empty
    if(*head==NULL) {
        
        *head = new_node;
        return *head;
        
    }
    
    //insertion at beginning of List
    else if(data < temp->data) {
        new_node->next = temp;
        temp->prev = new_node;
        *head =  new_node;
        return *head;
    }
    
    //walking with 2 pointers
    else{
        
        struct Node* temp1 = NULL;
        
        //traversing only if new_node has larger data
        while(temp!=NULL && temp->data < data) {
            temp1 = temp;//temp1 is node previous to temp
            temp=temp->next;
        }

        //insertion at end of LL
        if(temp==NULL) {
            temp1->next = new_node;
            new_node->prev = temp1;
            new_node->next = NULL;
        }
        
        //insertion in between
        //temp1 is node prev to temp
        //temp is ahead of temp1
        //new_node has to be inserted between temp and temp1
        else{
            temp1->next = new_node;
            temp->prev = new_node;
            
            new_node->next = temp;
            new_node->prev = temp1;
        }
            
            
        
        
        
    }
    return *head;
}
    
    
    


//int DLL::delPos(int pos) {
//	
//	
//	return
//}


int main() {
	
	
//	
//	struct Node *n1 = new Node();
//	struct Node *n2 = new Node();
//	n1->data=20;
//	n2->data=30;	
//	
//	n1->next = n2;
//	
//	
//	n2->next=NULL;
//	n2->prev = n1;
//	
//	n.traverse(n1);
	
	
	
//	InsertPos(20,1);
//////
//	InsertPos(30,2);
//	InsertPos(100,3);
////	

//	InsertHead("anish");
//	InsertPos(2,"Mrinal");
//	InsertPos(3,"Vaibhav");
//	InsertPos(4,"Rasila");
//	InsertPos(5,"gandu");
//	InsertPos(6,"mc");



SortedInsert(&head, 10);
SortedInsert(&head,1);
SortedInsert(&head,15);
SortedInsert(&head,100);

	
	cout<<"The list is: "<<endl;
	
//	traverse(head);	
//	cout<<"\n";
//	cout<<"After deletion:"<<endl;
//	
//	delHead();
//	delPos(4);
	
//	Reverse(head);
	
//	InsertLast(&head,20);
	traverse(head);
	
	ReverseData(head);
	
	return 0;
}
