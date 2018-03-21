#include<iostream>

using namespace std;


/*PRogram to convert a sorted linked list to a Binary Search tree-

1)Method-1 )Similar to the array version-1)Find middle node of list and make it as root
					 2) Recursively do the same for left and right half of list.
					 	2.1)left child is the middle node in lower half of list
						2.2)right child is the middle node in upper half of list			

*/


struct node{
	
	int data;
	
	node *next,*left,*right;
};


//function to count the length of list i.e number of nodes
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
	
	for(int i = 0 ; i < mid ; i++)
	{
		temp = temp->next;
	}
	
	
	return temp;
	
	
	
	
}


struct node *ListToBST(struct node *head)
{
	
}


void SortedInsert(node **root,int value)
{
	
}



node *newNode(int data)
{
	node *temp = new node();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	temp->next = NULL;
	
	return temp;
}


int main()
{
	struct node *head = newNode(1);
	
	head->next  = newNode(2);
	head->next->next = newNode(3);
	
	head->next->next->next = newNode(4);
	
	cout<<lengthList(head);
	cout<<FindMiddle(head)->data<<endl;
	
}
