#include<iostream>

using namespace std;//std namespace is assigned as global namesapace

//SOLVING DIAMOND PROBLEM  using VIRTUAL INHERITENCE 


class Animal{
	public:
		Animal() {
			cout<<"Animal constructor called"<<endl;
		}
		void getAnimal() {
			cout<<"hello I am animal"<<endl;
		}
}; 

class Tiger :   virtual public Animal{
	public:
		Tiger() {
			cout<<"Tiger constructor called"<<endl;
		}
};


class Lion : virtual public Animal{
	
	public:
		
		Lion() {
			cout<<"Lion constructor called"<<endl;
		}
};


class Liger:  public Tiger, private Lion {
	public:
		
		Liger() {
			cout<<"Liger constructor called"<<endl;
			
		}
};


int main() {
	Liger l ; 
//	l.getAnimal(); //error if virtual inheritence is not used-'getAnimal' is ambiguous, as compiler will not know from which instance of Tiger or Lion will be used to call
	//getAnimal() of Animal class
	
	// when virtual inheritence is not used- 
	//1)ANIMAL constructor called using Tiger's object2) TIGER Constructor called 3)Again Animal constructor called using LION's object 
	//4)Lion constructor called 5)Liger constructor called at last
//this happens because Liger class inherits from both Tiger and Lion class, so compiler will use the instances(objects) of both Tiger and Lion to call constructor of Animal
	
	
	//------------when Virtual inheritence is used----------------------- 
	//1) Animal constructor called
	//2)Tiger constructor called
	//3) Lion constructor called
	//4) Liger constructor called
	
//This happens because compiler creates only one instance(object) of Tiger or Lion class and uses it to call constructor of Animal, 2 instances of Tiger and Lion are not created
//when using virtual inheritence

	return 0;
}
