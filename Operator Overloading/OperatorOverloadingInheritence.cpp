#include<iostream>


//program to overload = operator
//Special thing about = operator is that the derived class cannot overload = operator function
using namespace std;

class Marks {
	
		public:
			int mark;
			Marks() {
				cout<<"parent class constructor called"<<endl;
			}
			
			Marks(int m) {
				mark = m;
			}
			
			void getmarks() {
				cout<<"The marks are: "<<mark<<endl;
			}
			
			Marks operator ++ () {
				
				mark += 1;
				
				cout<<"Overloading ++ operator in Prefix form"<<endl;
				
				return *this;
			}
		};
		
		
class Math : public Marks {
	public:
		Math(int m) 
		{
			mark =m;
			
		}
		//overloading -- operator function in derived class in POSTFIX FORM
		Math operator -- (int) 
		{
		  Math duplicate(*this);
			mark -= 1;
			cout<<"Overloading -- operator in POSTFIX form"<<endl;
			return duplicate;
		}	
};



int main() {
//	Marks m1(90);
//	
//	m1.getmarks(); //prints 90
//	
//	//overloading = operator
//	Marks m2 = m1 =85;
//	
//	m2.getmarks();

	Math m1(89);
	
	m1.getmarks();
	
	(++m1).getmarks(); //marks are incremented first;
	
	
	(m1--).getmarks();//marks still 90, first printed 
	
	//now marks are decremented after usage
	
	m1.getmarks();//now marks have decremented by 1
	

	
	return 0;
}
