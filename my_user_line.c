#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"

#define BUFFER_SIZE 1024
/**
 * my_user_line - to read the user inputs
 * @my_line: it contain the user input
 * @my_line_size: size of the input buffer
 * @my_input: line to read
 * @my_buffer_size: size storing the my_input
 * Return: the number of char to read
 */
ssize_t my_user_line(char *my_input,
		size_t my_buffer_size, char **my_line,
		size_t *my_line_size)
{
	static char buffer[BUFFER_SIZE];
	static size_t my_position, my_size;
	size_t my_new_position, my_length_line, a, b, my_new_size;
	char *my_new_line;

	for (b = 0; b < my_buffer_size && my_input[b] != '\0'; b++)
		buffer[b] = my_input[b];
	my_position = 0;
	my_size = my_buffer_size;
	my_length_line = 0;
	my_new_position = my_position;

	while (my_new_position < my_size && buffer[my_new_position] != '\n')
		my_new_position++;
	my_length_line = my_new_position - my_position;
	my_new_size = my_length_line + 1;
	my_new_line = malloc(my_new_size);

	if (my_new_line == NULL)
		return (-1);

	for (a = 0; a < my_length_line; a++)
	{
		my_new_line[a] = buffer[my_position + a];
	}

	my_new_line[my_length_line] = '\0';
	free(*my_line);

	*my_line = my_new_line;
	*my_line_size = my_new_size - 1;
	my_position = my_new_position + 1;

	return (my_length_line);
}
