/*
 * controller.c
 *
 *  Created on: Mar 13, 2015
 *      Author: Vlad
 */


#include "car.h"
#include "testcar.h"
#include "ui.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void controller_vector_append(Vector *vector, char *number, char *model, char *category)
{
	car aux;
	aux.nr=number;
	aux.model=model;
	aux.category=category;
	vector_append(vector,&aux);
}

void controller_set_car(Vector *vector, char *number, char *model, char *category, char *opt)
{
	int index;
	int ok;
	ok = 1;
	car elem;
	for(index = 0; (index < vector_get_size(vector)) && ok == 1; index++)
	{
		elem = vector_get(vector, index);
		if(strcmp(elem.nr, opt) == 0)
			ok = 0;
	}
	if(ok == 1)
	{
		print_error();
	}
	else
	{
		index--;
		printf("%d", index);
		car aux;
		aux.nr=number;
		aux.model=model;
		aux.category=category;
		vector_set(vector, &aux, index);
	}
}



void controller_remove_car(Vector *vector, char *opt)
{
	int index;
	int ok;
	ok = 1;
	car elem;
	for(index = 0; (index < vector_get_size(vector)) && ok == 1; index++)
	{
		elem = vector_get(vector, index);
		if(strcmp(elem.nr, opt) == 0)
			ok = 0;
	}
	if(ok == 1)
	{
		print_error();
	}
	else
	{
		index--;
		vector_remove(vector, index);
	}
}

Vector controller_filter_by_model(Vector *vector, char *model)
{
	return(vector_filter_by_model(vector, model));

}


Vector controller_filter_by_category(Vector *vector, char *category)
{
	return(vector_filter_by_category(vector, category));

}

Vector controller_cpy_vector(Vector *vector)
{
	return(cpy_vector(vector));
}




