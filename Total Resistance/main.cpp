/* @Tolga Ovatman
Student Name: Furkan Uysal
Student ID : 150150044
Date: 9.12.2020 */

#include <iostream>
#include <fstream>
#include "circuit.h"

using namespace std;

int main(int argc, char* argv[]){
	char a;
	double b;
	circuit mylist;
	ifstream myf;
	/*I could not handle read problem.
	It reads perfectly until it prints NO_RESISTOR with argc, argv arguments*/
	myf.open("input.txt");
	mylist.create();
	myf >> a;
	myf >> b;
	while(myf)
	{
		if(a == 'A' && b==0) mylist.circuit_info();
		else if(b>0)
		{
			mylist.add_resistor(a,b);
		}
		else
		{
			mylist.remove_resistor(a,b);
		}
		myf >> a;
		myf >> b;
	}
	mylist.clear();
	myf.close();
	getchar();
}