#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * tokenizer - char str, char delim
 * @str: string to be tokenized
 * @delim: delimeter to look for
 * description: function that parses through a string based on a delimeter
 * Return: pointer to an array of strings parsed from string
 */
char **tokenizer(char *str, char *delim)
{
	char **buffer;
	int delim_count = 0, i, token_count;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == *delim)
			delim_count++;
	}

	token_count = delim_count + 1;

	buffer = malloc(sizeof(char *) * (token_count + 1));

	if (buffer == NULL)
		return (NULL);
	i = 0;
	buffer[i] = strtok(str, delim);
	i++;
	while (i < token_count)
	{
		buffer[i] = strtok(NULL, delim);
		i++;
	}
	buffer[i] = NULL;

	return (buffer);
}
/**
 * _strdup - returns pointer to new alloc'd space in mem containing string
 * @str: sting
 *
 * Return: NULL if string is NULL
 */
char *_strdup(char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	ptr = malloc(sizeof(char) * (len + 1));

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < len + 1; i++)
		ptr[i] = str[i];

	return (ptr);
}
/**
 * _strncmp - char *s1, char *s2, size_t n
 * @s1: string one
 * @s2: string two
 * @n: number of bytes
 * description: function that compares the first n bytes of strings s1 and s2
 * Return: int <,=,> if s1 (or the first n bytes thereof) is found,
 * respectively to be greater than s2.
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	int index = 0;

	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2 && index < n)
	{
		s1++;
		s2++;
		index++;

		if (*s1 == *s2)
			return (0);

		else
			return (*s1 - *s2);

	}
}
/**
 * _strlen - char *str
 * @str: string to return length of
 * description: function that calculates the length of str, excluding null byte
 * Return: number of bytes in str
 */
int _strlen(char *str) /*should we change return type to size_t like man page*/
{
	int count;

	for (count = 0; str[count]; count++)
		;
	return (count);
}
/**
 * print_string - char str
 * @str: string to be printed
 * description: function that prints string to std output
 * Return: 1 if successful. Else -1.
 */
int print_string(char *str)
{
	return (write(STDOUT_FILENO, str, strlen(str)));
}
