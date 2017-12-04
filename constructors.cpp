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
		
	private:
		int age;
		string name;
	
	
};


int main() {
	human *obj= new human;//constructor is called as soon as an object is created
	obj->introduce();
}
