#include "shell_header.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - void
 * description: simple UNIX command interface
 * Return: 0 if successful
 */
int main(void)
{
	char **tokens = NULL;
	size_t buffSize = 0;
	char *cpyBuff = NULL;
	char *buffer = NULL;


	while (1)
	{
		prompt();
		if (getline(&buffer, &buffSize, stdin) == -1)
			break; /*need to write error message*/
		cpyBuff = _strdup(buffer);
		tokens = tokenizer(cpyBuff, "\n");
		fork_proc(tokens);
	}
	free(buffer);
	return (0);
}
