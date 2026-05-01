#ifndef __STRING_CL_H__
#define __STRING_CL_H__ 1

struct st_chained_cell {
	char * value;
	struct st_chained_cell * next;
};
typedef struct st_chained_cell * stringcl_cell;

extern stringcl_cell stringcl_create(char *);
extern void stringcl_destroy(stringcl_cell *);
extern void stringcl_destroy_nofree(stringcl_cell *);
extern unsigned long int stringcl_size(stringcl_cell);
extern int stringcl_append(stringcl_cell *, char *);
extern int stringcl_exists(stringcl_cell, char *);
extern int stringcl_remove(stringcl_cell *, char *);
extern int stringcl_removep(stringcl_cell *, stringcl_cell);
extern void stringcl_foreach(stringcl_cell, void *, void callback(stringcl_cell, void *));

extern char ** stringcl_into_array(stringcl_cell, unsigned long *);

#endif
