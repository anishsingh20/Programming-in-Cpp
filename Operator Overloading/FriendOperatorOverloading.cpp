#include<iostream>


//defining iperator function as a friend function of class which needs to be passed an reference to the class object to 
//access the class members


//overloading short hand operators

using namespace std;




class Marks {
	int mark;
	public:
		Marks() {
			mark=0;
		}
		
		Marks(int m) {
			mark=m;
		}
		
		void getmark() {
			cout<<"Marks are: "<<mark<<endl;
		}
		
		void operator+=(int bonus) 
		{
			mark+=bonus; // same as mark=mark+bonus
		}
		
		//friend operator function
		friend void operator-=(Marks &m,int dec); 
};

//defining friened function outside the class using a pointer to the class object

void operator-=(Marks &m,int dec) {
	m.mark -= dec ; //same as mark=mark-dec
}




int main () {
	Marks m(80);
	
	m+=20; //marks increased by 
	cout<<"Marks increased :"<<endl;
	m.getmark();
	
	cout<<"-----------------------------------"<<endl;
	
	cout<<"Marks decreased: "<<endl;
	m-=10; //marks decreased by 10
	
	m.getmark();
	
	return 0;
}
