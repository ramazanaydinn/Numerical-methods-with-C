#include<iostream>
#include<fstream>               // to use fstream library
#include<string>                //to use string library
#include<cmath>                 //using cmath library to use abs function
#include<float.h> 
#define machpres pow((10),(-7))
using namespace std;
int main (int argc,char*argv[]) {//to use comment line
  int i,j,k,n;
  n=0;                                         
  double x[n],y[n];
  
  string line;
  
  ifstream fileA (argv[1]);      //line 15-18 to count A matrix' line by reading A file 
  if (fileA.is_open()){
  while ( getline (fileA,line) ){n++;} 
  fileA.close();}

  else cout << "Unable to open file A"<<endl; 
  
  double**A=new double*[n];       //line 22-32 to create A and B matrix as well as b and c vector in memory thanks to dynamic memeory allocation
  double**B=new double*[n];
  
  for(i=0;i<n;i++){
  A[i]=new double[n];
  B[i]=new double[n];}
 
  double*b;
  double*c; 
  b=new double[n];
  c=new double[n];
 
 ifstream fileAmatrix (argv[1]);   //line 34-39 to fill A matrix by reading A file
 if (fileAmatrix.is_open()){
 for (i=0;i<n;i++ ){
 for(j=0;j<n;j++){
 fileAmatrix>>A[i][j];}}
 fileAmatrix.close();}

 else cout << "Unable to open file A"<<endl; 
 
 ifstream filebmatrix (argv[2]);  //line 43-47 to fill b matrix by reading b
 if (filebmatrix.is_open()){
 for (i=0;i<n;i++ ){filebmatrix>>b[i];}
 filebmatrix.close();}
 else cout << "Unable to open file b"<<endl; 
    
 if(n==2){                        //line 49-89to find condition number,if A is 2x2 matrix
 double detA;
 double m;
   	
 detA=A[0][0]*A[1][1]-A[0][1]*A[1][0];       //to find determinant of A
 if(machpres>=detA && detA>=(-1)*machpres) { //to control A is singular or not thanks to machine precision
 cout<<"A is singular matrix"<<endl;
 cout<<"condition number approaches infinity"<<endl;
 return 0;
 }
 else{
 m=1/detA;
 B[0][0]=m*A[1][1];                          //line 61-64 to find inverse of A.Inverse of A equals B matrix.
 B[0][1]=-m*A[0][1];
 B[1][0]=-m*A[1][0];
 B[1][1]=m*A[0][0];
   
 double Ainf,Binf,Aone,Bone;
 if(abs(A[0][1])+abs(A[1][1])>abs(A[0][0])+abs(A[1][0])){//line 67-76 to find condition number while using 1-norm
 Aone=abs(A[0][1])+abs(A[1][1]);}
 else Aone=abs(A[0][0])+abs(A[1][0]);
	   
 if(abs(B[0][1])+abs(B[1][1])>abs(B[0][0])+abs(B[1][0])){
 Bone=abs(B[0][1])+abs(B[1][1]);}
 else Bone=abs(B[0][0])+abs(B[1][0]);
	  
 double condofAone=Aone*Bone;
 cout<<"condition number is:"<<condofAone<<" by using 1-norm"<<endl;
	   
 if(abs(A[1][0])+abs(A[1][1])>abs(A[0][0])+abs(A[0][1])){//line 78-88 to find condition number while using infinity norm
 Ainf=abs(A[1][0])+abs(A[1][1]);}
	    
 else Ainf=abs(A[0][0])+abs(A[0][1]);
	   
 if(abs(B[1][0])+abs(B[1][1])>abs(B[0][0])+abs(B[0][1])){
 Binf=abs(B[1][0])+abs(B[1][1]);} 
       
 else Binf=abs(B[0][0])+abs(B[0][1]);
       
 double condofAinf=Ainf*Binf;
 cout<<"condition number is:"<<condofAinf<<" by using infinity norm"<<endl;}}
 //line 90-140 B matrix after applying gauss elimination to A matrix and c vector is b vector after applying gauss elimination to b vector 
 for(j=0;j<n;j++){if(A[0][0]==0){A[0][j]=(A[1][j]+A[0][j]);
 b[0]+=b[1];}
 B[0][j]=A[0][j];}  //to fill first row of B matrix and c vector
 c[0]=b[0];
	  
 for(k=0;k<n-1;k++){//line 96-106 by applying gauss elimination to A matrix and b vector to find B matrix and c vector
 for(i=k+1;i<n;i++){
 for(j=0;j<n ;j++){if(A[k][k]==0 && k!=n-1){A[k][j]+=A[k+1][j];
 b[k]+=b[k+1];}
 B[i][j]  = (-A[i][k]/A[k][k]*1.0)*A[k][j]+A[i][j];
 c[i]=(-A[i][k]/A[k][k]*1.0)*b[k]+b[i];}}
  
 for (i=0; i<n; i++){
 for(j=0;j<n;j++){
 A[i][j]=B[i][j];}}
 for(i=0;i<n;i++){b[i]=c[i];}}

 double detA;

 for(i=0;i<n;i++){//line 110-115 to control A is singular matrix or not by using machine precision
 if(machpres>=B[i][i] && B[i][i]>=(-1)*machpres){detA=0;}}
 
 if(0==detA){
 cout<<"A is singular matrix"<<endl;
 return 0;}

 for(i=n-1;i>=0;i--){//line 117-121 to find x vector by using B matrix and c vector
     	
 for(j=1;j<=n-1;j++){
 y[i]-=B[i][i+j]*x[i+j];}
 x[i]=(c[i]+y[i])/B[i][i];}
 
 for(i=0;i<n;i++){cout<<x[i]<<endl;}//to print out x vector
    
 ofstream filexmatrix("x.txt");//line 125-129 to write x matrix on x file
 if (filexmatrix.is_open()){
 for(i = 0; i < n; i++){
 filexmatrix<<x[i]<<endl;}
 filexmatrix.close();}
  
 else { cout << "Unable to open file x"<<endl;}

 for(i=0;i<n;i++){//line 133-140 to delete all matrix and vector in memory
 delete[] A[i];
 delete[] B[i];}
 delete[] A;
 delete[] B;
   
 delete[] b;
 delete[] c;
 return 0;
}

