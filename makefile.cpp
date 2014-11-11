//============================================================================
// Name        : makefile.cpp
// Problem     : CSC 340 Homework 5, #2
// Author      : Devin Clary
// Version     : 1.1
// Copyright   : Devin Clary
// Description : Make a random file, and call statistics programs to analyze 
//============================================================================



#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;


void rand(int &result, int upperLim ) //generate random number between 1 and upperLim
{

    result=rand()%upperLim;
}


void randomNumSum(int &result, int n, int range) //result=sum of nTimes random numbers in range
{
    int sum=0;
    int temp=0;
    for(int i=0; i<n; i++)
    {
        rand(temp, range);
        sum+=temp;
    }
    result=sum;
}

void makeFileRandNumSum(ofstream &out, int n, int degreeRand, int range) //create n numbers composed of the sum of degreeRand numbers
{
    int result=0;
    for (int i=1; i<=n; i++){
        randomNumSum(result, degreeRand, range);
        out<<result<<' ';
        if(i%20==0){
            out<<endl; //make lines that are 20 numbers long
        }
    }
}
int main(void) {
    
    cout<<"--------------------------------------------------"<<endl;
    cout<<"System 1-makefile.cpp executed. Creating random file."<<endl;

    srand((unsigned int)time(NULL));
    char fileName[]="random.dat";
    ofstream out(fileName, ios::out);
    makeFileRandNumSum(out, 200, 12, 9);
    out.close();

    cout<<"Created random file 'random.dat'."<<endl;



    system("g++ statistics.cpp");
    system("./a.out");

    system("g++ distribution.cpp");
    system("./a.out");

    cout<<endl;
    cout<<"End of program."<<endl;
    cout<<"--------------------------------------------------"<<endl;

    return 0;
}

