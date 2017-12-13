#include <iostream>
using namespace std;
int main()
{
     int const x=10;
     x=20; //compile time error-const variable values cannot be changed
     int y= x+10;
     
     cout<<"x="<<x<<" | "<<"y="<<y;
     return 0;
}
