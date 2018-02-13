#include<iostream>

using namespace std;

/*2 ways of setting flags -
all the flags are members of ios class
1) using setf() function and adding flag as arguent to it. 
2) directly placing flag inside cin or cout streams - cin >> flag  or cout << flag 
*/


int main()
{
	cout.setf(ios::showpos | ios::showpoint);
	
	cout<<hex<<10<<endl;
	//unsetting flag using unsetf
	cout.unsetf(ios::showpoint);
	
	cout<< oct << -100<<endl;
	
	cout<<hex<<100.22<<endl;
	return 0;
}
