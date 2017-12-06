//static variable and static member methods
#include<iostream>


using namespace std;

class Human {
	public:
	static int scount;//cannot be defined inside a class
	int count;
	//constructor
	Human() {
		scount++;
		count++;
		cout<<"Number of humans"<<" "<<scount<<endl;
	}
	
	static void totalHuman() {
		cout<<"There are "<<scount<< " "<< "people"<<endl;
		
	}
	

};
//static variable needs to be defined outside a class defination

int Human :: scount=0;


int main () {
	//only 1 copy of static variable created and shared amongst all the objects.
	Human anish;
	Human mrinal;
	Human lucky;
	Human vaibhav;
	//4 objects- the constructor is called 4 times and scount(static variable) becomes 4
	
	Human :: totalHuman(); 
	//can access static variables and methods without using an object of class.
	cout<<Human :: scount; 
	
	
return 0;	
}

