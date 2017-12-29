#include<iostream>


using namespace std;


string reverse(string name) {
	

	
	int i=0;
	int j = name.size()-1;
	
	

		while(i<=j) {
			
			swap(name[i],name[j]); //swapping
			i++;
			j--;
			
			
			
		}
		
		
		return name;
		
		
	
		
	
	
	
		
}


int main() {
	
	string name;
	getline(cin,name); 
	cout<<"Reversed string is : "<<endl;
	cout<<reverse(name);
	return 0;
}
