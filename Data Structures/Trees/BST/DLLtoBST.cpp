#include<iostream>


using namespace std;




struct node{
	
	int data;
	
	node *next,*prev;

};




int lengthList(struct node *head)
{
	int count=0;
	
	while(head)
	{
		head=head->next;
		count++;
	}
	
	return count;
	
	
}

//funtion to find the middle of the list
struct node *FindMiddle(struct node *head)
{
	if(head==NULL)
		return NULL;
		
	struct node *temp=head;
	
	int l=0;
	int h = lengthList(head);
	int mid = l + (h-l)/2; //finding the middle index in list
	
	//traversing till mid of list
	for(int i = 0 ; i < mid ; i++)
	{
		temp = temp->next;
	}
	
	//temp is now the pointer middle node
	return temp;
	
	
	
	
}


node *ConvertDLLToBST(node *head)
{
	
	if(!head)
		return NULL;

		
	//finding the middle node
	
	node *temp = FindMiddle(head);
	
	node *p = head;
	while(p->next!=temp)
		p = p->next;
	
	p->next  = NULL;
	
	node *high = temp->next;
	temp->next = NULL;
	
	temp->prev = ConvertDLLToBST(head);
	
	temp->next = ConvertDLLToBST(high);
	
	return temp;
}//TIME COMPLEXITY  = O(n)




void Inorder(node *root)
{
	if(!root)	return;
	
	Inorder(root->prev);
	
	cout<<root->data<<" ";
	
	Inorder(root->next);
}


void push(struct node** head, int new_data)
{
    /* allocate node */
    struct node* new_node = new node();
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* since we are adding at the begining,
      prev is always NULL */
    new_node->prev = NULL;
 
    /* link the old list off the new node */
    new_node->next = (*head);
 
    /* change prev of head node to new node */
    if((*head) !=  NULL)
      (*head)->prev = new_node ;
 
    /* move the head to point to the new node */
    (*head)    = new_node;
}


int main()
{
	node *head=NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,6);
	
	
	
	node *root = ConvertDLLToBST(head);
	
	cout<<"Inorder traversal of BST is: "<<endl;
	
	Inorder(root);
	
}
