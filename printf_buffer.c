#include "main.h"
/**
 * print_buffer - prints the contents of a buffer
 * @buffer: Array of characters
 * @bufferIndex: length of buffer
 */
void print_buffer(char buffer[], int *bufferIndex)
{
	if (*bufferIndex > 0)
		write(1, &buffer[0], *bufferIndex);

	*bufferIndex = 0;
}
