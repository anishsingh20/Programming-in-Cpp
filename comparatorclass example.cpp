// C++ program for the Comparator Class
// for implementing linear search
#include <bits/stdc++.h>
using namespace std;

// Generic function to search for object
template <class ForwardIterator, class T>
ForwardIterator search(
	ForwardIterator start,
	ForwardIterator end, T key)
{
	// Iterate until start equals to end
	while (start != end) {

		// If the value with given key is
		// found the return that index
		if (*start == key) {
			return start;
		}
		start++;
	}
	return end;
}

// Student Class
class student {
public:
	// To store Name and Roll Number
	string name;
	int rollnum;

	// Overloaded Constructor
	student(string name, int rollnum)
	{
		this->name = name;
		this->rollnum = rollnum;
	}
};

// Comparator Class to compare 2 objects
class studentcompare {
public:
	// Comparator function
	bool operator()(student a,
					student b)
	{
		// If values are the same then
		// return true
		if (a.name == b.name) {
			return true;
		}
		return false;
	}
};

// Driver Code
int main()
{
	// Object of class student
	student s1("Raj", 23);
	student s2("Prerna", 24);

	// List of students
	list<student> s;
	s.push_back(s1);
	s.push_back(s2);

	// Search student("Prerna", 24)
	student searchstudent("Prerna", 24);

	studentcompare cmp;

	// Print if element is found
	if (cmp(s2, searchstudent)) {
		cout << "Student found!";
	}
	else {
		cout << "Not found";
	}

	return 0;
}
