#include "../cstring.h"
#include "./operations.h"
#include <stdlib.h>
#include <string.h>

#define CSTRING_SIZE_PTR(cstring) (*(cstring - sizeof(cstring_size_t)))

cstring cstring_concat_cc(cstring a, cstring b) {
	cstring_size_t total = CSTRING_SIZE_PTR(a) + CSTRING_SIZE_PTR(b);

	char * new;
	if ((new = malloc(total + 1)) == NULL) return NULL;

	new[total] = 0;
	new[0] = total;

	new = new + sizeof(cstring_size_t);

	int i = 0;
	while (a[i] != 0) {
		new[i] = a[i];
		i++;
	}
	int j = 0;
	while (b[j] != 0) {
		new[i + j] = b[j];
		j++;
	}

	return new;
}
cstring cstring_concat_cn(cstring a, char * b) {
	cstring_size_t total = CSTRING_SIZE_PTR(a) + strlen(b);

	char * new;
	if ((new = malloc(total + 1)) == NULL) return NULL;

	new[total] = 0;
	new[0] = total;

	new = new + sizeof(cstring_size_t);

	int i = 0;
	while (a[i] != 0) {
		new[i] = a[i];
		i++;
	}
	int j = 0;
	while (b[j] != 0) {
		new[i + j] = b[j];
		j++;
	}

	return new;
}

cstring cstring_concat_nn(char * a, char * b) {
	cstring_size_t total = strlen(a) + strlen(b);

	char * new;
	if ((new = malloc(total + 1)) == NULL) return NULL;

	new[total] = 0;
	new[0] = total;

	new = new + sizeof(cstring_size_t);

	int i = 0;
	while (a[i] != 0) {
		new[i] = a[i];
		i++;
	}
	int j = 0;
	while (b[j] != 0) {
		new[i + j] = b[j];
		j++;
	}

	return new;
}
