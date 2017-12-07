//friend class
#include<iostream>
#include<string>

using namespace std;

void display(); //function prototype

class Human {
	private: //private attr of the class
		int age;
		int salary;
		string name;
	public:
		Human(int iage,int isal,string iname) {
			age=iage;
			salary=isal;
			name=iname;
		}
	void tell(){
		cout<<age<<salary<<endl<<name<<endl;
	}
		
	friend class man; //friend class of class Human which can access the private and protected attr and methods of the class Human	
	

};

class man{

	public:
		//now the member function of friend class will take the argument as the object of class Human
		void display(Human *anish) {
	
			cout<<"name: " <<anish->name<<","<<"salary : "<<anish->salary<<", "<<"age:"<<anish->age<<endl;
		}


};

//friend function defination



int main() {
	
	Human *obj=new Human(20,2004444,"Anish Singh Walia");
	man *anish=new man;//object of class man
	anish->display(obj);
	
return 0;
	
}
