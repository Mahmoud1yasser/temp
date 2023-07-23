#include "main.h"

/**
 * init_buf - Fill the buffer with null characters
 *
 * @buffer: The buffer that needs to be initialized
*/

void init_buf(char buffer[])
{
	int i;

	buffer = (char *)malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return;
	i = 0;
	while (i < 1024)
	{
		buffer[i] = 0;
		i++;
	}
	buffer[i] = '\0';
}
