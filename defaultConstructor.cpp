//constructors example
#include<iostream>

using namespace std;


class human 
{
	public:
		
		//default values of the constructor params
		human(int iage=19,string iname="Mrinal") {
			age=iage;
			name=iname;
			cout<<"Object created with default constructor values"<<endl;
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
	obj.introduce();
	 
	
}
