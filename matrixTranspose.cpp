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
	
	//now i=0 to  m(columns) , for non-square matrices
	for(int i=0;i<m;i++) {
		
		//j=0 to n(rows) 
		for(int j=0;j<n;j++) {
			
			
			cout<<mat[j][i]<<"\t";
		}
		
			cout<<"\n";
	}
	
	
	
	
	return 0;
	
	
}
