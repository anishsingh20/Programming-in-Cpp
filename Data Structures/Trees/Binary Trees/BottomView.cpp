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



//function to populate a map with node at each horizontal distance in Postorder
//void PopulateMap(Node *root,map < int,int> &m, int hd )
//{
//	if(!root) return;
//	
//	
//	
//	//recur to left and right subtrees
//	m[hd] = root->data;
//	PopulateMap(root->left,m,hd-1);
//	
//	PopulateMap(root->right,m,hd+1);
//	
//	
//}
//
//void BottomView(Node *root)
//{
//	
//	map<int,int> Map;
//	map<int,int>::iterator it;
//	
//	//populate the map
//	
//	PopulateMap(root,Map,0);
//	
//	for(it=Map.begin();it!=Map.end();it++)
//	{
//		cout<<it->first<<" ";
//		//last node at each horizontal distance i.e last node in the vector
//		cout<<it->second<<endl;
//	}
//	
//	
//}


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
}
