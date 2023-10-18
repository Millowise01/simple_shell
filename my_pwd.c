#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * to_find_location - the main path to the command
 * @command: the command
 * Return: to full path
 */
char *to_find_location(const char *command)
{
	char *my_token;
	int my_lenght;
	char *my_path_env;
	char *my_pathway;
	char *my_fullpath;
	const char *my_delim = ":";

	if (strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));
		return (NULL);
	}

	my_path_env = getenv("MYPATH");
	if (!my_path_env)
		return (NULL);
	my_pathway = strdup(my_path_env);
	my_token = strtok(my_pathway, my_delim);

	while (my_token)
	{
		my_lenght = strlen(my_token) + strlen(command) + 2;
		my_fullpath = malloc(sizeof(char) * my_lenght);
		if (!my_fullpath)
		{
			free(my_pathway);
			return (NULL);
		}
		sprintf(my_fullpath, "%s/%s", my_token, command);
		if (access(my_fullpath, F_OK) == 0)
		{
			free(my_pathway);
			return (my_fullpath);
		}
		free(my_fullpath);
		my_token = strtok(NULL, my_delim);
	}
	free(my_pathway);
	return (NULL);
}
