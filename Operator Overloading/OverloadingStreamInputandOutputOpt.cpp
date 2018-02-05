#include<iostream>

using namespace std;


class Student 
{
	public:
		int age;
		string name;
		Student() 
		{
			age = 0 ;
			name = "noname";
			
		}
		
		//defining friend functions- 2 arguments as they also need a reference to the class object to
		//access the class members outside the class
		
		friend ostream& operator <<(ostream &op, Student &s);
		
		friend istream& operator >>(istream &input,Student &s);
	
};



ostream& operator << (ostream &op, Student &s)
	{
		op<<"The name is: "<<s.name<<" and the age is: "<<s.age<<endl;
			
		return op;
			
        }
		
istream& operator >> (istream &input,Student &s)
	{
		input >> s.name ;
		input >> s.age;
		
			
		return input;
	}
	

int main()
{
	
	Student Anish;
	
	cout<<"Enter the name and age:"<<endl;
	
	cin >> Anish;
	
	cout << Anish;
	
	return 0;
}
