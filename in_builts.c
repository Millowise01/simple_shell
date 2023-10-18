#include "shell.h"
#include <string.h>

/**
 * BuiltInCommand - to check if command is in builts
 * @cmd: the pointer to a character
 * Return: to 1 if command is in-builts or 0 if fails
 */
int BuiltInCommand(char *cmd)
{
	return (strcmp(cmd, "exit") == 0
	|| strcmp(cmd, "env") == 0);
}

/**
 * to_exit - to be activated when exit command is used
 */
void to_exit(void)
{
	char goodbyeMsg[] = "bye bye You are exiting Shell...\n";

	write(STDOUT_FILENO, goodbyeMsg, sizeof(goodbyeMsg) - 1);
	exit(0);
}

/**
 * print_environment_variables - to show environ variables to the std output
 */
void print_environment_variables(void)
{
	char **var_ptr = environ;

	while (*var_ptr)
	{
		printf("%s\n", *var_ptr);
		var_ptr++;
	}
}
