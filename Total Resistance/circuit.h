/* @Tolga Ovatman
Student Name: Furkan Uysal
Student ID : 150150044
Date: 9.12.2020 */

#ifndef _H
#define _H
#include <iostream>

using namespace std;

#include "utility.h"

struct circuit {
	resistor* head;
	ascending* smallest;
	void create();
	void add_resistor(char, double);
	void remove_resistor(char, double);
	void delete_resistor(char);
	void circuit_info();
	void clearasc();
	void clear();
};
#endif