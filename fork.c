#include "hsh.h" 

/** 
 * my_fork -handles the fork 
 * Return: Nothing If successful or error if it fails. 
 * @arg: Arguments passed to the shell program. 
 */ 
int my_fork(char **arg) 
{ 
	pid_t child_ID, wpid; 
	int ID_status; 

	child_ID = fork(); 
	if (child_ID ==  0) 
	{ 
		if (execvp(arg[0], arg) == -1) 
		{ error(arg[0]); 
			return(127); 
		} 
	} 
	else if (child_ID< 0) 
		perror("Error forking process"); 

	else 
		wpid = waitpid(child_ID, &ID_status, 0); 

	if (wpid != -1) 
		if (WIFEXITED(ID_status)) { 
			int exit_status = WEXITSTATUS(ID_status); 

			if (exit_status == 2) 
				return(2); 
			else if (exit_status == 127)  
				return(127); } 
	return (-1); 
}
