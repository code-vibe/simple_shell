#include "main.h"
/**
 * sigintH - handles SIGINT (CTRL + C)
 * @signum: signal number caught by signal, 2 for SIGINIT
 * Return: void
 **/

void sigintH(int signum)
{
	if (signum == SIGINT)
	{
		write(2, "\n#Shell_CL$ ", 11);
	}
}

/**
 * _getenv - Search in environment variable to find a specific variable name
 * @name: environment variable
 * Return: pointer to the corresponding value string
 */

char *_getenv(char *name)
{
        int i = 0;

        while (environ[i])
        {
                if (strcmp(environ[i], name) == 0)
                        return (environ[i]);

                ++i;
        }
        return (NULL);
}
