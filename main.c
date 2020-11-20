#include "shell_header.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int main(void)
{
	char **tokens = NULL;
	size_t buffSize = 0;
	char *cpyBuff = NULL;
	char *buffer = NULL;

	while(1)
	{
		prompt();
		if (getline(&buffer, &buffSize, stdin) == -1)
			break; /*need to write error message*/
		cpyBuff = _strdup(buffer);
		tokens = tokenizer(cpyBuff,"\n");
		if (execve(tokens[0], tokens, NULL) == -1)
			break; /*needs error message*/
	}
	free(buffer);
	return (0);
}
