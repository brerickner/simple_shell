#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void fork_proc(char **tokens);
void prompt(void);
char **tokenizer(char *str, char *delim);
int _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *str);
int print_string(char *str);
int _strncmp(char *s1, char *s2, size_t n);
char *_strdup(char *str);

#endif /* HEADER_H */
