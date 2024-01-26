#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * infinite_while - Run an infinite while loop.
 *
 * Return: Always 0.
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - Creates 5 zombie processes.
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t p_id;
	int x = 0;

	while (x < 5)
	{
		p_id = fork();
		if (p_id > 0)
		{
			printf("Zombie process created, PID: %d\n", p_id);
			sleep(1);
			x++;
		}
		else
			exit(0);
	}

	infinite_while();

	return (0);
}
