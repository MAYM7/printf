#include "main.h"
/**
 * _printf - a function like printf.
 * @format: first arg.
 * Return: Always 0.
 **/
int _printf(const char *format, ...)
{
	int ch = 0;
	va_list list;

	if (format == NULL)
		return (-1);
	va_start(list, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
				ch++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				ch++;
			}
			if (*format == 'c')
			{
				char c = va_arg(list, int);

				write(1, &c, 1);
				ch++;
			}
			if (*format == 's')
			{
				char *str = va_arg(list, char*);
				int len = 0; 
					
					while (str[len] != '\0')
						len++;
					write(1, str, len);
					ch += len;
			}
		}
		format++;
	}
	va_end(list);
	return (ch);
}
