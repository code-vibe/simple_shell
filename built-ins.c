#include "main.h"

/**
 * hsh_exit - Function exit built in
 *
 * @args: arguments
 * @input_stdin: input of stdin
 * Return: Exit success
 */

int hsh_exit(char **args __attribute__((unused)),
		char *input_stdin __attribute__((unused)))
{
	free(args);
	free(input_stdin);
	exit(EXIT_SUCCESS);
}
