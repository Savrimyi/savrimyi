#include <string.h>
#include <stdio.h>

int compare(char * a, char * b)
{
	return a == b;
}

void main(int argc, char ** argv)
{
	FILE * flag_file = fopen("./flag", "r");

	char * flag = NULL;
	size_t m = 0;
	getline(&flag, &m, flag_file);

	char * attempt = NULL;
	size_t n = 0;
	getline(&attempt, &n, stdin);

	if (compare(attempt, flag)) {
		printf(flag);
	} else {
		printf(attempt);
	}
}
