<h1>Description</h1>
<p>A school programming assignment in the C++ programming language. The program makefile.cpp creates a file of random numbers, then calls the program statistics.cpp which sorts, and calculates statistics on the data set created. The program distribution.cpp is then called and prints a histogram of the data set to the console. </p>
---------------------------------------------------------
<h2>Contains:</h2>
<p>
-makefile.cpp 
-statistics.cpp
-distribution.cpp
</p>
---------------------------------------------------------
<h3>Purpose:</h3> 
<p>-Demonstrate the use of shell scripting from within a C++ program to call other C++ programs</p>
---------------------------------------------------------
<h3>Example Output</h3>

<p>
--------------------------------------------------
System 1-makefile.cpp executed. Creating random file.
Created random file 'random.dat'.
--------------------------------------------------
Running System 2-statistics.cpp.
Sorting random.dat file.
Sorted file 'random.dat' successfully.
Basic statistics of data:
Mean: 47.625
Variance: 82.2044
Standard Deviation: 9.06666
Coefficient of Variation: 0.190376
--------------------------------------------------
Running System 3-distribution.cpp.
Histogram of data:
0-5      |
5-10     |
10-15    |
15-20    |*
20-25    |*
25-30    |*****
30-35    |*********
35-40    |**********************
40-45    |**********************************
45-50    |*************************************
50-55    |***********************************************
55-60    |**************************
60-65    |************
65-70    |******
70-75    |
75-80    |
80-85    |
85-90    |
90-95    |
95-100   |

End of program.
--------------------------------------------------
</p>
