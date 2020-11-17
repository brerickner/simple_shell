#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H

#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *str); /*should we change return type to size_t like man page*/
int print_string(char *str);

#endif /* HEADER_H */
