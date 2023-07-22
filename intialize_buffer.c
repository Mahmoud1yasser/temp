#include "holberton.h"

/**
 * initialize_buffer - Fill the buffer with null characters for
 *
 * @buffer: The buffer that needs to be initialized of type char
 *
 * Return : 0 success
*/

void initialize_buffer(char buffer[])
{
	int i;

	i = 0;
	while (i < 1024)
	{
		buffer[i] = 0;
		i++;
	}
	buffer[i] = '\0';
}
