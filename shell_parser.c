#include "shell.h"
#include <string.h>

/**
 * input_parser_line - the parser line into an array argu.
 * @inputLine: The input line
 * Return: to an array of argu or NULL if it fails
 */
char **input_parser_line(char *inputLine)
{
	const char my_delimiter[] = "\t\n";
	char **args = malloc(BUFSIZE * sizeof(char *));
	char *my_token;
	int index = 0;

	if (!args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	my_token = strtok(inputLine, my_delimiter);
	while (my_token != NULL)
	{
		args[index] = strdup(my_token);
		if (!args[index])
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		my_token = strtok(NULL, my_delimiter);
		index++;
	}
	args[index] = NULL;
	return (args);
}


