#include<iostream>

using namespace std;


//program to demonstrate how to pass default template arguments for a generic class


template<class t1=int,class t2=string> class Person{
	
	t1 age;
	t2 name;
	
	public:
		Person(t1 age,t2 name)
		{
			this->age = age;
			this->name = name;
		}


	void introduce()
	{
		cout<<"The age is: "<<age<<" and name is: "<<name<<endl;
	}


};

 
int main()
{
	
	Person <> obj1(20,"anish");
	
	Person <float> obj2(20.0099,"anish singh");
	
	Person<string,int> obj3("anish walia",25);
	
		
	obj1.introduce();
	
	obj2.introduce();
	
	obj3.introduce();
	
	return 0;
}
