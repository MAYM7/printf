#include "main.h"

/**
 * printb - Prints the contents of the buffer if it exist.
 * @buffer: char array.
 * @buff_ind: index at which to add next char.
 * Return: Printed chars.
 */

void printb(char buffer[], int *buff_ind)
{
        if (*buff_ind > 0)
                write(q, &buffer[0], *buff_ind);
        *buff_ind = 0;
}

