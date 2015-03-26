/*
 * car.c
 *
 *  Created on: Mar 11, 2015
 *      Author: Vlad
 */


#include <stdio.h>
#include <stdlib.h>
#include "car.h"
#include <string.h>




// It will allocate memory for
// an element of type Vector

void vector_init(Vector *vector) {
  // initialize size and capacity
  vector->size = 0;
  vector->capacity = VECTOR_INITIAL_CAPACITY;

  // allocate memory for vector->data
  vector->data = malloc(sizeof(car) * vector->capacity);
}



//appends a new element of type car
//to the end of the list. If the list is full it will
//reallocate the list with enaught memory

void vector_append(Vector *vector, car *value) {
  // make sure there's room to expand into
  vector_double_capacity_if_full(vector);

  // append the value and increment vector->size
  vector->data[vector->size].category = value->category;
  vector->data[vector->size].nr = value->nr;
  vector->data[vector->size].model = value->model;
  vector->size++;

}

//The function returns an element of type car
//wich is found at position "index" in the list
//of type Vector

car vector_get(Vector *vector, int index) {
  if (index >= vector->size || index < 0) {
    //printf("Index %d out of bounds for vector of size %d\n", index, vector->size);
    exit(1);
  }
  return vector->data[index];
}

int vector_get_size(Vector *vector)
{
	return(vector->size);
}

void vector_set(Vector *vector, car *value, int index)
{
	vector->data[index].category = value->category;
	vector->data[index].nr = value->nr;
	vector->data[index].model = value->model;
}


void vector_remove(Vector *vector, int index)
{
	int i;
	for (i = index; i < (vector->size) - 1; i++)
	{
		vector->data[i].category = vector->data[i + 1].category;
		vector->data[i].nr = vector->data[i + 1].nr;
		vector->data[i].model = vector->data[i + 1].model;
	}
	vector->size--;
}


Vector vector_filter_by_model(Vector *vector, char *model)
{
	Vector sir;
	vector_init(&sir);
	int i;
	for (i = 0; i < vector->size; i++)
	{
		if(strcmp(vector->data[i].model, model) == 0)
			vector_append(&sir, &(vector->data[i]));
	}
	return(sir);
}


Vector vector_filter_by_category(Vector *vector, char *category)
{
	Vector sir;
	vector_init(&sir);
	int i;
	for (i = 0; i < vector->size; i++)
	{
		if(strcmp(vector->data[i].category, category) == 0)
			vector_append(&sir, &(vector->data[i]));
	}
	return(sir);
}


//The function reallocate memory for an element
//of type vector( 2 * the current size)

void vector_double_capacity_if_full(Vector *vector) {
  if (vector->size >= vector->capacity) {
    // double vector->capacity and resize the allocated memory accordingly
    vector->capacity *= 2;
    vector->data = realloc(vector->data, sizeof(car) * vector->capacity);
  }
}


Vector cpy_vector(Vector *vector)
{
	Vector back;
	vector_init(&back);
	int i;
	for (i = 0; i < vector->size; i++)
	{
		vector_append(&back, &(vector->data[i]));
	}
	return(back);
}

//The function frees the memory allocated to an element of
//type vector

void vector_free(Vector *vector) {
  free(vector->data);
}


