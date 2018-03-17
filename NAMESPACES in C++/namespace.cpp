#include<iostream>

using namespace std;

/*program to explain the concept of namespaces
namespaces consists of a set of identifiers which are local to that particular name space.Also namespaces are like the lastname of a 2 persons having different names.
Like we can differentiate 2persons with smae first names using their last names(Which are different) in the same way to avoid name collisions in c++, we use
namespaces. 

To access members of a namespace outside it, we have to use scope resolution operator.

'using' keyword actually loads the particular namespace into the golbal namespace or global scope.

Each program has a un-named or anynymous namespace.
*/

#include "one.cpp"

#include "two.cpp"


int main()
{
	one::x=20;
	one::display();
	
	two::x=30;
	two::display();
}
