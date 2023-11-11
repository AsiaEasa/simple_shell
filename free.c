nclude "hsh.h" 
/** 
 * free_all - free memory 
 * @arg: Arguments passed to the shell program. 
 */ 

void free_all(char **arg) 
{int i; 
	if (arg == NULL) 
		return; 
	for (i = 0; arg[i] != NULL; i++) 
		free(arg[i]); 
	free(arg); 
}
