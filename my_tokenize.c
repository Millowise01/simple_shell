#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
/**
 * my_tokenize - to input strings into my argu
 * @my_string: the string to be tokenized
 * Return: - to a token pointer array
 */
char **my_tokenize(char *my_string)
{
	char **my_argu;
	int i;
	char *my_token;
	const char *delim = " \n\t\r";

	i = 0;
	my_argu = malloc(sizeof(char *) * 500);

	if (!my_argu)
		return (NULL);
	my_token = strtok(my_string, delim);
	while (my_token)
	{
		my_argu[i] = strdup(my_token);
		if (!my_argu[i])
		{
			if (my_argu)
			{
				for (i = 0; my_argu[i] != NULL; i++)
					free(my_argu[i]);

				free(my_argu);
			}
			return (NULL);
		}
		my_token = strtok(NULL, delim);
		i++;
	}
	my_argu[i] = NULL;
	return (my_argu);
}
