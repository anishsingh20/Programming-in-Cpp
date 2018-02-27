#include<iostream>


//Doubly linked list program
using namespace std;

struct Node{
	int data;
	struct Node  *next;
	struct Node *prev;
};


Node *head= new Node();

void InsertPos(struct Node **head,int data,int pos);
		
void traverse(struct Node *head);
		
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


void traverse(Node *head) {
	
	struct Node *temp=head;
	int count=0;
	
	while(temp!=NULL) {
		
		
		cout<<"<-->"<<temp->data;
		temp=temp->next;
		count++;
		
		
	}
	cout<<"->NULL"<<endl;
	cout<<"Count of items is :"<<count<<endl;

	
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



//FUNCTION TO REVERSE A DOUBLY LINKED LIST 
Node* Reverse(Node* head)
{
    Node *curr=head;
    Node *temp;
    
	//CASE-1 -if List is empty
	if(head==NULL) {
		
		
		return head;
	}
	
	
	//if list has only 1 element
	if(curr->next == NULL) {
		
		return head;
	}
	
	else{
	
		while(curr!=NULL) {
			
			temp = curr->prev;
			
			//changing Links
			curr->prev = curr->next; //changing prev to next
			curr->next = temp;//curr next points to its prev node
				
			curr=curr->prev;
		}
		
		    if(temp!=NULL)
		    {
		    	
			temp=temp->prev;
			
		    }
		
		head = temp;
		
		while(temp!=NULL) {
			cout<<"<-->"<<temp->data;
			temp=temp->next;
		}
        	
	return head;	
    }	
    
   
   
   
}



//FUNCTION TO REMOVE DUPLICATES IN A SORTED LINKED LIST - No need of 2 while lopps because we already know the list is sorted
void RemoveDuplicate(Node *head) {
	
	Node *temp=head;
	Node *temp1;
	
	//list empty
	if(head==NULL) {
		return;
	}
	
	//traversing the list and searching for duplicates
	while(temp->next!=NULL) {
		
		temp1 = temp->next;
		
			if(temp->data == temp1->data) 
			{
				
				temp->next = temp1->next;
				temp1->next->prev = temp;
				
				cout<<"Deleted Duplicate:"<<temp1->data<<endl;
				
				delete temp1;
				
			}
			
			else {
				temp=temp->next;
			}
	}
}


/*FUNCTION TO REMOVE DUPLICATES FROM AN UNSORTED LINKED LIST-
1) Using 2 while loops - Time complexity = O(n^2), ineffieicnt
2) Sort the List using QUick or Merge sort and then simply remove duplicates from sorted list as used above- TIME COLPLEXITY= O(nlogn), space complexity = O(1)
*/

void RemoveDupUnsorted(Node *head) 
{
	Node *temp = head;
	Node *temp1;
	
	if(head==NULL) {
		
		return;
	}
	
	for(temp=head;temp!=NULL;temp=temp->next) 
	{
		
		temp1 = temp->next;
		
		while(temp1!=NULL) 
		{
			
			if(temp->data == temp1->data) {
				
				
				
				temp->next = temp1->next;
				temp1->next->prev = temp;
				
				cout<<"Deleted:"<<temp1->data<<endl;
				
				delete temp1;
				
			}
			
			else {
				temp1=temp1->next;
			}
			
		}
		
	}
	
}//TIME CPMPLEXITY-O(n^2)




//QUICK SORT FOR LINKED LISTS

//Function to partiton the list and find PIVOT
Node* Partition(Node *l,Node *h) {
	
	int pivot = h->data; //PIVOT is the last node-Right most
	
	Node *Pindex = l->prev; //initially NULL
	
	
	//traversing the list
	for(Node *j = l ; j!=h ; j=j->next) {
		
		if(j->data <= pivot) {
			
			//similar to incrementing Pindex = Pindex + 1
			Pindex = (Pindex==NULL) ? l : Pindex->next;
			
			swap(j->data,Pindex->data);
			
			
		}
		
	}
	
	Pindex = (Pindex==NULL) ? l : Pindex->next;
	swap(Pindex->data,h->data);
	
	return Pindex; //returns the pointer to PIVOT node	
			
}

//function to return the last node of list
Node *LastNode(struct Node *tail) {
	
	while(tail && tail->next) {
		tail = tail->next;	
	}
	return tail;
}	


void _QuickSort(Node *l,Node *h) {
	
	
	if(h!=NULL &&  l != h &&  l!=h->next) {
		
		//calling partition function to return the pointer to PIVOT
		struct Node *pIndex = Partition(l,h);
		
		//QuickSort on the left of Pindex-PIVOT
		_QuickSort(l,pIndex->prev);
		
		//QuickSort on the Right of Pindex-PIVOT node
		_QuickSort(pIndex->next,h);
		
	}
	
}


//main function to sort list
void QuickSort(struct Node *head) {
	
	Node *temp = head;
	
	while(temp->next!=NULL) {
		temp=temp->next;
	}
	
	//temp is the last node
	
	//calling the recursive _quicksort
	_QuickSort(head,temp);
}








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
    

//function to reverse a doubly linked list using recursion and return the new head
Node  *reverseRec(Node *head)
{
	Node *temp;
	
	
	if(!head) return NULL;
	
	//first swap the next and prev pointers
	temp=head->next;
	head->next = head->prev;
	head->prev = temp;

	//if prev becomes NULL, this means we have reversed the list and reached end
	if(head->prev==NULL)
	{
		
		return head;	
	}	
	
	//otherwise simply keep swapping next nd prev until we reach the end and prev becomes NULL
	return reverseRec(head->prev);		
}


//function to find the maximum occuring item in list-simple iterative solution   
int maxOccuringItem(Node *head)
{
	if(head==NULL)	return -1;
	
	Node *temp=head;
	Node *temp1;
	while(temp!=NULL)
	{
		temp1 = temp;
		while(temp1->next!=NULL)
		{
			if(temp->data==temp1->next->data)
			{
				return temp->data;	
			}
			
			temp1 = temp1->next;
		}
		temp =temp->next;
	}
	return 0;
}
//TIME COMPLEXTIY=O(N*N)
    

void printAlternateRec(Node *head,bool odd=true)
{
	if(head==NULL) return ;

	if(odd==true)
	{
	
		
		cout<<head->data<<"<->";
		
		
	}	
	
	//this bool variable will make sure to print alternate nodes
	printAlternateRec(head->next,!odd);	
}



void printEvenNodes(Node *head,bool even=false)
{
	if(head==NULL) return;
	
	if(even==true)
	{
		
		cout<<head->data<<"->";
		
		
	}
	
	printOddEvenNodes(head->next,!even);
}

int main() {
	
	
	
//	
//	struct Node *n1 = new Node();
//	struct Node *n2 = new Node();
//	struct Node *n3 = new Node();
//	struct Node *n4 = new Node();
//	
//	
//	//assigning head as first node	
//	
//	n1->data=20;
//	n2->data=3;	
//	n3->data = 10;
//	
//	
//	n1->next = n2;
//	n1->prev = NULL;
//	
//	
//	n2->prev = n1;
//	n2->next = n3;
//	n3->prev=n2;
//	n3->next=NULL;
	
//	
//	n.traverse(n1);
	
	
	
//	InsertPos(20,1);
//////
//	InsertPos(30,2);
//	InsertPos(100,3);
////	

	InsertHead(20);
	InsertPos(2,10);
	
	InsertPos(3,11);
	
	InsertPos(4,5);
	InsertPos(5,6);
	InsertPos(6,13);
	InsertPos(7,12);
	InsertPos(8,8);
//	


//SortedInsert(&head, 10);
//SortedInsert(&head,1);
//SortedInsert(&head,1);
//SortedInsert(&head,1);
//SortedInsert(&head,15);
//SortedInsert(&head,100);
//SortedInsert(&head,15);
	
	cout<<"The list is: "<<endl;
	traverse(head);
	
	RemoveDuplicate(head);
	
	
	cout<<endl;
	
	
	
	QuickSort(head);
	
	
	traverse(head);

	
	return 0;
}
