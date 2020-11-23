#include "shell_header.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * print_string - char str
 * @str: string to print
 * description: function that prints string to std output
 * Return: string to std out
 */
int print_string(char *str)
{
	return (write(STDOUT_FILENO, str, strlen(str)));
}
/**
 * _strdup - char str
 * @str: sting
 * description: alloc'd space in mem then duplicates string into it
 * Return: pointer to newly alloct'd space in mem. Else NULL
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
	size_t index = 0;

	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2 && index < n)
	{
		s1++;
		s2++;
		index++;

		if (*s1 == *s2)
			return (0);

	}
	return (*s1 - *s2);
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
