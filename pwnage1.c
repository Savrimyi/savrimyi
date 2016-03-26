#include <stdio.h>
#include <string.h>
#include <unistd.h>

void main(int argc, char ** argv)
{
	char * line = NULL;
	size_t len = 0;

	char pwn[8];
	char msg[32];

	if (argc < 2) {
		puts("Specify 'yes' or 'no' to pwn");
		return;
	}

	strcpy(pwn, argv[1]);

	printf("The current pwn setting is '%s', but that should be easy to change.\n", pwn);

	printf("What color are your eyes? ");

	fflush(stdout);

	getline(&line, &len, stdin);
	strtok(line, "\n");

	sprintf(msg, "You have %s eyes.", line);
	puts(msg);
	
	if (strncmp(pwn, "yes", 3) == 0) {
		puts("I'll pwn it for you now!");
		fflush(stdout);

		execve("/bin/sh", NULL, NULL);
	}

	puts("Goodbye!");
}
