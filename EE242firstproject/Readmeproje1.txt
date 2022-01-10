                        C++ Program for Solving Ax=b                                              2016401351 Ramazan Aydın   
   We have three arguments.
   Argv[0] reads name of the file(source.exe),argv[1] reads first input(A file),and argv[2] reads second input(b file).
   First of all,we create fileA and fileb as txt file.
   We read A file and count line of A.
   Secondly,by using dynamic memory allocation,We create A and b matrix in memory.
   Thirdly,we fill A file and b file by using method of filing.
   If dimension of A 2*2,we calculate the condition number in addition to calculating x matrix.
   Condition number at 1 norm and infinty norm are equal for 2*2 matrix.
   Fourthly,we find B matrix and c vector by applying gauss elimination.
   Fifthly we find x vector thanks to B matrix and c vector.Finally we delete all matrix and all vector.
   How to run the program?
   create 'A.txt' which includes a nxn matrix.
   create 'b.txt' which includes a n vector.
   open source.cpp
   click execute and compile&run 
   We use comment line to our programme by writing application name after the find where programme is.
   Example: .\source.exe A1.txt B1.txt for windows.
                      The case of high condition number
A:
1.000 1.000
1.000 1.001
The condition number of A matrix is 4004.
b1:		b2:
2.000		2.000
2.000		2.001 
x1:             x2
2               1
0               1 
|x2(0)-x1(0)|/|b2[1]-b1[1]|=1*100=100

|x2(1)-x1(1)|/|b2[1]-b1[1]|=1*100=100
one hundred percent change
  Small change in second row of b1 between b2 vector results in huge change.Thats why,A matrix is ill-conditioned.
  We can understand because of that condition number is very large.
cd\Users\Mehmet\Desktop>Ee242firstproject