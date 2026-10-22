#include "exec_command.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int exec_command(char * args[]) {
	pid_t pid;
	int status;

	switch (pid = fork()) {
		case -1:
			perror("fork");
			return -1;
		case 0:
			execvp(args[0], args);
			perror("execvp");
			exit(127);
			break;
		default:
			waitpid(pid, &status, 0);

			if (WIFEXITED(status)) return WEXITSTATUS(status);
			return 127;
	}
}
