#include "hsh.h" 

/** 
 * ch_er - prints an error message 
 * @arg_v: the argument input 
 * Return: print the error message if not return 0 
 */ 

void ch_er(char *arg_v) 
{ 
	char *p = "can't cd to ", l[BUFFER_SIZE],  m[3] = "\n"; 
	char *t = "cd", ptr[BUFFER_SIZE]; 
	int in_count = 1; 
	char *s = my_itoa(in_count, ptr, 10); 

	strcpy(l, arg_v); 
	strcat(l, m); 
	arg_v = l; 
	write(2, "./hsh", 5); 
	write(2, ": ", 2); 
	write(2, s, _strlen(s)); 
	write(2, ": ", 2); 
	write(2, t, _strlen(t)); 
	write(2, ": ", 2); 
	write(2, p, _strlen(p)); 
	write(2, arg_v, _strlen(arg_v)); 
}
