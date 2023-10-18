#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>
#include "shell.h"

#define BUFFER_SIZE 1024
/**
 * main - the main entry to the shell
 * @arguputs: the length of argu
 * @argv_input: the array of argu
 * Return: to 0 if successful
 */
int main(int arguputs, char **argv_input)
{
	char **argu_input = argv_input;
	ssize_t stats;
	char *buffer_input = NULL;
	size_t size;
	int i;

	while (1)
	{
		display_custom_prompt();
		stats = getline(&buffer_input, &size, stdin);
		if (stats == -1)
		{
			free(buffer_input);
			exit(0);
		}
		argu_input = my_tokenize(buffer_input);
		if (argu_input == NULL)
			continue;
		exe_in_command(argu_input[0], argu_input);
		for (i = 0; argu_input[i] != NULL; i++)
			free(argu_input[i]);
		free(argu_input);
		free(buffer_input);
		size = 0;
		buffer_input = NULL;
	}
	if (argu_input)
	{
		for (i = 0; argu_input[i] != NULL; i++)
		{
			free(argu_input[i]);
		}
		free(argu_input);
	}
	return (0); /*/ To remove unnecessary argu++ */
	arguputs++;
}
