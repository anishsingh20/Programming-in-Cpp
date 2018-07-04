#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

/*Program to print the bottom view of a binary tree-
Bottom view of a binary tree is the bottomost node at its horizontal distance. Horizontal distance is -1 for a left edge and +1 for a right edge.
Whereas Topview was the top most node at its horizontal distance.
*/
struct Node {
	
	int data;
	Node *left,*right;
	
};


Node *newNode(int data){
	Node *temp = new Node;
	
	temp->data = data;
	temp->right=temp->left=NULL;

	
	return temp;
}




//Method-1 Using hash Map
void BottomViewUtil(Node *root, int ht, int hd, map< int, pair<int,int> >&m)
{
	if(!root) return;
	
	//inserting in map
	if(m.find(hd)==m.end())
	{
		m[hd] = make_pair(root->data,ht);
	}
	
	//otherwise compare height of already present node and current node
	else
	{
		pair<int,int> p = m[hd];
		
		//if height of new node is greater , then add that in the map
		if(p.second <= ht)
		{
			m[hd].second = ht;
			m[hd].first = root->data;
		}
		
		
	}
	
	
	//simply recur to the left and right subtrees
	
	BottomViewUtil(root->left,ht+1,hd-1,m);
	BottomViewUtil(root->right,ht+1,hd+1,m);
}


void BottomViewMap(Node *root)
{
	map< int,pair<int,int> > Map;
	
	map<int ,pair<int,int> >::iterator it;
	
	//populating the map
	BottomViewUtil(root,0,0,Map);
	
	
	for(it = Map.begin();it!=Map.end();it++)
	{
		cout<<it->first<<" ";
		cout<<it->second.first<<endl;
	}
	
}


//similar to Top view using level order and a map
void BottomView(Node *root)
{
	map<int,int> Map;
	map<int,int>::iterator it;
	
	queue< pair<Node*, int> > q;
	
	if(!root) return;
	
	//initially pusing root and its horizontal distance
	q.push(make_pair(root,0));
	
	
	while(!q.empty())
	{
		pair<Node*,int> p = q.front();
		q.pop();
		
		Node *temp = p.first;
		int hd = p.second;
		
		
		//inserting the dequeued item in the hash map. The last inserted item with same horizontal distance will be updated in the map.
		//This will ensure that the bottom most at each Hd is inserted
		//Every time we find a node having same horizontal
        	// distance we need to replace the data in map
        
		Map[hd] = temp->data;
		
		
		if(temp->left)
			q.push(make_pair(temp->left,hd-1));
			
		if(temp->right)
			q.push(make_pair(temp->right,hd+1));
	}
	
	for(it=Map.begin();it!=Map.end();it++)
	{
		cout<<it->first<<"-- "<<it->second<<endl;
	}
}


void UtilBottomView(Node *root,map<int,vector<int> >&m,int hd=0)
{
    if(!root) return;
    
    UtilBottomView(root->left,m,hd-1);
    
    m[hd].push_back(root->data);
    
    UtilBottomView(root->right,m,hd+1);
    
}
void bottomView(Node *root)
{
    
    map<int,vector<int> >m;
    map<int,vector<int> >::iterator it;
    //populating the map
    UtilBottomView(root,m);
   
    for(it = m.begin();it != m.end();it++)
    {
         
         int j = it->second.size()-1;
         
         cout<<it->second[j]<<" ";
         
    }
    
}

int main()
{
	Node *root = newNode(20);
	root->left = newNode(8);	
	root->right = newNode(22);
	root->left->left = newNode(5);
	root->left->right = newNode(3);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right->right = newNode(25);
	
	BottomView(root);
	cout<<endl;
	
	bottomView(root);
}
