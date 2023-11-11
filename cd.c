#include "hsh.h" 
/** 
 * cd - change directory 
 * @arg: input argement 
 */ 

int cd(char **arg) 
{ 
	char cd[1024]; 
	char *path; 

	path = arg[1]; 

	if (path == NULL) 
	{ 

		char *home = in_env("HOME"); 

		chdir(home); } 

	else if (_strcmp(path, "-") == 0) 
	{ 
		char *oldpwd = in_env("OLDPWD"); 

		if (oldpwd == NULL) 
			return(-1); 
		_puts(oldpwd); 
		_putchar('\n'); 
		if (chdir(oldpwd) == -1) 
			perror("chdir"); 
	} else 
	{ 
		if (chdir(path) == -1) 
			ch_er(path); } 
	if (in_env("PWD") != NULL) 
		putenv("PWD"); 
	if (getcwd(cd, sizeof(cd)) != NULL) 
		setenv("PWD", cd, 1); 
	return(-1); 
}
