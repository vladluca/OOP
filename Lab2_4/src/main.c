/*
 * main.c

 *
 *  Created on: Mar 11, 2015
 *      Author: Vlad
 */

#include "car.h"
#include "testcar.h"
#include "ui.h"
#include "testcontroller.h"
#include <stdlib.h>
#include <stdio.h>



int main()
{
	setbuf(stdout, NULL);
	Vector sir;
	test_run();
	test_run_controller();

	vector_init(&sir);
	ui(&sir);
	return (0);
}
