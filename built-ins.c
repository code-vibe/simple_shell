#include "main.h"

/**
 * hsh_exit - Function exit built in
 *
 * @args: arguments
 * @input_stdin: input of stdin
 * @exit_status: exit status
 * Return: Exit success
 */

int hsh_exit(char **args, char *input_stdin, int *exit_status)
{
	int output_exit = 0;

	(void)args;
	(void)input_stdin;
	(void)exit_status;

	if (args[1] == NULL)
	{
		free(args);
		free(input_stdin);
		exit(*exit_status);
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
 * @exit_status: exit status
 *
 * Return: Always 1 (success)
 */

int hsh_env(char **args, char *input_stdin, int *exit_status)
{
	int i = 0;

	(void)args;
	(void)input_stdin;
	(void)exit_status;


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
 * hsh_cd - change directory
 * @args: argument array
 * @input_stdin: input of stdin
 * @exit_status: exit status
 * Return: 1 (success)
 */
int hsh_cd(char **args, char *input_stdin, int *exit_status)
{
	int stat;
	char s[128];

	getcwd(s, sizeof(s));

	(void)input_stdin;
	(void)exit_status;

	if (args[1] == NULL)
		stat = chdir(getenv("HOME"));
	else if (strcmp(args[1], "-") == 0)
		stat = chdir(getenv("OLDPWD"));
	else if (strcmp(args[1], "~") == 0)
		stat = chdir(getenv("HOME"));
	else
		stat = chdir(args[1]);

	if (stat == -1)
		perror("cd had an error");

	setenv("OLDPWD", s, 1);
	setenv("PWD", getcwd(s, sizeof(s)), 1);
	return (1);
}
/**
 * built_setenv - Command to set or overwrite a env variable.
 * @args: argument array
 * @input_stdin: input of stdin
 * @exit_status: exit status
 * Return: Return 1 if use a function, 0 otherwise.
 */

int hsh_setenv(char **args,  char *input_stdin, int *exit_status)
{
	int n_tokens = 0;

	(void)input_stdin;
	(void)exit_status;

	while (args[n_tokens] != NULL)
	{
		n_tokens++;
	}

	if (n_tokens == 3)
		setenv(args[1], args[2], 1);
	else if (n_tokens < 3)
		fprintf(stderr, "Try use \"setenv [KEY] [VALUE]\"\n");
	else
		fprintf(stderr, "Try use \"setenv [KEY] [VALUE]\"\n");

	return (1);
}
/**
 * built_unsetenv - Command of the simple shell eliminate a env var.
 * @args: argument array
 * @input_stdin: input of stdin
 * @exit_status: exit status
 * Return: Return 1 if use a function, 0 otherwise.
 */

int hsh_unsetenv(char **args,  char *input_stdin, int *exit_status)
{
	int n_tokens = 0;

	(void)input_stdin;
	(void)exit_status;

	while (args[n_tokens] != NULL)
        {
                n_tokens++;
        }
	
	if (n_tokens == 2)
		unsetenv(args[1]);
	else
		fprintf(stderr, "Try use \"unsetenv [KEY]\"\n");

	return (1);
}
/**
 * hsh_execute_builtins - Function that execute a
 * correct builtin command
 * @args: arguments
 * @input_stdin: input of stdin
 * @argv: argv
 * @exit_status: exit status
 *
 * Return: execute function of choose builtin
 * or return hsh_execute
 */

int hsh_execute_builtins(char **args, char *input_stdin, char **argv,
		int *exit_status)
{
	int i = 0;

	choose_builtins_t options[] = {
		{"exit", hsh_exit},
		{"env", hsh_env},
		{"cd", hsh_cd},
		{"setenv", hsh_setenv},
		{"unsetenv", hsh_unsetenv},
		{NULL, NULL}
	};

	while (options[i].name_builtin)
	{
		if (strcmp(options[i].name_builtin, args[0]) == 0)
		{
			return ((int)((*options[i].func_builtin)(args, input_stdin, exit_status)));
		}
		i++;
	}
	return (hsh_execute(args, argv, exit_status));

}
