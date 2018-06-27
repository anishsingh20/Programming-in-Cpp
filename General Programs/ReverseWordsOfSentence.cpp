#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>


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


//function to count words
int countWords(string s)
{
	int count = 0 ;
        int word = 0;
	
	int i = 0 ;
	int size = s.size()-1;
	
	while(i <= size)
	{
		if(s[i] == ' ') word = 0;
		
		else if(++word==1)
			count++;
		
		i++;
	}
	
	return count;
}

int main()
{
	
	string s = "  hey   how are you";
	
	ReverseWords(s);
	
	cout<<endl<<countWords(s);	
	return 0;
}
