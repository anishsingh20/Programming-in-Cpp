#include<iostream>
#include<string>
#include<algorithm>


using namespace std;

//sorting a string in cpp


int main()
{
	string s = "anishwal";
	
	//sort function to sort a string
	sort(s.begin(),s.end());
	
	cout<<s;
}
