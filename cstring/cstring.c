#include "./cstring.h"
#include <stdlib.h>

cstring cstring_create(cstring_size_t s) {
	cstring string;
	if ((string = malloc(s + sizeof(cstring_size_t))) == NULL) return NULL;

	string[0] = s;
	return string + sizeof(cstring_size_t);
}
void cstring_destroy(cstring string) {
	free(string - sizeof(cstring_size_t));
}

cstring_size_t cstring_size(cstring string) {
	return *(string - sizeof(cstring_size_t));
}
cstring cstring_copy(cstring string) {
	cstring copy;
	cstring_size_t n = cstring_size(string);
	if ((copy = cstring_create(n)) == NULL) return NULL;

	int i = 0;
	while (i < n) {
		copy[i] = string[i];
		i++;
	}

	return copy;
}

char cstring_reverse_nth(cstring string, cstring_size_t n) {
	return string[cstring_size(string) - n - 1];
}
