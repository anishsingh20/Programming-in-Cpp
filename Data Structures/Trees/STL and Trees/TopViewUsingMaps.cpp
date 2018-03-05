#include<iostream>
#include<queue>
#include <map>




/*program to print the TOP VIEW OF A TREE- 

TOP VIEW CONSISTS OF THE NODES WHICH ARE TOP MOST AT THAT HORIZONTAL DISTANCE
HORIZONTAL DISTANCE-HD IS - 1 FOR A LEFT EDGE AND +1 FOR A RIGHT EDGE FROM THE HD OF PARENT NODE
*/
//using namespace std;


using namespace std;


struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left,*parent;
	BinaryTreeNode *right;
};



//store HD in a map using level order traversal using a single queue
void TopViewLevelOrder(BinaryTreeNode *root)
{
	if(!root) return ;
	
	map<int,int>TreeMap;
	
	queue< pair<BinaryTreeNode* ,int> > q; //making a queue with 2 fields
	
	q.push(make_pair(root,0)); //hd of root is 0
	
	while(!q.empty())
	{
		
		//now popping the front of queue
		pair<BinaryTreeNode *,int>p = q.front();
		BinaryTreeNode *temp= p.first;  
		int hd = p.second;
		q.pop();
		
		
		//if HD not found in MAP, that means it is the first HD in tree and store it in map and also print it,
		//to print the topmost root in HD
		if(TreeMap.find(hd)==TreeMap.end())
		{
			TreeMap[hd] = temp->data;
			
			cout<<temp->data<<" ";
		}
		
		//otherwise simply push left and right subchilds in queue like we do in any level order traversal
		
		if(temp->left)	q.push(make_pair(temp->left,hd-1)); //for left edge push left and hd-1
		
		
		if(temp->right)	q.push(make_pair(temp->right,hd+1)); //for right push right in queue and its hd+1
		
		
	}
	
	
	
}

//TIME COMPLEXITY = O(N)


//Method-2 Only valid for Full Binary Trees

void left(BinaryTreeNode *root)
{
    if(root->left)
            left(root->left);
    
    cout<<root->data<<" ";
}

void right(BinaryTreeNode *root)
{
    cout<<root->data<<" ";
    if(root->right)
        right(root->right);
}

void topView(BinaryTreeNode *root)
{
    
   
    if(root->left)
        left(root->left);
        
    cout<<root->data<<" ";
  
   if(root->right)
        right(root->right);
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



//Other method to find top view of a tree


int main()
{
	struct BinaryTreeNode *root1= NULL;
	
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	Insert(&root1,7);
//	Insert(&root1,8);
//	Insert(&root1,9);

	TopViewLevelOrder(root1);
	cout<<endl;
	
	topView(root1);
	
	return 0;
	
}

