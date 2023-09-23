#include "main.h"

/**
 * get_precision - Computes the precision for printing
 * @format: Formatted string used in print the arguments
 * @i: Pointer to an index in the format string
 * @list: Record of arguments to be printed
 *
 * This function calculates the precision for printing based on the format
 * specifier in the format string.
 *
 * Return: The calculated precision value.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;
    /*Check if the next character in the format string is '.'*/  
	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
    /*Update the index *i to the current position or the previous position*/
	*i = curr_i - 1;

	return (precision);
}
