/* @Tolga Ovatman
Student Name: Furkan Uysal
Student ID : 150150044
Date: 9.12.2020 */
#include <iostream>
#include "circuit.h"

using namespace std;

void circuit::create()
{
	head = NULL;
	smallest = NULL;
}

void circuit::add_resistor(char x, double y)
{
	resistor* traverse;
	resistor* prev;
	resistor* ptr = new resistor;
	ptr->group = x;
	ptr->value = y;
	ptr->quantity = 1;

	if (head == NULL) {
		head = ptr;
		ptr->next = NULL;
	}
	else {
		if (head->group > x)
		{
			ptr->next = head;
			head = ptr;
		}
		else if (head->group == x) head->quantity += 1;
		else {
			traverse = head;
			while (traverse->next != NULL && traverse->group < x)
			{
				prev = traverse;
				traverse = traverse->next;
			}
			if (traverse->group > x) {
				prev->next = ptr;
				ptr->next = traverse;
			}
			else if (traverse->group == x) traverse->quantity += 1;
			else {
				ptr->next = NULL;
				traverse->next = ptr;
			}
		}
	}
}

void circuit::remove_resistor(char x, double y)
{
	resistor* traverse;
	traverse = head;
	while(traverse)
	{
		if(traverse->group == x)
		{
			if(traverse->quantity == 1)
			{
				return delete_resistor(x);
			}
			else
			{
				traverse->quantity -= 1;
				return;
			}
		}
		traverse = traverse->next;
	}
	cout << "NO_RESISTOR" << endl;
}
	
void circuit::delete_resistor(char target)
{
	resistor* traverse = new resistor;
	resistor* prev;
	traverse = head;
	if(head->group == target)
	{
		head = head->next;
		delete traverse;
	}
	else
	{
		while(traverse)
		{
			if(traverse->group == target)
			{
				prev->next = traverse->next;
				delete traverse;
				break;
			}
			prev = traverse;
			traverse = traverse->next;
		}
	}
}
	
void circuit::circuit_info()
{
	resistor* trav;
	ascending* tmp;
	ascending* prev;
	trav = head;
	tmp = smallest;
	double total = 0;
	if(head == NULL) cout << "NO_RESISTOR" << endl;
	else
	{
		while(trav)
		{
			total += trav->value / trav->quantity;
			ascending* ptr = new ascending;
			ptr->value = trav->value;
			ptr->quantity = trav->quantity;
			if (smallest == NULL)
			{
				smallest = ptr;
				ptr->next = NULL;
			}
			else
			{
				if(smallest->value > ptr->value)
				{
					ptr->next = smallest;
					smallest = ptr;
				}
				else if (smallest->value == ptr->value) smallest->quantity += 1;
				else
				{
					tmp = smallest;
					while (tmp->next != NULL && tmp->value < ptr->value)
					{
						prev = tmp;
						tmp = tmp->next;
					}
					if (tmp->value > ptr->value)
					{
						prev->next = ptr;
						ptr->next = tmp;
					}
					else if (tmp->value == ptr->value) tmp->quantity += 1;
					else
					{
						ptr->next = NULL;
						tmp->next = ptr;
					}
				}
			}
			trav = trav->next;
		}
		tmp = smallest;
		while(tmp)
		{
			cout << tmp->value << ":" << tmp->quantity << endl;
			tmp = tmp->next;
		}
		clearasc();
		cout << "Total Resistance=" << total << " ohm" << endl;
	}
	delete trav;
	delete tmp;
	delete prev;
}

void circuit::clearasc()
{
	ascending* ptr;
	while (smallest)
	{
		ptr = smallest;
		smallest = smallest->next;
		delete ptr;
	}
}

void circuit::clear()
{
	resistor* ptr;
	while (head)
	{
		ptr = head;
		head = head->next;
		delete ptr;
	}
}