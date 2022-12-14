#include "main.h"
/**
 * match_function - function that match format with printf format
 * @format: match the format with the function format
 * @arg: list of arguments prinff witll recieve
 * @st_format: array of functions used while printing
 * Return: the number of caracters printed
 */
int match_function(const char *format, va_list arg, st_fmt st_format[])
{
	int i = 0, j, k = 0, done = 0;
	int c = 0;

	for (i = 0; format && format[i] != 0; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			c = c + 1;
		}
		else
		{
			for (j = 0; st_format[j].fmt; j++)
			{
				if (format[i + 1] == st_format[j].fmt[k])
				{
					done = st_format[j].funct(arg);
					c += done;
					i++;
					break;
				}
			}
			if (st_format[j].fmt == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != 0)
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					c = c + 2;
					i++;
				}
				else
					return (-1);
			}
		}
	}
	if (format == NULL)
		return (-1);
	return (c);
}
