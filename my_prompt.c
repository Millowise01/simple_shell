#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
/**
 * display_custom_signal - to handle my custom signal
 * @my_signal_number: the signal number
 */
void display_custom_signal(int my_signal_number)
{
	(void)my_signal_number;
	write(STDOUT_FILENO, "\n$ ", 10);
}

/**
 * display_custom_prompt - to show shell prompt and set signal handler
 */
void display_custom_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "# ", 2);
}
