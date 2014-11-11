//============================================================================
// Name        : distribution.cpp
// Problem     : CSC 340 Homework 5, #2
// Author      : Devin Clary
// Version     : 1.1
// Copyright   : Devin Clary
// Description : Print histogram of data to console
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip> 
using namespace std;


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

void printHistLine(int a[], int length, int fromValue, int toValue)
{
	if(fromValue<10&&toValue<10)
	{
		cout<<fromValue<<'-'<<toValue<<"  ";
	}
	else if(fromValue<10||toValue<10)
	{
		cout<<fromValue<<'-'<<toValue<<' ';
	}
	else
	{
		cout<<fromValue<<'-'<<toValue;
	}
	if(toValue>99)
	{
		cout<<setw(4)<<'|';
	}
	else
	{
		cout<<setw(5)<<'|';
	}
	for(int i=0; i<length; i++){
		if(a[i]>=fromValue&&a[i]<toValue){
			cout<<'*';
		}
	}
	cout<<endl;
}

void printHist(int a[], int length)
{
	for(int i=0; i<100; i+=5)
	{
		printHistLine(a, length, i, i+5);
	}
}



int main(void)
{
	cout<<"Running System 3-distribution.cpp."<<endl;
	cout<<"Histogram of data: "<<endl;
	char fileName[]="random.dat";
	int a[200];
	fileToArray(a, 200, fileName);
	printHist(a, 200);


	return 0;
}