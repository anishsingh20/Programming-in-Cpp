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
	
}

void SplitList(struct Node *head, Node **headA, Node **headB)
{
	if(head==NULL || head->next == NULL)
	{
		(*headA) = head;
		 headB = NULL;	
		 return;	
	}
	
	(*headA) = head;
	int len = length(head);
	
	int l=0,h=(len-1),mid;
	
	//finding mid index of list
	mid = (l + (h-l)/2);
	struct Node *temp;
	
	for(int i=0;i<mid;i++) 
	{
		
		temp=temp->next;
	}
	
	(*headB) = temp->next;
	
	temp->next = NULL;
	
	
}


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
		
		new_head->next = SortedMerge(headA=B->next,headA );
	}
	
	return new_head;
	
	
	
}




void mergeSort(struct Node *head) 
{
	
	
}

int main()
{
	
}
