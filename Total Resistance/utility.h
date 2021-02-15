/* @Tolga Ovatman
Student Name: Furkan Uysal
Student ID : 150150044
Date: 9.12.2020 */

struct resistor {
	char group;
	double value;
	int quantity;
	resistor* next;
};

struct ascending {
	double value;
	int quantity;
	ascending* next;
};