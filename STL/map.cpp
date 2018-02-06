#include<iostream>
#include<map>

/*
Maps are associative containers that store elements in a mapped fashion. 
Each element has a key value and a mapped value. 
No two mapped values can have same key values.
*/

using namespace std;


int main()
{
	map<int,string> m;
	
	m.insert(pair <int,string> (1,"Anish"));
	m.insert(pair <int,string> (2,"mrinal"));
	m.insert(pair <int,string> (3,"Vaibhav"));
	m.insert(pair <int,string> (4,"Rasila"));
	//can also insert using
	m.insert(make_pair(10,"Lucky"));	
	
	map<int,string>::iterator i;
	
	
	//can also do random access using the key value as subscript-O(1)
	cout<<m[2]<<endl; //prints mrinal
	
	
	//traversing the map using iterator
	for(i = m.begin(); i != m.end();i++)
	{
		cout<<i->first;
		cout<<" | ";
		cout<<i->second;
		
		cout<<endl;
	}
	
	
	
	cout<<"Erasing--"<<endl;
	
	
	//will erase elements from begin of map till 2nd element , not 3
	// remove all elements up to element with key = 3 in found
	 m.erase(m.begin(), m.find(3) );
	 
	 for(i = m.begin(); i != m.end();i++)
	{
		cout<<i->first;
		cout<<" | ";
		cout<<i->second;
		
		cout<<endl;
	}
	 
	
	//find() method returns an iterator to key passed as argument
	
	map<int,string>::iterator i1;
	i1 = m.find(3);
	cout<<i1->second; //prints "mrinal"
	
	
	
	return 0;
	
}
