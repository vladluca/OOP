#include <assert.h>
#include "car.h"

void test_vector_init()
{
	Vector sir;

	vector_init(&sir);
	assert(sir.capacity == 100);
	assert(sir.size == 0);
}

void test_vector_append()
{
	Vector sir;
	car masina;
	masina.category = "da";
	masina.model = "nu";
	masina.nr = "cd";
	vector_init(&sir);
	assert(sir.size == 0);
	vector_append(&sir, &masina);
	assert(sir.data[0].category == "da");
	assert(sir.data[0].model == "nu");
	assert(sir.data[0].nr == "cd");
	assert(sir.size == 1);
}

void test_vector_get()
{
	Vector sir;
	car masina;
	car test;
	masina.category = "da";
	masina.model = "nu";
	masina.nr = "cd";
	vector_init(&sir);
	assert(sir.size == 0);
	vector_append(&sir, &masina);
	assert(sir.size == 1);
	test = vector_get(&sir, 0);
	assert(test.category == "da");
	assert(test.model == "nu");
	assert(test.nr == "cd");
}




void test_vector_set()
{
	Vector sir;
	car masina;
	car test;
	masina.category = "da";
	masina.model = "nu";
	masina.nr = "cd";
	vector_init(&sir);
	vector_append(&sir, &masina);
	masina.category = "ana";
	masina.model = "are";
	masina.nr = "mere";
	vector_set(&sir, &masina, 0);
	test = vector_get(&sir, 0);
	assert(test.category == "ana");
	assert(test.model == "are");
	assert(test.nr == "mere");

}


void test_vector_remove()
{
	Vector sir;
	car masina;
	car test;
	masina.category = "da";
	masina.model = "nu";
	masina.nr = "cd";
	vector_init(&sir);
	vector_append(&sir, &masina);
	assert(sir.size == 1);
	vector_remove(&sir, 0);
	assert(sir.size == 0);
}


void test_vector_filter_by_model()
{
	Vector sir;
	car masina;
	Vector test;
	masina.category = "da";
	masina.model = "nu";
	masina.nr = "cd";
	vector_init(&sir);
	vector_append(&sir, &masina);
	test = vector_filter_by_model(&sir, "nu");
	assert(test.data[0].category == "da");
	assert(test.data[0].model == "nu");
	assert(test.data[0].nr == "cd");

}


void test_vector_filter_by_category()
{
	Vector sir;
	car masina;
	Vector test;
	masina.category = "da";
	masina.model = "nu";
	masina.nr = "cd";
	vector_init(&sir);
	vector_append(&sir, &masina);
	test = vector_filter_by_category(&sir, "da");
	assert(test.data[0].category == "da");
	assert(test.data[0].model == "nu");
	assert(test.data[0].nr == "cd");
}


void test_run()
{
	test_vector_init();
	test_vector_append();
	test_vector_get();
	test_vector_set();
	test_vector_remove();
	test_vector_filter_by_model();
	test_vector_filter_by_category();

}


