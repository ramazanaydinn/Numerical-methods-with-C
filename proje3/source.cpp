#include<iostream>
#include<fstream>               
#include<string>                
#include<cmath>                 
#include<float.h> 
#include <stdlib.h>

using namespace std;
int main (int argc,char*argv[]) {//to use comment line

int i,j,n,count;
double a,b,t,k,m,r,c,p,first,second,tolerance;//first is the first initial guess, second is the second is the second initial guess,and tolerance is the tolerance value

n=argc-5;//to find n variable 

double y[n+1];//y vector stores the exponent of x

double*f;//dynamic memory allocated to store
f=new double[n+1];
// f vector stores the coefficients of function
for(i=0;i<n+1;i++){f[i]=atof(argv[i+1]);}//fiiling the f vector with coefficients of function
 
first=atof(argv[n+2]);//to find first variable for first initial guess
second=atof(argv[n+3]);//to find second variable for second initial guess
tolerance=atof(argv[n+4]);//to find tolerance variable for tolerance value

a=first;//to assign first variable with a variable
b=second;//to assign second variable with b variable
//line 30-48 to implement hybrid method, the first two iterations should be bisection method
count=0;
for(j=0;j<2;j++){
 for(i=0;i<n+1;i++){y[i]=pow((a),(n-i));}//y vector stores the exponent of a

t=0;
for(i=0;i<n+1;i++){t+=f[i]*y[i];}//the equation of f(a)=t

	
m=a+(b-a)/2;
for(i=0;i<n+1;i++){y[i]=pow((m),(n-i));}//y vector stores the exponent of m

r=0;
for(i=0;i<n+1;i++){r+=f[i]*y[i];}//the equation of f(m)=r

if(t*r>0){a=m;}//to detect whether sign of f(a) and  sign of f(m) are same or not
else{b=m;}

count++;//if the loop is completed,to add a one to count
}
//line 50-73 secant method for the rest of the iterations of hybrid method
while(fabs(b-a)>tolerance){//to detect difference of sequential two x values are smaller than tolerance value or not
for(i=0;i<n+1;i++){y[i]=pow((a),(n-i));}//y vector stores the exponent of a

t=0;
for(i=0;i<n+1;i++){t+=f[i]*y[i];}//the equation of f(a)=t

for(i=0;i<n+1;i++){y[i]=pow((b),(n-i));}//y vector stores the exponent of b

k=0;
for(i=0;i<n+1;i++){k+=f[i]*y[i];}//the equation of f(b)=k

c=b-k*(b-a)/(k-t);//to implement the secant method( c=x(k+1) b=x(k) k=f(x(k)) a=x(k-1) t=f(x(k-1)) )

a=b;//to assign x(k) with x(k-1) to repeat secant method
b=c;//to assign x(k+1) with x(k) to repeat secant method

count++;//if the loop is completed,to add a one to count
}

cout<<"For the Hybrid Method: ";//to print out the x value for hybrid method
cout<<count;
cout<<" number of iterations and ";//to print out the number of iterations for hybrid method
cout<<b;
cout<<" is the root"<<endl;
//line 75-105 to implement secant method
k=0;
t=0;
count=0;
a=first;//to assign first variable with a variable
b=second;//to assign second variable with b variable

while(fabs(b-a)>tolerance){//to detect difference of sequential two x values are smaller than tolerance value or not
for(i=0;i<n+1;i++){y[i]=pow((a),(n-i));}//y vector stores the exponent of a

t=0;
for(i=0;i<n+1;i++){t+=f[i]*y[i];}//the equation of f(a)=t

for(i=0;i<n+1;i++){y[i]=pow((b),(n-i));}//y vector stores the exponent of b

k=0;
for(i=0;i<n+1;i++){k+=f[i]*y[i];}//the equation of f(b)=k

c=b-k*(b-a)/(k-t);//to implement the secant method( c=x(k+1) b=x(k) k=f(x(k)) a=x(k-1) t=f(x(k-1)) )

a=b;//to assign x(k) with x(k-1) to repeat secant method
b=c;//to assign x(k+1) with x(k) to repeat secant method

count++;//if the loop is completed,to add a one to count

}

cout<<"For the Secant Method: ";//to print out the x value for secant method
cout<<count;
cout<<" number of iterations and ";//to print out the number of iterations for secant method
cout<<b;
cout<<" is the root"<<endl;
//line 107-138 to implement secant method
k=0;
t=0;
r=0;
count=0;
a=first;//to assign first variable with a variable
b=second;//to assign second variable with b variable

while(abs(b-a)>tolerance){//to detect difference of sequential two x values are smaller than tolerance value or not
for(i=0;i<n+1;i++){y[i]=pow((a),(n-i));}//y vector stores the exponent of a

t=0;
for(i=0;i<n+1;i++){t+=f[i]*y[i];}//the equation of f(a)=t

m=a+(b-a)/2;

for(i=0;i<n+1;i++){y[i]=pow((m),(n-i));}//y vector stores the exponent of m

r=0;
for(i=0;i<n+1;i++){r+=f[i]*y[i];}//the equation of f(m)=r
		
if(t*r>0){a=m;}//to detect whether sign of f(a) and  sign of f(m) are same or not
else{b=m;}

count++;//if the loop is completed,to add a one to count

}

cout<<"For the Bisection Method: ";//to print out the x value for bisection method
cout<<count;
cout<<" number of iterations and ";
cout<<m;//to print out the number of iterations for bisection method
cout<<" is the root"<<endl;

delete[] f;//to prevent unnecessary memeory usage,deleting the f vector

return 0;
}
