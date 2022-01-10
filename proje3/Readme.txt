                        C++ Program for secant,bisection,and hybrid methods.                                             2016401351 Ramazan Aydın   
   We have at least four arguments.They are coeefficients of the function,initial guesses and the tolerance. 
   Argv[0] reads name of the file(source.exe),between argv[1] and argv[n+1] reads first coefficients of the function, 
   argv[n+2] reads first initial guess, argv[3] reads second initial guess,and argv[4] reads tolerance as tolerance value.
   Fristly,by using dynamic memory allocation,We create f vector in memory.The dimension of f vector is n+1=argc-4.
   Secondly,we fill f vector by using coefficients of function.
   Thirdly, we create y vector according to the number of coefficients of function.The dimension of y vector is n+1=argc-4.
   Fourhtly,we implement the hybrid method which is with bisection methods for the first two iterations and then continue with secant method for the rest of the iterations. 
   Fifthly,We implement the secant method.

   secant method:xk+1=xk-f(xk)*(xk-x(k-1))/(f(xk)-f(x(k-1)))
   
   Sixthly,We implement the bisection method:
   The input for the method is a continuous function f, an interval [a, b], and the function values f(a) and f(b). 
   The function values are of opposite sign (there is at least one zero crossing within the interval). 
   Each iteration performs these steps:

   1)Calculate c, the midpoint of the interval, c = (a + b)/2
   2)Calculate the function value at the midpoint, f(c).
   3)If convergence is satisfactory (that is, c - a is sufficiently small, or |f(c)| is sufficiently small), return c and stop iterating.
   4)Examine the sign of f(c) and replace either (a, f(a)) or (b, f(b)) with (c, f(c)) so that there is a zero crossing within the new interval.
   When implementing the method on a computer, there can be problems with finite precision, so there are often additional convergence tests or limits to the number of iterations.
   Although f is continuous, finite precision may preclude a function value ever being zero.
   For example, consider f(x) = x − π; there will never be a finite representation of x that gives zero. 
   Additionally, the difference between a and b is limited by the floating point precision;
   i.e., as the difference between a and b decreases, at some point the midpoint of [a, b] will be numerically identical to (within floating point precision of) either a or b.
   Finally, we delete f vector in memory.
   How to run the program?
   open source.cpp
   click execute and compile&run 
   We use comment line to our programme by writing application name after the find where programme is.
   Example: .\source.exe coefficients of function first initial guess second initial guess tolerance value for windows.
   Some examples for these methods:
   Also all values may also be entered parameters in execute and compile&run.

The command line arguments are: 2 2 -7 1 -7 1.5 1.8 0.001 (the example in project
Your program should solve 2𝑥4 + 2𝑥3 − 7𝑥2 + 𝑥 − 7 = 0.
So the program works:

Input: 

2 2 -7 1 -7 1.5 1.8 0.001 

Output: 

For the Bisection Method: 9 number of iterations and 1.66934 is the root.

For the Secant Method: 4 number of iterations and 1.66941 is the root.

For the Hybrid Method: 5 number of iterations and 1.66941 is the root.



Input: 

2 2 -7 1 -7 1 2 0.0001 

Output:

For the Bisection Method: 14 number of iterations and 1.66937 is the root.

For the Secant Method: 7 number of iterations and 1.66941 is the root.

For the Hybrid Method: 6 number of iterations and 1.66941 is the root.



Input:

3 -5 -5 2 3 2 2.5 0.0001 

Output:

For the Bisection Method: 13 number of iterations and 2.19318 is the root.

For the Secant Method: 6 number of iterations and 2.1932 is the root.

For the Hybrid Method: 6 number of iterations and 2.1932 is the root.



Input:

-6 -2 2 -4 -2 6 9 0.8 1.5 0.0001

Output:

For the Bisection Method: 13 number of iterations and 1.0549 is the root.

For the Secant Method: 8 number of iterations and 1.05496 is the root.

For the Hybrid Method: 7 number of iterations and 1.05496 is the root.



Input:

 3 -9 4 2 3 0.0001

Output:

For the Bisection Method: 14 number of iterations and 2.45746 is the root.

For the Secant Method: 5 number of iterations and 2.45743 is the root.

For the Hybrid Method: 6 number of iterations and 2.45743 is the root.



                     
