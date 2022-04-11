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
