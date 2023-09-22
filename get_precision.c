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
	int curr_i = *i + 1; // Increment the index to check the next character
	int precision = -1; // Initialize precision to -1

	// Check if the next character in the format string is '.'
	if (format[curr_i] != '.')
		return (precision); // If not, return -1 as precision is not specified

	precision = 0; // Reset precision to 0

	// Loop through characters in the format string to calculate precision
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0'; // Convert digit characters to an integer
		}
		else if (format[curr_i] == '*')
		{
			curr_i++; /* Move to the next character to read the dynamic precision from va_list*/
			precision = va_arg(list, int); // Read the precision from the va_list
			break;
		}
		else
			break; // Stop if a non-digit or non-'*' character is encountered
	}

	*i = curr_i - 1; // Update the index *i to the current position or the previous position

	return (precision); // Return the calculated precision value
}
