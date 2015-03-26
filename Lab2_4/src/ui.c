/*
 * ui.c
 *
 *  Created on: Mar 12, 2015
 *      Author: Vlad
 */

#include "car.h"
#include "testcar.h"
#include "controller.h"
#include <stdlib.h>
#include <stdio.h>




void print_error()
{
	printf("No element with the given number!");
}


//Print's on the screen all the elements of
//the list of type vector.

void print_car(Vector *vector){
	int index;
	//printf("Enter number of car to print:");
	//scanf("%i",&index);
	for(index = 0; index < vector->size; index++)
	{
		printf("%s%d%s\n", "Car ", index, ": ");
		vector_print(vector,index);
	}
}



//The function ask the user for the elements of a car variable
//and then calls the function vector_append wich will append
//the new element to the list of type Vector

void add_car(Vector *vector){
	char *number;
	number=malloc(sizeof(char)*100);
	char *model;
	model=malloc(sizeof(char)*100);
	char *category;
	category=malloc(sizeof(char)*100);
	printf("Enter category:");
	scanf("%s",category);
	printf("Enter model:");
	scanf("%s",model);
	printf("Enter number:");
	scanf("%s",number);
	controller_vector_append(vector,number, model, category);
}

void set_car(Vector *vector)
{
	char *opt;
	opt = malloc(sizeof(char) * 100);
	char *number;
	number=malloc(sizeof(char)*100);
	char *model;
	model=malloc(sizeof(char)*100);
	char *category;
	category=malloc(sizeof(char)*100);

	printf("Enter the number of the car you want to set:\n");
	scanf("%s", opt);

	printf("Enter category:");
	scanf("%s",category);
	printf("Enter model:");
	scanf("%s",model);
	printf("Enter number:");
	scanf("%s",number);
	controller_set_car(vector, number, model, category, opt);
}


void remove_car(Vector *vector)
{
	char *opt;
	opt = malloc(sizeof(char) * 100);

	printf("Enter the number of the car you want to remove:\n");
	scanf("%s", opt);
	controller_remove_car(vector, opt);
}


void filter_car(Vector *vector)
{
	int option;
	char *model;
	char *category;
	Vector sir;
	model = malloc(sizeof(char) * 100);
	category = malloc(sizeof(char) * 100);
	printf("Filter by: 1. Model | 2. Category\n");
	scanf("%d", &option);
	if(option == 1)
	{
		printf("Enter model: ");
		scanf("%s", model);
		sir = controller_filter_by_model(vector, model);
		print_car(&sir);
	}
	if(option == 2)
	{
		printf("Enter category: ");
		scanf("%s", category);
		sir = controller_filter_by_category(vector, category);
		print_car(&sir);
	}
}


//The function prints on the screen
//the element of a car find at the position "index"
//in the list of type Vector

void vector_print(Vector *vector,int index){
	car elem;
	elem = vector_get(vector, index);
	printf("%s\n",elem.category);
	printf("%s\n",elem.model);
	printf("%s\n",elem.nr);
}


//The function print's on the screen the menu
// and waits the user to give an option
// and then calls the requested function

void ui(Vector *vector){
	char *menu="\n1 - Add car | 2 - Modify car | 3 - Remove car | 4 - Filter | 5 - Undo | 6 - Print all | 0 - Exit\n";
	int option;
	Vector back;
	printf("%s",menu);
	scanf("%d",&option);
	while (option !=0 ){
		if(option==1){
			back = controller_cpy_vector(vector);
			add_car(vector);
		}
		if(option == 2){
			back = controller_cpy_vector(vector);
			set_car(vector);
		}
		if(option == 3)
		{
			back = controller_cpy_vector(vector);
			remove_car(vector);
		}
		if(option == 4)
		{
			filter_car(vector);
		}
		if(option == 5)
		{
			*vector = controller_cpy_vector(&back);
		}
		if(option == 6){
			print_car(vector);
		}

		printf("%s",menu);
		scanf("%d",&option);
	}

}
