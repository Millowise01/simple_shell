#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * exe_in_command - to check if first element of array is NULL
 * @my_argu: it point to a argu
 * @my_argu_array: it contain the argument
 * Return: to 1 if SUCCESSFUL
 */
int exe_in_command(char *my_argu, char **my_argu_array)
{
	char *command_path, *command;
	pid_t processID;
	int stats;

	if (!my_argu_array[0])
		return (0);
	command = my_argu_array[0];
	if (strcmp(command, "env") == 0)

		/*to print the environment*/
		print_environment_variables();
	else if (strcmp(command, "exit") == 0)
	{
		to_exit();
	}
	else
	{
		command_path = to_find_location(command);
		if (!command_path)
		{
			fprintf(stderr, "%s: No such file\n", my_argu);
			return (0);
		}
		processID = fork();
		if (processID == -1)
			perror("Error");
		else if (processID == 0)
		{
			if (execve(command_path, my_argu_array, NULL) == -1)
			{
				perror("Error");
				exit(0);
			}
		}
		else if (wait(&stats) == -1)
			perror("Error");
		free(command_path);
	}
	return (0);
}

