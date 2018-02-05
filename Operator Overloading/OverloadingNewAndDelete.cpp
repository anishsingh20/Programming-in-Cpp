#include<iostream>
#include<cstdlib>
#include<stdexcept>

using namespace std;

/*overloading new and delete operator in cpp
1) new operator is used to dynamically allocate a memory block to a variable in memory
2) delete operator is used to deallocate the memory block assigned to a variable and free it
*/
using namespace std;

class student {
	public:
		int age;
		string name;
		
		student() {
			
			age= 0 ;
			name = "noname";
		}
		student(string name,int age) 
		{
			this->age = age;
			this->name = name;
		}
		
		void getDet() 
		{
			cout<<"Name is: "<<name<<" and "<<"age is: "<<age<<endl;
		}
		
		//Overloading new operator
		//will return a void pointer becasue it can point to any specific data type-
		void* operator new(size_t  size) 
		{
			void *pointer;
			cout<<"Overloaded new operator and size is "<<size<<" Bytes."<<endl;
			//allocating memory
			pointer = malloc(size);//malloc() also returns a void pointer
			
			//exception -bad allocation
			if(!pointer)
			{
				bad_alloc b;
				throw b;
			}
			
			return pointer;			
		}
		
		
		//Overloading the delete operator
		void operator delete(void *pt)
		{
			
			cout<<"delete operator overloaded"<<endl;
			
			free(pt);
		}
	
};


int main() {
	
	
	student *Anish ,*mrinal;
	
	try 
	{
		Anish = new student("Anish Singh",20); //object Anish allocated 40 bytes of memory
		Anish->getDet();
		
		delete(Anish);
		
		mrinal = new student;
	}
	catch(bad_alloc b) 
	{
		cout<<b.what();
	}
	
	
	
}

