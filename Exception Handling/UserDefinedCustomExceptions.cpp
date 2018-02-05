#include<iostream>
#include<exception>


using namespace std;
//creating custom user defined exception classes

//Overspeed class which inherits from exception class
class OverSpeed : public exception
{
	public:
		int speed ;
		OverSpeed() 
		{
			speed=0;
		}
		//inherits what() of exception class
		const char* what() 
		{
			return "Please slow down, Overspeedying is dangerous.";
			
		}
		
		void getSpeed() 
		{
			cout<<"Now the speed is: "<<speed<<endl;
		}
		
		void setSpeed(int speed) {
			
			this->speed = speed;
		} 
		
};//created a custom exception class



//class in which exception is throwed
class Car {
	
	public:
		int speed ;
		//constructor
		Car() 
		{
			speed=0;
		}
		
		void getSpeed()
		{
			cout<<"The speed is:"<<speed<<endl;
		}
		
		void acclerate()
		{
			//infinite loop which increments speed by 10 and if speed exceeds 250, exception is throwed
			for( ; ; )
			{
				
				speed += 10;
				getSpeed();
				
				if(speed >= 150) {
					
					OverSpeed obj;
					
				
					
					obj.setSpeed(speed);
					 
					throw obj; //will throw object of exception class OverSpeed
					
				}
			}
		}
	
	
};




int main()
{
	Car c;
	
	try {
		
		c.acclerate();
		
	}
	catch(OverSpeed obj) 
	{
		
		obj.getSpeed();
		cout<<obj.what();
		
	}
	return 0;
}
