#include "main.h"
/**
 * get_size - Computes the size to cast the argument
 * @format: Formatted string used to print the arguments
 * @i: Pointer to an index in the format string
 *
 * This function calculates the size to cast the argument based on the format
 * specifier in the format string.
 *
 * Return: The size specifier (S_LONG or S_SHORT) for casting the argument.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1; // Increment the index to check the next character
	int size = 0; // Initialize the size to zero

	// Check if the next character in the format string is 'l' (long) or 'h' (short)
	if (format[curr_i] == 'l') 
		size = S_LONG; // Set size to S_LONG if 'l' is found
	else if (format[curr_i] == 'h') 
		size = S_SHORT; // Set size to S_SHORT if 'h' is found
	// Update the index *i to the current position or the previous position
	if (size == 0) 
		*i = curr_i - 1; // If no size specifier is found, set the index to the previous position
	else
		*i = curr_i; // If a size specifier is found, set the index to the current position
		return (size); // Return the determined size specifier
}
