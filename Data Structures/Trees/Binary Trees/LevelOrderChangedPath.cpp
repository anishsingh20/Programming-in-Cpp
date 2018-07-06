#include<iostream>
#include<queue>
#include<stack>

using namespace std;


struct node{
	
	int data;
	node *left,*right;
};


void levelOrderChanged(node *root)
{
	stack<node*>s; //stack to store a level nodes
	
	queue<node*>q; //queue to store next level nodes
	node *temp,*temp1;
	
	int ct = 0;
	int sz=0;
	
	q.push(root);
	
	bool righttoleft = false;
	
	while(!q.empty())
	{
		ct++;
		sz = q.size();
 
        // Do a normal level order traversal
        	for (int i = 0; i < sz; i++)
		 {
            	
		    	temp  = q.front();
			q.pop();
			
            		
            		
			if(righttoleft==false)
			{
				cout<<temp->data<<" ";
			}
			
			else
				s.push(temp);
			
			
			if(temp->left)
				q.push(temp->left);
			
			if(temp->right)
				q.push(temp->right);
	
		}
	
		
		if(righttoleft == true)
		{
			
			while(!s.empty())
			{
				temp = s.top();
				s.pop();
				
				cout<<temp->data<<" ";
			}
						
		}
		
		if(ct==2)
		{
			righttoleft = !righttoleft;
			ct=0;
			
		}
	
		cout<<"\n";		
	}
	
}

node *newNode(int data)
{
	node *temp = new node();
	temp->data = data;
	
	return temp;
}

int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(3);
    root->left->right->right = newNode(1);
    root->right->left->left = newNode(4);
    root->right->left->right = newNode(2);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(2);
    root->left->right->left->left = newNode(16);
    root->left->right->left->right = newNode(17);
    root->right->left->right->left = newNode(18);
    root->right->right->left->right = newNode(19);
    
	levelOrderChanged(root);

}
