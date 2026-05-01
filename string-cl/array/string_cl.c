#include "./string_cl.h"
#include "../string_cl.h"
#include <stdlib.h>
#include <string.h>

#define SET_VAL(ptr, value) {if (ptr != NULL) (*ptr) = value;}

char ** stringcl_into_array(stringcl_cell list, unsigned long * size) {
	char ** array;
	*size = stringcl_size(list);
	if ((array = malloc(sizeof(char *) * (*size))) == NULL) return NULL;

	unsigned long index = 0;
	while (list != NULL) {
		array[index] = list->value;
		list = list->next;
	}

	return array;
}
char ** stringcl_into_array_dup(stringcl_cell list, unsigned long * size) {
	char ** array;
	*size = stringcl_size(list);
	if ((array = malloc(sizeof(char *) * (*size))) == NULL) return NULL;

	unsigned long index = 0;
	while (list != NULL) {
		array[index] = strdup(list->value);
		list = list->next;
	}

	return array;
}

stringcl_cell stringcl_from_array(char ** array, unsigned long size, int * valid) {
	stringcl_cell list = NULL;
	SET_VAL(valid, 1);

	unsigned long i = 0;
	while (i < size) {
		if (!stringcl_append(&list, array[i])) SET_VAL(valid, 0);
		i++;
	}

	return list;
}
stringcl_cell stringcl_from_array_dup(char ** array, unsigned long size, int * valid) {
	stringcl_cell list = NULL;

	unsigned long i = 0;
	while (i < size) {
		char * dup;
		if ((dup = strdup(array[i])) != NULL) {
			if (!stringcl_append(&list, array[i])) SET_VAL(valid, 0);
		} else SET_VAL(valid, 0);
		i++;
	}

	return list;
}
