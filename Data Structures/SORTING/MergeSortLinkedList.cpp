#include<iostream>

//Merge sort for a linked list
using namespace std;


struct Node{
	Node *next;
	int data;
};


int length(struct Node *head) {
	int count = 0;
	while(head!=NULL) {
		count++;
		head=head->next;
	}
	return count;
	
}//TIME COMPLEXITY   = O(n)

void SplitList(struct Node *head, Node **headA, Node **headB)
{
	struct Node *temp=head;
	if(head==NULL || head->next == NULL)
	{
		(*headA) = head;
		(*headB) = NULL;	
		 return;	
	}
		
	
	//assigning headA of sublist as head
	(*headA) = head;
	int len = length(head); //O(n)
	
	int l=0,h=(len-1),mid;
	
	//finding mid index of list
	mid = (l + (h-l)/2);
	
	
	for(int i=0;i<mid;i++) 
	{
		
		temp=temp->next;
	}
	
	(*headB) = temp->next;
	
	temp->next = NULL;
	
	
}//TIME COMPLEXITY = O(n) and space consumed by the pointers/references


//function to merge 2 linked lists in sorted manner
Node* SortedMerge(struct Node *headA, struct Node *headB) 
{
	struct Node *new_head=NULL;
	//base condition
	if(headA==NULL) return headB;
	if(headB==NULL) return headA;
	
	if(headA->data <= headB->data) {
		new_head = headA;
		
		new_head->next = SortedMerge(headA->next,headB );
		
	}
	
	else {
		
		new_head = headB;
		
		new_head->next = SortedMerge(headA,headB->next);
	}
	
	return new_head;
	
} //TIME COMPLEXITY = O(1) , SPACE COMPLEXITY = O(n) due to recursion and usage of stack space

//recursive merge sort function
void mergeSort(struct Node **act_head) 
{
	struct Node *head=(*act_head);
	struct Node *a, *b;
	//base condition
	if( head==NULL || head->next == NULL) {
		return;
	}
	
	//now split the list in 2 sublists
	SplitList( head , &a , &b );
	
	//recursively splitting sorting  the sublists
	mergeSort(&a);
	mergeSort(&b);
	
	//merging the 2 sublists into one sorted list which returns the new head of sorted list
	*act_head = SortedMerge(a,b);

}//TIME COMPLEXITY = O(nlogn) in worst case, but it is not in-place sorting algorithm, due to 2 new sublists ar formed which consume extra memory 



//function to traverse the list
void printList(struct Node **head) 
{
	while( (*head)!=NULL ) {
		
		cout<<(*head)->data<<"-->";
		(*head)=(*head)->next;
	}
	cout<<"NULL";
}


int main()
{
	
	struct Node *n1 = new Node();
	struct Node *n2 = new Node();
	struct Node *n3 = new Node();
	struct Node *n4 = new Node();
	struct Node *n5 = new Node();
	
	
	
	n1->data = 90;
	n2->data = 10;
	n3->data = 80;
	n4->data = 15;
	n5->data = 60;
	
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;
	
	
	//sorting the list
	mergeSort(&n1);
	
	
	//printint the sorted list
	printList(&n1);
	
	
	
}
