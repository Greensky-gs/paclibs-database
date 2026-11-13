#ifndef __CSTRING_H__
#define __CSTRING_H__ 1

typedef char * cstring;
typedef long int cstring_size_t;

/**
 * It does not count the null terminator
 */
extern cstring cstring_create(cstring_size_t);
extern void cstring_destroy(cstring);
extern cstring cstring_copy(cstring);
extern cstring_size_t cstring_size(cstring);
/**
 * 0 is the very last character
 */
extern char cstring_reverse_nth(cstring, cstring_size_t);

#endif
