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
	map<string,int> m;
	
	m.insert(pair <string,int> ("Anish",10));
	m.insert(pair <string,int> ("mrinal",2));
	m.insert(pair <string,int> ("Vaibhav",3));
	m.insert(pair <string,int> ("Rasila",4));
	//can also insert using
//	m.insert(make_pair(10,"Lucky"));
	string name;
	int marks;
	cin>>name;
	cin>>marks;
	map<string,int>::iterator i=m.find(name);
               int new_marks  = (i->second + marks);
               i->second = new_marks;	
	
	map<string,int>::iterator it;
	
	
	//can also do random access using the key value as subscript-O(1)
	cout<<m["Anish"]<<endl; //prints mrinal
	
	
	//traversing the map using iterator
	for(it = m.begin(); it != m.end();it++)
	{
		cout<<it->first;
		cout<<" | ";
		cout<<it->second;
		
		cout<<endl;
	}
	
	
	
	cout<<"Erasing--"<<endl;
	
	
	//will erase elements from begin of map till 2nd element , not 3
	// remove all elements up to element with key = 3 in found
//	 m.erase(m.begin(), m.find(3) );
//	 
//	 for(i = m.begin(); i != m.end();i++)
//	{
//		cout<<i->first;
//		cout<<" | ";
//		cout<<i->second;
//		
//		cout<<endl;
//	}
	 
	
	//find() method returns an iterator to key passed as argument
	
//	map<int,string>::iterator i1;
//	int n;
//	cin>>n;
//	i1 = m.find(n);
//	if(i1->first) 
//		cout<<i1->second; //prints "mrinal"
//		
//	else 
//		cout<<"Not found"<<endl;
//	
//	
//	
//	return 0;
	
}
