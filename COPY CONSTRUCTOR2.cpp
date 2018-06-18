#include<iostream>


using namespace std;


class Person{

	public:
		int age;
		int *s;
		Person(int age,int p)
		{
			this->age = age;
			(this->s)  = new int(p);
		}
		
		//copy constructor
		Person(const Person &obj)
		{
			age = obj.age;
			s = new int(*obj.s);
			
		}
		
		void getdet()
		{
			cout<<"Age is"<<" : "<<this->age<<endl;
			cout<<"Name is "<<" : "<<*s;
		}
};


int main()
{
	Person p(20,2003);
	
	p.getdet();
	
	Person p1 = p; //copy constructor called, for object p1, s pointer member allocated memory at a different block.
	//now both objects maintain different copies of pointer s
	*p.s = 1000;
	
	cout<<endl;
	
	cout<<"Address of pointer variable of both objects: "<<p.s<< " "<<p1.s<<endl; //object p1 also points to the same location of pointer member p
	
	p1.getdet();
	cout<<endl;
	p.getdet(); //changes only reflected in object p's copy of pointer var s;
}
