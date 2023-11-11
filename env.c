#include "hsh.h" 

/** 
 * envi -handles the env built-in command 
 *Return: Nothing 
 */ 

int envi(void) 
{ char **ptr; 

	ptr = environ; 

	while (*ptr) 
	{ 
		print_env(*ptr); 
		print_env("\n"); 
		ptr++; } 
	return (-1);  } 

	/** 
	 * print_env - print all environmen 
	 * @str: point to environment 
	 * Return: Nothing. 
	 */ 

void print_env(char *str) 
{ 
	while (*str) 
	{ 
		write(1, str, 1); 
		str++; 
	} 
} 
/** 
 *in_env - gets the value of a speficied environment variable 
 * @in_env: Variable to look for in environment 
 * Return: Pointer to start index of the value. 
 */ 

char *in_env(char *in_env) 
{ 
	char **ptr = environ; 
	int len = _strlen(in_env); 

	while (*ptr) 
	{ 

		if (_strncmp(*ptr, in_env, len) == 0 && (*ptr)[len] == '=') 
		{ 
			return (&((*ptr)[len + 1])); 
		} 
		ptr++; 
	} 
	return (NULL); 
}
