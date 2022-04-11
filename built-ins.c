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
/**
 * hsh_env - Function that print enviromental
 *
 * @args: arguments
 * @input_stdin: input of stdin
 *
 * Return: Always 1 (success)
 */

int hsh_env(char **args __attribute__((unused)),
		char *input_stdin __attribute__((unused)))
{
	int i = 0;

	if (environ[i] == NULL)
	{
		printf("%s", "The built in env is empty");
		return (1);
	}
	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);

	return (1);
}
