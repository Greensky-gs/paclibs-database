#ifndef __INT_CL_H__
#define __INT_CL_H__ 1

typedef int cl_t;

struct st_cl_t_chained_cell {
	cl_t value;
	struct st_cl_t_chained_cell * next;
};
typedef struct st_cl_t_chained_cell * cl_cell;

extern cl_cell cl_create(cl_t);
extern void cl_destroy(cl_cell *);
extern unsigned long int cl_size(cl_cell);
extern int cl_append(cl_cell *, cl_t);
extern int cl_exists(cl_cell, cl_t);
extern cl_t cl_nth(cl_cell, unsigned long);
extern cl_cell cl_nthp(cl_cell, unsigned long);
extern int cl_remove(cl_cell *, cl_t);
extern int cl_removep(cl_cell *, cl_cell);
extern void cl_foreach(cl_cell, void *, void (cl_cell, void *));

#endif
