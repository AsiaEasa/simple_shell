#include "hsh.h" 
/** 
 * handle_exit - handles the 'exit' buil-in command 
 * @exit_args: Arrguments for the exit command. 
 * Return: Nothing 
 */ 
int handle_exit(char **exit_args) 
{ int status; 
	if (exit_args[1]) 
	{ 
		if ((exit_args[1][0] == '-') || 
				(exit_args[1][0] >= 'a' && exit_args[1][0] <= 'z') || 
				(exit_args[1][0] >= 'A' && exit_args[1][0] <= 'Z')) 
		{ error_exit(exit_args[1]); 
			return(2); } 
		else 
		{ status = _atoi(exit_args[1]); 
			return(status); }} 
	return(0); 
} 

/** 
 * _atoi - convert a string into an integer. 
 * @s: the string to use. 
 * Return: integer. 
 */ 

int _atoi(char *s) 
{ 
	int sign = 1, i = 0; 
	unsigned int res = 0; 

	while (!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0') 
	{ 
		if (s[i] == '-') 
			sign *= -1; 
		i++;        } 
	while (s[i] <= '9' && (s[i] >= '0' && s[i] != '\0')) 
	{ 
		res = (res * 10) + (s[i] - '0'); 
		i++; 
	} 
	res *= sign; 
	return (res); 
}
