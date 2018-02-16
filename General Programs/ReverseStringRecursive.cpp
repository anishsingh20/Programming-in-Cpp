#include<iostream>
#include<string>

//recursive program to find reverse of a string

using namespace std;

string ReverseRec(string str)
{
	
 	static int i=0,j=str.size()-1;
	
	//base condition-terminating condition -recursion stops here
	if(i>j) return str; //or when i==j
			
	
		swap(str[i],str[j]);
		i++;
		j--;
		return ReverseRec(str);
		
		
}


int main()
{
	
	cout<<ReverseRec("anish singh walia");
	return 0;
}
