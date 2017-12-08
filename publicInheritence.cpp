#include<iostream>
#include<math.h>

using namespace std;

class Shape {
	
	protected:
		int side;
		
	public:
		
		int getArea();
		int volume();
};


//PUBLIC inheritence-public members of parent class act as public members of child class 2) Protected member of parent class, as protected member of child class

class square : public Shape {
	public:
		//constructor
		square(int a) {
			side=a;
		}
			
		
		//inherited from Shape(base) class
		void getArea() {
			
		cout<<"Area is: "<<side*side<<endl;
		}
		void volume() {
			cout<<"Volume is: "<<pow(side,4) << endl;
		}
		void perm() {
			cout<<"Perimeter is: "<<(side*4)<<endl;
		}
};


int main () {
	
	square s(4); //object of subclass
	s.getArea();
	s.perm();
	s.volume();
}
