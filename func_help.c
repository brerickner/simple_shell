#include "shell_header.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * fork_proc - char tokens
 * @tokens: arguments passed in to command lin
 * description: function that creates a child process
 * Return: void
 */
void fork_proc(char **tokens)
{
	pid_t child = fork();
	int status;

	if  (child == -1)
		exit(-1);/*failed forking child*/
	if (child == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
			exit(3); /*unable to read*/
	}
	else
		child = wait(&status);
}
/**
 * prompt - void
 * description: function that fork a child proccess
 * Return: void
 */
void prompt(void)
{
	char *prompt = "$ ";

	print_string(prompt);
}
/**
 * tokenizer - char str, char delim
 * @str: string to parse
 * @delim: delimeter to look for when parsing string
 * description: parses through a string and returns array of strings as
 * tokens
 * Return: pointer to an array of strings parsed from string
 */
char **tokenizer(char *str, char *delim)
{
	char **holder;
	int delim_count = 0, index, token_count;

	for (index = 0; str[index]; index++)
	{
		if (str[index] == *delim)
			delim_count++;
	}

	token_count = delim_count + 1;

	holder = malloc(sizeof(char *) * (token_count + 1));

	if (holder == NULL)
		return (NULL);

	index = 0;
	holder[index] = strtok(str, delim);
	index++;

	while (index < token_count)
	{
		holder[index] = strtok(NULL, delim);
		index++;
	}
	holder[index] = NULL;
/*	free(holder[index]);*/
/*	free(holder);*/
	return (holder);
}
