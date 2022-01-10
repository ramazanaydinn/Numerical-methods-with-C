#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <sstream>
using namespace std;
#include <stdlib.h> 

using namespace std;
int main(int argc,char*argv[]){
	int i,j,m,n;

	double k,t;
	double diff,eigenvalue1;
	n=0;
	
	double tolerance;

	
	
 string line;
  
  ifstream fileA (argv[1]);      //line 24-29 to count A matrix' line by reading A file 
  if (fileA.is_open()){
  while ( getline (fileA,line) ){n++;} 
  fileA.close();}
  double H[n][n],I[n][n],G[n][n];
double x[n],y[n],z[n];


 
double**A=new double*[n];       //line 33-38 to create A in memory thanks to dynamic memeory allocation
 
  for(i=0;i<n;i++){
  A[i]=new double[n];
  
  }
 
  ifstream fileAmatrix (argv[1]);   //line 40-45 to fill A matrix by reading A file
 if (fileAmatrix.is_open()){
 for (i=0;i<n;i++ ){
 for(j=0;j<n;j++){
 fileAmatrix>>A[i][j];}}
 fileAmatrix.close();}

 else cout << "Unable to open file A"<<endl; 
 
 ifstream filetolerance (argv[2]);  //line 49-53 to fill b matrix by reading tolerance
 if (filetolerance.is_open()){
 filetolerance>>tolerance;
 filetolerance.close();}
 else cout << "Unable to open file tolerance"<<endl; 
 



 for(i=0;i<n;i++){x[i]=1;
 }

 k=0;

for (int q=0;q<2;){ 
for(int m=0;m<n;m++){y[m]=0;}
t=0;
		for(i=0;i<n;i++){
		for(j=0;j<n;j++){ 
		y[i]+=A[i][j]*x[j];

		}
			
	if(abs(y[i])>abs(t)){t=y[i];
}}

		for(i=0;i<n;i++){
		
		x[i]=y[i]/t;	
	}
	
      diff=abs(t-k);

	
    	k=t;
    	
    
		
if(abs(diff)<=tolerance){break;
}		

}
eigenvalue1=k;

 
 for(i=0;i<n;i++){
 	
 	z[i]=x[i];
	 
 }

 
 t=0;
 for(i=0;i<n;i++){
t+=x[i]*x[i];
 }

  y[0]=1;
 for(i=1;i<n;i++){y[i]=0;
 }

 if(A[0][0]>0){
 
 for(i=0;i<n;i++){
 	x[i]=x[i]+sqrt(t)*y[i];
 }
}
else{
	 for(i=0;i<n;i++){
 	x[i]=x[i]-sqrt(t)*y[i];
 }
}
 
 
for(i=0;i<n;i++){
 
 		y[i]=x[i];
	
 }

 for(i=0;i<n;i++){
 	for(j=0;j<n;j++){
 		H[i][j]=y[i]*y[j];
 		
	 }	
	 

 }
  
	t=0;
for(i=0;i<n;i++){
 

 		t+=x[i]*x[i];
 
 }
 
	for(i=0;i<n;i++){
 	for(j=0;j<n;j++){
 
 	if(i!=j){I[i][j]=0;}
	 else{I[i][j]=1;}
	 }
 }
  
 	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			H[i][j]=I[i][j]-2*H[i][j]/t;
		}
	}


	   for(m=0;m<n;m++){
		  
		for(i=0;i<n;i++){
				k=0;
				
		for(j=0;j<n;j++){
			
	
			k+=H[m][j]*A[j][i]; 
	
		
			I[m][i]=k;	
		
		}
	
			
	} 
}
	


     for(int m=0;m<n;m++){
		  
		for(i=0;i<n;i++){
				k=0;
				
		for(j=0;j<n;j++){
			
	
			k+=I[m][j]*H[j][i];
	
		
			G[m][i]=k;	
		
		}
	
			
	} 
}

	


	
	if(n==2){
		ofstream fileresult("result.txt");
 if (fileresult.is_open()){
 	 	 fileresult<<eigenvalue1<<endl;
  for(i = 0; i < n; i++){

 fileresult<<z[i]<<endl;
 
 
 }

 fileresult<<G[1][1]<<endl;
 
 fileresult.close();}
	}
	
	else{
	
	 x[0]=0;
	 x[1]=1;
 for(i=2;i<n;i++){x[i]=0;
 }

	k=0;

	while (1){ 
for(int m=0;m<n-1;m++){y[m+1]=0;}
t=0;
		for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){ 
		y[i+1]+=G[i+1][j+1]*x[j+1];

		}
		
	if(fabs(y[i])>fabs(t)){t=y[i];
}}

		for(i=0;i<n-1;i++){
		
		x[i+1]=y[i+1]/t;	
	}
	
      diff=t-k;

	
    	k=t;
    	
    

		
if(fabs(diff)<=tolerance){break;
}		

}

ofstream fileresult("result.txt");//line 260-275 to write eigenvalue1,eigenvector1,eigenvalue2 on result file
 if (fileresult.is_open()){
 	fileresult<<"eigenvalue1:";
 	 	 fileresult<<eigenvalue1<<endl;
 	 	
 for(i = 0; i < n; i++){

 fileresult<<z[i]<<endl;
 
 
 }
 fileresult<<"eigenvalue2:";
  fileresult<<k<<endl;
 
 fileresult.close();}
}
	return 0;
}
