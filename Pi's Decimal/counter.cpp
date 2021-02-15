/*
YOU HAVE TO WRITE THE REQUIRED  FUNCTIONS. YOU CAN ADD NEW FUNCTIONS IF YOU NEED.
*/

/* @Tolga Ovatman
Student Name: Furkan Uysal
Student ID : 150150044
Date: 11.11.2020 */

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "counter.h"

using namespace std;

	
int Counter::findindex(Token *arr,char elem[]){
	int index = 0;
	for (index = 0; index < token_count; index++)
	{
		if(arr[index].token[0] == elem[0] && arr[index].token[1] == elem[1])
		{
			return index;
		}
	}
	return -1;
} 

bool Counter::contains(char *token, char target){
	int i = 0;
	while (token[i] != '\0') {
		if (token[i] == target) return true;
		i++;
	}
	return false;
}

void Counter::read_and_count(){
	char c, tok[2];
	string line;
	int k, index = 0, count = 0, i = 0, dot;
	FILE* filePointer; 
	filePointer = fopen("pi_approximate", "r");
	for (c = getc(filePointer); c != EOF; c = getc(filePointer))
	{
		line.push_back(c);
		count++;
		if(c == '.' || c == ',') dot = count;
	}
	fclose(filePointer);
	k = dot;
	while(k < count - 1)
	{
		tok[0] = line[k];
		tok[1] = line[k+1];
		index = findindex(token_array, tok);
		if(index == -1)
		{
			token_array[i].token[0] = tok[0];
			token_array[i].token[1] = tok[1];
			token_array[i].count++;
			token_count++;
			i++;
		}
		else
			token_array[index].count++;
		k++;
	}
}

Token *Counter::get_most_common_three(){
	Token* mct;
	mct = new Token[3];
	Token x, tokens[token_count];
	int i = 0, j = 0;
	for(i = 0 ; i < token_count ; i++) tokens[i] = token_array[i];
	for (i = 0; i < token_count; i++)
	{
		for (j = 0; j < token_count; j++)
		{
			if (tokens[i].count > tokens[j].count) 
            {
                x =  tokens[i];
                tokens[i] = tokens[j];
                tokens[j] = x;
            }
		}
	}
	for (i = 0; i < 3; i++)
	{
		mct[i] = tokens[i];
	}
	return mct;
}
