//constructors example
#include<iostream>

using namespace std;


class human 
{
	public:
		human() {
			int age=10;
			string name="Anish";
			cout<<"Constructor is called"<<endl;
		}
		
		void introduce()
		 {
		 	cout<<"Hello I am" <<" " << getName() << " "<<"and my age is" << getage()<<endl;
		 }
		 
		int getage() 
		{
		 cin>>age;
		 return age;
			
		}
		string getName() 
		{
			
			cin>>name;
			return name;
			
		}
		
	
		int age;
		string name;
	
	
};

class anish : private human {
	public:
		human::age;
		human::name;
		anish () {
			cout<<"Anish constructor called"<<endl;
		}
		void intro(int sage,string sname) {
			age = sage;
			name = sname;
			 
			cout<<"Hello I am "<< " " << sname << " " <<"age is :"<< sage <<endl;
		}
};


int main() {
//	human *obj= new human;//constructor is called as soon as an object is created
//	obj->introduce();
	anish A;
	A.intro(20,"anish");
}
