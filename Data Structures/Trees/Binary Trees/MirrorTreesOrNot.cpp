#include<iostream>
#include<queue>

using namespace std;

//PROGRAM TO CHECK IF 2 TREES ARE MIRROR OF EACH OTHER 

struct BinaryTreeNode
{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


//recursive program to find if 2 trees are Mirrors of each other or not
bool MirrorOrNot(struct BinaryTreeNode *root1, struct BinaryTreeNode *root2)
{
	//base condition
	if(!root1  && !root2) return true;
	
	if(!root1 || !root2) return false;
	

	//condition to check if the 2 roots are same or not
	if(root1->data != root2->data) return false;
	
//	else
//		 return MirrorOrNot(root1->left,root2->right) && MirrorOrNot(root1->right,root2->left);
//	
	
		//now recur down to left and right of 1 and 2 trees
		bool left = MirrorOrNot(root1->left,root2->right);
		
		bool right = MirrorOrNot(root1->right,root2->left);
		return left&&right;
		//OR we can also do below
		//if both left and right 
//		if(left&&right) return true;
//		else return false;
	
	

}



//another iterative method to tell if a tree is symmetric or not
bool isSymmetric(TreeNode* root) {
        
         queue<TreeNode *>q;
        
        if(!root)
                return true;
        
        TreeNode *temp,*temp1;
        
        q.push(root);
        q.push(root);
        
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            temp1 = q.front();
            q.pop();
            
            if(!temp1 && !temp) continue;
            
            if(!temp1 || !temp    )    return false;
            
            if(temp->val!=temp1->val)   return false;
             
                    q.push(temp->left);
            
            
                    q.push(temp1->right);
            
            
                    q.push(temp->right);
            
            
                    q.push(temp1->left);
        }     
        return true;
    
    }
    
    
    
    

void Insert( struct BinaryTreeNode **root,int data)
{
	struct BinaryTreeNode *new_node = new BinaryTreeNode();
	struct BinaryTreeNode *temp;
	queue<BinaryTreeNode *> q;
	new_node->data = data;
	new_node->left=NULL;
	new_node->right=NULL;
	
	if(*root==NULL)
	{
		*root = new_node;
		return;
	}
	
	q.push(*root);
	
	while(!q.empty())
	{
		temp  = q.front();
		q.pop();
		
		if(temp->left==NULL)
		{
			temp->left = new_node;
			return;
			
			
		}
		
		else
		{
			q.push(temp->left);
		}
			
		if(temp->right==NULL)
		{
			temp->right = new_node;
			return;
			
		}	
		
		else
		{
			q.push(temp->right);
		}
	}
	
}



int main()
{
	
	struct BinaryTreeNode *root1=NULL;
	struct BinaryTreeNode *root2 =NULL;
	
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	Insert(&root1,7);
	


	Insert(&root2,1);
	Insert(&root2,3);
	Insert(&root2,2);
	Insert(&root2,7);
	Insert(&root2,6);
	Insert(&root2,5);
	Insert(&root2,4);
		
	cout<<MirrorOrNot(root1,root2);
	
	
	return 0;
}
