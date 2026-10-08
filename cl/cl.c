#include <stdlib.h>
#include "cl.h"

cl_cell cl_create(int val) {
	cl_cell cell;
	if ((cell = malloc(sizeof(struct st_cl_t_chained_cell))) == NULL) return NULL;

	cell->next = NULL;
	cell->value = val;
	return cell;
}
void cl_destroy(cl_cell * list) {
	if (list == NULL) return;

	cl_cell current = *list;
	while (current != NULL) {
		cl_cell next = current->next;
		free(current);

		current = next;
	}

	*list = NULL;
}
unsigned long int cl_size(cl_cell list) {
	unsigned long int c = 0;
	while (list != NULL) {
		c++;
		list = list->next;
	}
	return c;
}
int cl_append(cl_cell * list, int val) {
	if (list == NULL) return 0;

	cl_cell cell;
	if ((cell = cl_create(val)) == NULL) return 0;

	if (*list == NULL) {
		*list = cell;
		return 1;
	}

	cl_cell previous = *list;
	cl_cell current = previous->next;
	while (current != NULL) {
		previous = current;
		current = previous->next;
	}

	previous->next = cell;
	return 1;
}
cl_t cl_nth(cl_cell list, unsigned long n) {
	while (list != NULL && n > 0) {
		list = list->next;
	}

	return list->value;
}
cl_cell cl_nthp(cl_cell list, unsigned long n) {
	while (list != NULL && n > 0) {
		list = list->next;
	}

	return list;
}
int cl_exists(cl_cell list, int val) {
	while (list != NULL) {
		if (list->value == val) return 1;
		list = list->next;
	}
	return 0;
}
int cl_remove(cl_cell * list, int val) {
	if (list == NULL) return 0;

	if ((*list)->value == val) {
		cl_cell next = (*list)->next;
		free(*list);
		*list = next;
		return 1;
	}

	cl_cell previous = *list;
	cl_cell current = previous->next;
	while (current != NULL) {
		if (current->value == val) {
			previous->next = current->next;
			free(current);
			return 1;
		}
		previous = current;
		current = previous->next;
	}
	return 0;
}
int cl_removep(cl_cell * list, cl_cell p) {
	if (list == NULL) return 0;

	if ((*list) == p) {
		cl_cell next = (*list)->next;
		free(*list);
		*list = next;
		return 1;
	}

	cl_cell previous = *list;
	cl_cell current = previous->next;
	while (current != NULL) {
		if (current == p) {
			previous->next = current->next;
			free(current);
			return 1;
		}
		previous = current;
		current = previous->next;
	}
	return 0;
}
void cl_foreach(cl_cell list, void * data, void callback(cl_cell, void *)) {
	while (list != NULL) {
		callback(list, data);
		list = list->next;
	}
}
