#include "main.h"
/**
 * get_width - Calculate width for printing.
 * @format: Formatted string.
 * @i: Argument list index.
 * @list: Argument list.
 * 
 * This function calculates the width for formatting based on the
 * provided format string and argument list.
 *
 * Return: Width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			/* Accumulate digits to calculate width.*/
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{/* Handle width specified as an argument.*/
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
		{
			/* Stop processing when a non-digit or non-'*' is encountered.*/
			break;
		}
	}
	*i = curr_i - 1;

	return (width);
}
