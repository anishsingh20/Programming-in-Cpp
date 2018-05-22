#include<iostream>
#include<set>

/*Program to check if a BST has dead end or not
*/
using namespace std;

struct node {
	int data;
	struct node *left,*right;	
		
};


struct node *newNode(int data)
{
	struct node *temp = new node();
	temp->data = data;
	
	return temp;
}


struct node* insert(node *root,int data)
{
	if(root==NULL)
	{
		return newNode(data);
	}
	
	if(root->data > data)
	{
		root->left = insert(root->left,data);
		
	}
	
	if(root->data < data)
	{
		root->right = insert(root->right,data);
	}
		
	return root;
	
}

void FillHashMap(node *root,set<int> &allNodes,set<int>LeafNode)
{
	if(root==NULL)
		return;
		
	allNodes.insert(root->data);
	
	
	//inserting leaf nodes in a separate hash map
	if(root->left==NULL && root->right==NULL)
	{
		LeafNode.insert(root->data);
		return;
	}
	
	//recursively calling the function on left and right subtrees
	FillHashMap(root->left,allNodes,LeafNode);
	FillHashMap(root->right,allNodes,LeafNode);
}



bool DeadEndOrNot(node *root)
{
	set<int>all_nodes,leafNodes;
	
	if(!root)
		return false;
		
		
	all_nodes.insert(0);
	//populating the hash maps
	FillHashMap(root,all_nodes,leafNodes);
	
	
	//now checking if there exists a leaf x and nodes with x+1 or x-1
	for(set<int>::iterator i = leafNodes.begin(); i != leafNodes.end() ; i++)
	{
		int x =  (*i);//storing the leaf node
		
		if(all_nodes.find(x+1) != all_nodes.end() && all_nodes.find(x-1) != all_nodes.end())
		   {
		   		return true;
		   }
		   
	}
	
	
		
	
}



//recursive solution
bool checkDeadEnd(node *root, int min, int max)
{
    if(root == NULL)
        return(true);
    if(root->data == min && root->data == max)
        return(false);
    return(checkDeadEnd(root->left, min, root->data-1) && checkDeadEnd(root->right, root->data+1, max));
}

bool isDeadEnd(node *root)
{
    return(!checkDeadEnd(root, 1, INT_MAX));
}


int main()
{
	    
    node *root = NULL;
    insert(root, 8);
    insert(root, 5);
    insert(root, 2);
    insert(root, 3);
    insert(root, 7);
    insert(root, 11);
    insert(root, 4);
    
    
   cout<<isDeadEnd(root)<<endl;
	    
	
return 0;
}
