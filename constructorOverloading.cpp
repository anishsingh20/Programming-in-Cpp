//constructors example
#include<iostream>

using namespace std;


class human 
{
	public:
		human() {
			age=10;
			name="Anish";
			cout<<"Default Constructor is called"<<endl;
		}
		
		human(int iage,string iname) {
			age=iage;
			name=iname;
			cout<<"overloaded constructor called"<<endl;
		}
		
		void introduce()
		 {
		 	cout<<"Hello I am" <<" " << name << " "<<"and my age is" << age<<endl;
		 }
		 
		/* /int getage() 
		{
		 cin>>age;
		 return age;
			
		}
		string getName() 
		{
			
			cin>>name;
			return name;
			
		}*/
		
	private:
		int age;
		string name;
	
	
};


int main() {
	human obj;//constructor is called as soon as an object is created
	 //default constructor called
	obj.introduce();
	 
	human obj2(20,"mrinal");//arguments passed to the object
	//constructor overloaded

	obj2.introduce();
}
