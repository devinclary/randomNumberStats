//============================================================================
// Name        : statistics.cpp
// Problem     : CSC 340 Homework 5, #2
// Author      : Devin Clary
// Version     : 1.1
// Copyright   : Devin Clary
// Description : Calculate mean, std deviation, and coefficent of variation
//============================================================================
#include <iostream>
#include <fstream>
#include <math.h>  
using namespace std;


void swap(int a[], int indexA, int indexB){
    int temp=a[indexA];
    a[indexA]=a[indexB];
    a[indexB]=temp;
}


void selectionSort(int a[], int length){
    
    int smallestValue;
    
    for(int i=0; i<length-1; i++){
    	smallestValue=a[i];
	    for(int j=i+1; j<length; j++){
	        if(a[j]<smallestValue){
	            swap(a, i, j);
	            smallestValue=a[i];
	        }
	    }
	}
    
}

void fileToArray(int a[], int length, char fileName[]){
	
	ifstream in(fileName, ios::in);
	int nextNum;
	int i=0;
	while(in>>nextNum&&i<length)
	{
		a[i]=nextNum;
		i++;
	}
	in.close();
}

void arrayToFile(int a[], int length, char fileName[]){

	ofstream out(fileName, ios::out);

	for(int i=0; i<length; i++)
	{
		if(i%20==0&&i!=0){
			out<<endl;
		}
		out<<a[i]<<' ';
	}

	out.close();


}

void sortFile(char fileName[], int length)
{	
	int a[length];
	fileToArray(a, length, fileName);
	selectionSort(a, length);
	arrayToFile(a, length, fileName);

}

void calculateMeanFromArray(int a[],  int length, double &result){

	int sum=0;
	for(int i=0; i<length; i++){
		sum+=a[i];
	}

	result=(double)sum/(double)length;
}

void calculateVarianceFromArray(int a[], int length, double mean, double &result)
{
	double sumOfMeanDiffsSquared=0.;
	double currentDiffValue=0.;

	for(int i=0; i<length; i++) //calculate difference of each value and the mean. Square the result's and sum them together.
	{	
		currentDiffValue=(double)a[i]-mean;
		sumOfMeanDiffsSquared+=(currentDiffValue*currentDiffValue);
	}

	result=sumOfMeanDiffsSquared/length; //average the results to get the variance
}

void calculateStdDev(double variance, double &result)
{
	
	result=sqrt(variance);


}



int main (void)
{
   cout<<"--------------------------------------------------"<<endl;
   cout<<"Running System 2-statistics.cpp."<<endl;
   cout<<"Sorting random.dat file."<<endl;
   
   char fileName[]="random.dat";
   sortFile(fileName, 200);
   
   cout<<"Sorted file 'random.dat' successfully."<<endl;
   cout<<"Basic statistics of data:"<<endl;
   
   int a[200];
   fileToArray(a, 200, fileName);
   double mean, variance, stdDev;
   calculateMeanFromArray(a, 200, mean);
   calculateVarianceFromArray(a, 200, mean, variance);
   calculateStdDev(variance, stdDev);
   double coeffVar=stdDev/mean;

   cout<<"Mean: "<<mean<<"\nVariance: "<<variance<<"\nStandard Deviation: "<<stdDev<<"\nCoefficient of Variation: "<<coeffVar<<endl;

   cout<<"--------------------------------------------------"<<endl;
  
    
    return 0;
}
