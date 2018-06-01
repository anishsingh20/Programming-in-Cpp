#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<set>


using namespace std;

//PROGRAM TO PRINT NODES AT EACH LEVEL IN SORTED MANNER USING MAPS-TIME COMPLEXITY = O(nlogn)
//as maps are implemented using self balancing Binary search trees


struct BinaryTreeNode{
	
	int data;
	struct BinaryTreeNode *left,*right;
};



void SortedLevelPrintUtil(struct BinaryTreeNode *root, map< int,vector<int> > &Map,int level)
{
	if(!root) return ;
	
	SortedLevelPrintUtil(root->left,Map,level+1); //increment level as we recur to each left node
	
	Map[level].push_back(root->data); //insert level as key and the node's data in vector
	
	SortedLevelPrintUtil(root->right,Map,level+1); //increment level as we recur to each right node
}


void SortedLevelPrint(struct BinaryTreeNode *root)
{
	map< int,vector<int> > Map;
	
	map< int,vector<int> >::iterator i;
	
	//fill the map
	
	SortedLevelPrintUtil(root,Map,0);
	
	cout<<"level"<<setw(10)<< " Sorted Level Nodes:"<<endl;
	
	for(i=Map.begin(); i!=Map.end();i++)
	{
		//now we just need to sort the vector
		
		cout<<i->first<<"      |    ";
		
		sort(i->second.begin(), i->second.end());
		
		for(int j= 0 ; j< i->second.size();j++)
		{
			cout<<i->second[j]<<" ";
		}
		
		cout<<endl;
	}
}


//Method-2, simple method using level order traveral using a queue, and store each level data in a set
//now set automatically sorts the data inside it. The only thing we need to care is tha we need to empty the set after
//visiting each level

void SortedLevelOrderTraversal(BinaryTreeNode *root)
{
	queue<BinaryTreeNode *>q;
	BinaryTreeNode *temp;
	set<int> S;
	set<int>::iterator i;
	
	if(root==NULL) return;
	
	q.push(root);
	q.push(NULL); //marker for completion of level-0
	
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		
		//when a level has been traversed
		if(temp==NULL)
		{
			if(!q.empty())
				q.push(NULL); //marker for completion of another level 
				
			for(i = S.begin(); i != S.end() ; i++ )
			{
				cout<<*i<<" ";
			}
			cout<<endl;
			
			S.clear(); //emptying the set after each level is traversed
		}
		
		else
		{
			S.insert(temp->data);//O(logn)
			
			if(temp->left)	q.push(temp->left);
			
			if(temp->right) q.push(temp->right);
		}
	}
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



//METHOD-3  : USING LEVEL ORDER and MAP but extra memory is consumed

void SortedLevelOrderMap(struct BinaryTreeNode *root)
{
	//a queue to store level and node
	queue< pair<BinaryTreeNode*,int> > q;

	//map to store level as key and their corresponding nodes at each level
	map< int, vector<int> > Map;
	
	if(root==NULL) return;
	
	q.push(make_pair(root,0)); //level 0
	
	while(!q.empty())
	{
		pair<BinaryTreeNode*,int> Pair = q.front();
		q.pop();
		int level = Pair.second;//level
		BinaryTreeNode *temp = Pair.first;//node
		
		//simply insert the level and nodes at eack level in map
		Map[level].push_back(temp->data);
		
		if(temp->left) q.push(make_pair(temp->left,level+1));
		
		if(temp->right) q.push(make_pair(temp->right,level+1));
		
		
	}
	
	
	map< int,vector<int> >::iterator i;
	
	for(i = Map.begin(); i != Map.end(); i++ )
	{
		cout<<"level "<<i->first<<" has sorted : ";
		
		//sorting the vector of nodes inside map
		sort(i->second.begin(),i->second.end());
		
		for(int j = 0; j < i->second.size(); ++j)
		{
			cout<<i->second[j]<<" ";
			
		}
		
		cout<<endl;
		
	}
		
} 





int main()
{
	struct BinaryTreeNode *root1= NULL;
	
	Insert(&root1,7);
	Insert(&root1,10);
	Insert(&root1,3);
	Insert(&root1,8);
	Insert(&root1,100);
	Insert(&root1,6);
	Insert(&root1,9);
	
	
	SortedLevelPrint(root1);
	
	cout<<endl;
	
	SortedLevelOrderTraversal(root1);
	
	cout<<endl;
	 
	SortedLevelOrderMap(root1);

return 0;


}

