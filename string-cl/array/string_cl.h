#ifndef __ARRAY_STRINGCL_H__
#define __ARRAY_STRINGCL_H__ 1

#include "../string_cl.h"

extern char ** stringcl_into_array(stringcl_cell, unsigned long *);
extern char ** stringcl_into_array_dup(stringcl_cell, unsigned long *);

/**
 * Convert a string chained list to an array, without duplicating the values from the list
 *
 * @param int * - controls the result. If set to NULL nothing happens, else set to 1 if everything went ok, 0 otherwise
 */
extern stringcl_cell stringcl_from_array(char **, unsigned long, int *);
/**
 * Convert a string chained list to an array, by duplicating the values of the list
 *
 * @param int * - controls the result. If set to NULL nothing happens, else set to 1 if everything went ok, 0 otherwise
 */
extern stringcl_cell stringcl_from_array_dup(char **, unsigned long, int *);

#endif
