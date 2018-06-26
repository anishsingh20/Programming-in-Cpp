#include<iostream>
#include<stack>
#include<algorithm>


using namespace std;

//program to reverse Words of a sentence


void ReverseWords(string &s)
{
	int start = 0;
        int i = 0;

	//to remove spaces in the starting
       while( s[i] == ' ') s.erase(i, 1);
        
        
        reverse(s.begin(), s.end());
        


        int size = s.size();
        for(i = 0; i < size - 1; i++){
        	
        	//removing empty spaces
            if( s[i] == ' '){
                if( i == start ){
                    s.erase(i--,1);
                    size--;
                }
                else{
                    reverse(s.begin()+start, s.begin()+i);
                    start = i+1;
                }
            }
        }
        
        reverse(s.begin() + start, s.end());
        cout<<s;
}	


int main()
{
	
	string s = " hey  how are you";
	
	ReverseWords(s);	
	return 0;
}
