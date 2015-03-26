/*
 * controller.h
 *
 *  Created on: Mar 13, 2015
 *      Author: Vlad
 */

#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_


void controller_vector_append(Vector *vector, char *number, char *model, char *category);
void controller_set_car(Vector *vector, char *number, char *model, char *category, char *opt);
void controller_remove_car(Vector *vector, char *opt);
Vector controller_filter_by_model(Vector *vector, char *model);
Vector controller_filter_by_category(Vector *vector, char *category);
Vector controller_cpy_vector(Vector *vector);

#endif /* SRC_CONTROLLER_H_ */
