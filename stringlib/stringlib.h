#ifndef __STRINGLIB_H__
#define __STRINGLIB_H__ 1

extern int streq(char *, char *);
extern char * join(char *, char *);
extern int starts_with(const char * input, const char * with);
/*
 * Compares `str` with `cmp`. If after comparison, there are remaining chars in `str`,
 * the comparison is called valid if they are only chars like crumb until the end
 */
extern int streq_with_crumb(const char * str, const char * cmp, const char crumb);

#endif
