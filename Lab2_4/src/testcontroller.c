/*
 * testcontroller.c
 *
 *  Created on: Mar 19, 2015
 *      Author: Vlad
 */

#include <assert.h>
#include "car.h"
#include "controller.h"

void test_controller_vector_append()
{
	Vector sir;

	vector_init(&sir);
	assert(sir.size == 0);
	controller_vector_append(&sir, "mere", "are", "ana");
	assert(sir.data[0].category == "ana");
	assert(sir.data[0].model == "are");
	assert(sir.data[0].nr == "mere");

}


void test_controller_vector_set()
{
	Vector sir;
	vector_init(&sir);
	controller_vector_append(&sir, "mere", "are", "ana");
	controller_set_car(&sir, "numar", "model", "category", "mere");
	assert(sir.data[0].category == "category");
	assert(sir.data[0].model == "model");
	assert(sir.data[0].nr == "numar");
}

void test_controller_vector_remove()
{
	Vector sir;
	vector_init(&sir);
	controller_vector_append(&sir, "mere", "are", "ana");
	controller_remove_car(&sir, "mere");
	assert(sir.size == 0);
}

void test_controller_filter_by_model()
{

	Vector sir;
	car masina;
	Vector test;
	masina.category = "da";
	masina.model = "nu";
	masina.nr = "cd";
	vector_init(&sir);
	vector_append(&sir, &masina);
	test = controller_filter_by_model(&sir, "nu");
	assert(test.data[0].category == "da");
	assert(test.data[0].model == "nu");
	assert(test.data[0].nr == "cd");

}



void test_controller_filter_by_category()
{
	Vector sir;
	car masina;
	Vector test;
	masina.category = "da";
	masina.model = "nu";
	masina.nr = "cd";
	vector_init(&sir);
	vector_append(&sir, &masina);
	test = controller_filter_by_category(&sir, "da");
	assert(test.data[0].category == "da");
	assert(test.data[0].model == "nu");
	assert(test.data[0].nr == "cd");
}


void test_run_controller()
{
	test_controller_vector_append();
	test_controller_vector_set();
	test_controller_vector_remove();
	test_controller_filter_by_model();
	test_controller_filter_by_category();
}
