#include<iostream>


using namespace std;




struct node{
	
	int data;
	
	node *next,*prev;



node *newNode(int data)
{
	node *temp = new node();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	temp->next = NULL;
	
	return temp;
}


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





void Inorder(node *root)
{
	if(!root)	return;
	
	Inorder(root->left);
	
	cout<<root->data<<" ";
	
	Inorder(root->right);
}



int main()
{
	
}
