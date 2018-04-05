#include<iostream>

using namespace std;


/*PRogram to convert a sorted linked list to a Binary Search tree-

1)Method-1 )Similar to the array version-1)Find middle node of list and make it as root
					 2) Recursively do the same for left and right half of list.
					 	2.1)left child is the middle node in lower half of list
						2.2)right child is the middle node in upper half of list
	This method takes time O(nlogn)			


	2)Efficient method which takes O(n) time. is to build the tree in bottom-up fashion
*/


struct node{
	
	int data;
	
	node *next,*left,*right;
};



node *newNode(int data)
{
	node *temp = new node();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	temp->next = NULL;
	
	return temp;
}


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



//recursive function to build BST using bottom-up approach
node *ListToBSTRecur(node **head,int start,int end)
{
	
	//base condition
	if(start>end)
		return NULL;
	
	//finding middle index of list	
	int mid = start + (end-start)/2;
	
	//recursively build the left subtree i.e till middle of list
	node *LeftChild  = ListToBSTRecur(head,start,mid-1);
	
	
	
	//now generate root and link it with the left subtree
	node *root = newNode((*head)->data);
	root->left = LeftChild;
	
	//moving the head pointer of list
	*head = (*head)->next;
	
	//now recursively generate right subtree and link it with the root
	
	root->right = ListToBSTRecur(head,mid+1,end);
	
	return root;
	
} //TIME COMPLEXITY = O(n)


node *ListToBST(node *head)
{
	int n = lengthList(head);
	
	return ListToBSTRecur(&head,0,n-1);
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




void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node();
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

int main()
{

	struct node* head = NULL;
	    push(&head, 7);
	    push(&head, 6);
	    push(&head, 5);
	    push(&head, 4);
	    push(&head, 3);
	    push(&head, 2);
	    push(&head, 1);
		
	
	//converting list to a BST
	node *root = ListToBST(head);
	
	Inorder(root);
	
}
