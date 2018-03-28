#include<iostream>

using namespace std;

/*Program to find Floor and Ceiling if a key in BST

*/


struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};



BSTnode *FindFloor(BSTnode *root,int key)
{
	//base case
	if(root==NULL) 
		return root;
	
	//if key is equal to root's key
	if(root->data==key)
		return root;
		
	//if key is less than root's key , the the floor is definitely in left subtree,sor we search in left subtree
	if( key < root->data)
		return FindFloor(root->left,key);
		
		
	//otherwise floor is in right subtree, so we search in right subtree
	BSTnode *floor = FindFloor(root->right,key);
	
	//if floor in right subtree found, return it, otherwise floor is root
	return (floor) ? floor : root;
}


int f,c;


void FindFloorCeil(BSTnode *root,int key)
{
	
	if(!root)	return;
	
	if(root->data==key)
	{
		c=f=key;
	}
	
	else if(root->data < key)
	{
		f = root->data;
		FindFloorCeil(root->right,key);
		
	}
	
	else
	{
		c = root->data;
		FindFloorCeil(root->left,key);
		
	}
}



//similar method to find the floor
int Floor(BSTnode *root,int key)
{
	if(!root)
		return -1;
		
		
	if(root->data==key)
		return root->data;
		
	//case when floor will be in left subtree of root
	if(root->data > key)
		return Floor(root->left,key);
	
	//otherwise floor if in right subtree, or current node itself
	
	if(root->data < key)
	{
		int floor = Floor(root->right,key);
		/*floor of the key could be in the
		right subtree, but only if there is a key smaller than or equal to the key in the right subtree;
		if not (or if the key is equal to the the key at the root) then the floor is the current root.
		
		imp condition-if the key at root is smaller than or equal to the floor in right subtree
		*/
		
		return (floor >= root->data) ? floor : root->data;
	}


}


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


BSTnode *insert(BSTnode *root,int value)
{
	//we first need to find the appropiate location to insert data
	if(root==NULL)
	{
		BSTnode *temp  = new BSTnode();
		temp->data = value;
		temp->left = temp->right = NULL;
		
		root = temp;
	}
	
	
	else if(root->data > value)
	{
		root->left = insert(root->left,value);
	}
		
	else if(root->data < value)
	{
		root->right = insert(root->right,value);
	}
	
	
	
	//returning root of the updated tree
	return root;
}

int main()
{
	
	BSTnode *root  = newNode(4);
	
	insert(root,2);
	insert(root,3);
	insert(root,1);
	insert(root,7);
	insert(root,6);
	insert(root,12);
	insert(root,20);
	
//	cout<<FindFloor(root,100)->data;
//	cout<<endl;
//	cout<<"another method to find floor"<<endl;
//	cout<<Floor(root,13);

	//finding floor and ceil
	FindFloorCeil(root,10);
	
	cout<<f<<endl;
	cout<<c<<endl;

}

