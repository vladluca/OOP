/*
 * car.h
 *
 *  Created on: Mar 11, 2015
 *      Author: Vlad
 */


#define VECTOR_INITIAL_CAPACITY 100
typedef struct {
	char *nr;
	char *model;
	char *category;
} car;

// Define a vector type

typedef struct {
  int size;      // slots used so far
  int capacity;  // total available slots
  car *data;     // array of integers we're storing
} Vector;

void vector_init(Vector *vector);

void vector_append(Vector *vector, car *value);

car vector_get(Vector *vector, int index);

int vector_get_size(Vector *vector);

void vector_set(Vector *vector, car *value, int index);

void vector_remove(Vector *vector, int index);

Vector vector_filter_by_model(Vector *vector, char *model);

Vector vector_filter_by_category(Vector *vector, char *category);

void vector_double_capacity_if_full(Vector *vector);

Vector cpy_vector(Vector *vector);

void vector_free(Vector *vector);

void vector_print(Vector *vector,int index);
