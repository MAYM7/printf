#include "main.h"
void printb(char buffer[], int *buff_ind);
/**
 * _printf - a function like printf.
 * @format: first arg.
 * Return: Always 0.
 **/
int _printf(const char *format, ...)
{
	int i, ch = 0, pch = 0;
	int flags, wid, pre, size, index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[index++] = format[i];
			if (index == BUFF_SIZE)
				printb(buffer, &index);
			ch++;
		}
		else
		{
			printb(buffer, &index);
			flags = _flags(format, &i);
			wid = _wid(format, &i, list);
			pre = _pre(format, &i, list);
			size = _size(format, &i);
			i++;
			pch = printh(format, &i, list, buffer,
					flags, wid, pre, size);
			if (pch == -1)
				return (-1);
			ch += pch;
		}
	}
	printb(buffer, &index);
	va_end(list);
	return (ch);
}

/**
 * printb - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 **/
void printb(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
