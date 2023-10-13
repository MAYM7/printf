#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int _print_char(va_list args);
int _print_int(va_list args);
int _print_str(va_list args);
int (*_selec_func(char c))(va_list);
int _putchar(char c);

#endif
