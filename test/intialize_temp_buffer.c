#include "main.h"

/**
 * init_buf - buffer filled by null characters
 * @buffer: The buffer that needs to be initialized
 */
void init_buf(char buffer[])
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
