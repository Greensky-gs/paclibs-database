#include "recurs.h"
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

static int is_sys_path(char * a) {
	if (a == NULL) return 0;
	if (*a == 0) return 0;
	if (*a == '.' && a[1] == 0) return 1;
	if (*a == '.' && a[1] == '.' && a[2] == 0) return 1;
	return 0;
}
static void concat(char * target, char * a, char * b) {
	while (*a != 0) {
		target[0] = a[0];
		target++;
		a++;
	}
	*target = '/';
	target++;
	while (*b != 0) {
		target[0] = b[0];
		target++;
		b++;
	}
	target[0] = 0;
}
recursion_result_t recursion(
	char * path,
	void * file_data,
	void file_callback(char *, void *),
	void * dir_data,
	void dir_callback(char *, void *)
) {
	DIR * dir;
	if ((dir = opendir(path)) == NULL) {
		perror("opendir");
		return UnknownPath;
	}

	struct dirent * entry;
	struct stat sb;
	errno = 0;
	while ((entry = readdir(dir)) != NULL) {
		if (is_sys_path(entry->d_name)) continue;

		char * newpath;
		if ((newpath = malloc(strlen(entry->d_name) + strlen(path) + 2)) == 0) {
			perror("malloc");
			errno = 0;
			continue;
		}

		concat(newpath, path, entry->d_name);
		if (stat(newpath, &sb) == -1) {
			perror("stat");
			errno = 0;
			free(newpath);
			continue;
		}
	
		if (S_ISDIR(sb.st_mode)) {
			if (dir_callback != NULL) dir_callback(newpath, dir_data);
			recursion(newpath, file_data, file_callback, dir_data, dir_callback);
		} else if (S_ISREG(sb.st_mode)) {
			if (file_callback != NULL) file_callback(newpath, file_data);
		}

		free(newpath);
	}
	if (errno != 0) {
		perror("readdir");
		return ReadError;
	}

	closedir(dir);
	return Ok;
}
