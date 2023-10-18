#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stddef.h>

#define BUFSIZE 1024
char **input_parser_line(char *inputLine);
int exe_in_command(char *args, char **args_array);
char *to_find_location(const char *command);
void display_custom_prompt(void);
void display_custom_signal(int my_signal_number);
int BuiltInCommand(char *cmd);
void to_exit(void);
void print_environment_variables(void);
extern char **environ;
ssize_t my_user_line(char *my_input,
		size_t my_buffer_size, char **my_line,
		size_t *my_line_size);
char **my_tokenize(char *my_string);

#endif
