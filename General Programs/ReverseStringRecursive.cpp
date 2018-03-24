#include<iostream>
#include<string>

//recursive program to find reverse of a string

using namespace std;

string ReverseRec(string str,int i,int j)
{
	
  	
	
	//base condition-terminating condition -recursion stops here
	if(i>j) return str; //oor when i==j
	
	else
	{
		//otherwise simply swap the characters until above base condition is rached i.e i>j
		swap(str[i],str[j]);
		
		return ReverseRec(str,i+1,j-1);
	}
	
		
		
		
}


int main()
{
	string name ;
	name= "anish singh walia";
	cout<<ReverseRec(name,0,name.size()-1);
	return 0;
}
