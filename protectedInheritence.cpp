#include<iostream>
#include<math.h>

using namespace std;

class Shape {
	
	//all public members will now be protected members of subclass
	public:
		int side;
		int getArea();
		int volume();
};


//Protected inheritence-public and protected members of parent class act as protected members of child class-i.e accessible only inside the subclass 
class square : private Shape {
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
	
	square *s = new square(3); //object of subclass
	
	s->getArea();
	s->volume();
	s->perm();
}
