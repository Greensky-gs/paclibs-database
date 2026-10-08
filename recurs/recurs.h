#ifndef __RECURS_H__
#define __RECURS_H__ 1

typedef enum {
	Ok = 0,
	UnknownPath = 1,
	ReadError = 2,
	Error = 3,
} recursion_result_t;

extern recursion_result_t recursion(
	char * path,
	void * file_data,
	void file_callback(char * path, void *),
	void * dir_data,
	void dir_callback(char * path, void *)
);

#endif
