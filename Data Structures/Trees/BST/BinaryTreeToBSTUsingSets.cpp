#include<iostream>
#include<set>

using namespace std;

/*program to convert a Binary tree to BST using sets as containers.

Sets in cpp are implemented using self-balancing BST. hence it by default sorts the data.
//This method will consume extra space of order O(n).


*/

struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};



void StoreInorderInSet(BSTnode *root, set<int>&s)
{
	if(!root)
		return;
		
//	StoreInorderInSet(root->left,s);
//	
//	s.insert(root->data); // insertion takes order of O(logn) for sets
//	
//	StoreInorderInSet(root->right,s);

	BSTnode *curr = root;
	BSTnode *pre;

	while(curr)
	{
		//case-1 if current node has no left child
		if(curr->left==NULL)
		{
			
			s.insert(curr->data);
			
			curr = curr->right;
				
		}
		
		else
		{
			//find the inorder predecessor of current node
			//inorder predecessor is the right most in left subtree i.e
			//maximum element in left subtree or left child itself
			pre = curr->left;
			
			while(pre->right!=NULL && pre->right!=curr)
			{
				pre = pre->right;	
			}	
			
			//create threads
			if(pre->right==NULL)
			{
				pre->right = curr;
				
				curr = curr->left;
				
			}
			
			//if the thread between current and its predecessor already exists.
			else
			{
				pre->right = NULL;
				
				s.insert(curr->data);
					
				curr = curr->right;	
					
			}
		}
	
	}
} //Time complexity  = O(nlogn) ,Space complexity - O(1) constant space as no recursion or stack is used to do inorder traversal


//function to copy items of set one by one to the tree while doing inorder traversal
void SetToTree(set<int>&s,BSTnode *root)
{
	
	//base condition
	if(!root)
		return;
	

	
	//first move to the left subtree and update items
	SetToTree(s,root->left);
	
	//iterator initially pointing to the beginning of set
	set<int>::iterator it=s.begin();
	
	root->data = *it; //copying the item in set(sorted) to the tree while inorder traversal
	s.erase(it);//now erasing the beginning item.
	
	
	//now move to right subtree and update items
	SetToTree(s,root->right);

	
} //T(n) = O(nlogn) time


//this is function which will convert the Binary tree to BST
void BinaryTreeToBST(BSTnode *root)
{
	
	set<int>s;
	
	//populating the set with the tree's inorder data
	StoreInorderInSet(root,s);
	
	//now sets are by default sorted as they are implemented using self-balancing BST
	
	//copying items from set to the tree while inorder traversal which makes a BST
	SetToTree(s,root);
	
}//Time complexity  =  O(nlogn) , Space complexity = O(n) as extra space for sets is consumed.

BSTnode *newNode(int data)
{


	BSTnode *temp = new BSTnode();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	
	return temp;
}


void Inorder(BSTnode *root)
{
	if(!root)	return;
	
	Inorder(root->left);
	
	cout<<root->data<<" ";
	
	Inorder(root->right);
}

int main()
{
	BSTnode *root=newNode(5);

	root->left = newNode(7);
	root->right = newNode(9);
	root->right->left = newNode(10);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->right->right = newNode(11);
	
	//converting the above Binary tree to BST
	BinaryTreeToBST(root);
	
	cout<<"Inorder traversal of BST is: "<<endl;
	
	Inorder(root);
	
}

