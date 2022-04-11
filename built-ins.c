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
	int output_exit = 0;

	if (args[1] == NULL)
	{
		free(args);
		free(input_stdin);
		exit(0);
	}
	if (args[2] != NULL)
	{
		fprintf(stderr, "exit: too many arguments\n");
		return (0);
	}
	output_exit = atoi(args[1]);
	free(args);
	free(input_stdin);
	exit(output_exit);
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
/**
 * hsh_execute_builtins - Function that execute a
 * correct builtin command
 *
 * @args: arguments
 * @input_stdin: input of stdin
 * @argv: argv
 *
 * Return: execute function of choose builtin
 * or return hsh_execute
 */

int hsh_execute_builtins(char **args, char *input_stdin, char **argv)
{
	int i = 0;

	choose_builtins_t options[] = {
		{"exit", hsh_exit},
		{"env", hsh_env},
		{NULL, NULL}
	};

	while (options[i].name_builtin)
	{
		if (strcmp(options[i].name_builtin, args[0]) == 0)
		{
			return ((int)((*options[i].func_builtin)(args, input_stdin)));
		}
		i++;
	}
	return (hsh_execute(args, argv));

}
