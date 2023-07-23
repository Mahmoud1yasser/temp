#include <unistd.h>
#include "main.h"

/**
 * write_buf - Print out the buffer of all characters to print
 * @buffer: The buffer with the string needed to print
 * @buflen: Pointer to the length of buffer
 * @bufpos: Pointer to the postion inside buffer
 */
void write_buf(char *buffer, int *len, int *pos)
{
	write(1, buffer, *len - 1);
	*pos = 0;
	*len = 1;
}
