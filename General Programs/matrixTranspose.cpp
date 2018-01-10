#include<iostream>

using namespace std;//assignning std to global namespace


int main() {
	
	int mat[3][3],n,m;
	
	cout<<"Enter the order of matrix"<<endl;
	cin>>n;
	cin>>m;
	
	cout<<"Enter the elements of matrix"<<endl;
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>mat[i][j];
		}
	}
	
	
	cout<<"matrix is= "<<endl;
	for(int i=0;i<n;i++) {
		
		
		for(int j=0;j<m;j++) {
			
			
			cout<<mat[i][j]<<"\t";
		}
			cout<<"\n";
		
	}
	

	
	//transpose of matrix
	
	cout<<"Transpose of matrix is= "<<endl;
	
	//rows and columns are exchanged
	
	
	for(int i=0;i<n;i++) {
		
		
		for(int j=0;j<m;j++) {
			
			//simply changing the subscripts of indices -rows and columns
			cout<<mat[j][i]<<"\t";
		}
		
			cout<<"\n";
	}
	
	
	
	
	return 0;
	
	
}
