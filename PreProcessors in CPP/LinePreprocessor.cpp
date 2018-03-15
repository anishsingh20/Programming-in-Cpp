#include<iostream>

//PROGRAM TO SHOW DIFFERENT PRE-DEFINED  C++ PRE-PROCESSORS AND  LINE DIRECTIVE

using namespace std;

int main()
{
	
	cout<<"The line number is:"<<__LINE__<<endl;
	cout<<"THe file is"<<__FILE__<<endl;
	
	cout<<"The time of compilation of this program is:"<<__TIME__<<endl;
	
	cout<<"The date of source code conversion to object code is:"<<__DATE__<<endl;
	
	cout<<"Our compiler can accept standard c and c++ code:"<<__STDC__<<endl;
	
	cout<<"Whether our compiler is confirming to the c++ standard:"<<__cplusplus<<endl;
	
	
	//usage if line directive to change line number and file name
	
	#line 1200 "anish.txt"
	
	cout<<"Now the line is:"<<__LINE__+__LINE__<<endl;
	cout<<"Now the file is:"<<__FILE__<<endl;
}
