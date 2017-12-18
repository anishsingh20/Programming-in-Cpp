#include<iostream>

using namespace std;

//overloading [] array subsscripting operators- the condition is for some special operators such as ->,(),[] ..the operator function
//should not be a friend function nor a static member function of class


class Marks {
	int sub_mark[3];
	public:
		Marks(int sub1,int sub2,int sub3) {
			
			sub_mark[0]=sub1;
			sub_mark[1]=sub2;
			sub_mark[2]=sub3;
		}
		
		int operator [] (int pos) {
			return sub_mark[pos];
		}
};

int main () {
	
	Marks m(44,56,90);
	cout<<m[0]<<endl;
	cout<<m[1]<<endl;
	cout<<m[2];
	
	return 0;

}
