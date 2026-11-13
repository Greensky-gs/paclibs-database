#include "../args.h"
#include <stdio.h>

void display_args(int args_count, struct arg_input args[]) {
	int i = 0;
	while (i < args_count) {
		printf("    \x1b[90m%-19s\x1b[0m : %s. Of type \x1b[91m", args[i].name, args[i].description);
		switch (args[i].type) {
			case String:
				printf("string\x1b[0m");
				if (args[i].str_result == NULL) printf(", no default value is provided\n");
				else printf(", default value set to \x1b[33m%s\x1b[0m", args[i].str_result);
				break;
			case Int:
				printf("integer\x1b[0m, default value is set to \x1b[33m%d\x1b[0m\n", args[i].int_res);
				break;
			case Presence:
				printf("toggle\x1b[0m\n");
				break;
		}
		i++;
	}
}
