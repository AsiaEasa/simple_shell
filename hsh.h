#ifndef HSH_H
#define HSH_H
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stddef.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
void ch_er(char *arg_v);
int cd(char **arg);
char *in_env(char *in_env);
void error_exit(char *arg_v);
void error(char *arg_v);
void reverse(char str[], int length);
char *my_itoa(int num, char str[], int base);
void _puts(char *str);
int _strncmp(char *str1, char *str2, int n);
int _putchar(char c);
char *_read(void);
void free_all(char **arg);
int check(char **arg);
int _strcmp(char *s1, char *s2);
char *get_line(void);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
int my_fork(char **arg);
int handle_exit(char **exit_args);
extern char **environ;
int envi(void);
void print_env(char *str);
char **str_tok(char *line);
void interactive(void);
void none_interactive(void);
int main(void);
#endif
