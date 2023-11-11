#include "hsh.h" 
/** 
 * get_line - read a line from stdin 
 * 
 * Return: pointer that points to a str with the line content 
 */ 
char *get_line(void) 
{ 
	static char buffer[BUFFER_SIZE]; 
	static int buffer_index; 
	static int buffer_size; 
	char *temp; 
	char *line = NULL; 
	int line_index = 0; 
	char current_char; 

	while (1) 
	{ 
		if (buffer_index >= buffer_size) 
		{buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE); 
			buffer_index = 0; 
			if (buffer_size <= 0) 
			{ 
				if (line_index == 0) 
					return (NULL); 
				break; } } 
		current_char = buffer[buffer_index++]; 
		if (current_char == '\n') 
			break; 
		temp = malloc((line_index + 1) * sizeof(char)); 
		if (temp == NULL) 
		{free(line); 
			return (NULL); } 
		memcpy(temp, line, line_index * sizeof(char)); 
		temp[line_index++] = current_char; 
		free(line); 
		line = temp; } 
	if (line != NULL) 
	{char *temp = malloc((line_index + 1) * sizeof(char)); 
		if (temp == NULL) 
		{free(line); 
			return (NULL); } 
		memcpy(temp, line, line_index * sizeof(char)); 
		temp[line_index] = '\0'; 
		free(line); 
		line = temp; } 
	return (line); }
