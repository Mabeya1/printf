#include "main.h"

/**
 * handle_print - Prints an argument depending on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: Index to track the present position in fmt.
 * @buffer: Buffer array to handle print.
 * @flags: Computes active flags
 * @width: Specifies width
 * @precision: Specifies precision
 * @size: Specifies size
 *
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	// Loop through the format type array to find a matching format specifier
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			// Call the corresponding print function for the matched specifier
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
		
	   
	// If no matching specifier is found, handle it as a literal character
	if (fmt_types[i].fmt == '\0')
              {
		if (fmt[*ind] == '\0');
			return (-1); // End of format string
		
		unknow_len += write(1, "%%", 1); // Print '%'
		
		// Check for space character or width specification
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
                           {
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1); // Return 1 to indicate a successful print
		}
		
		unknow_len += write(1, &fmt[*ind], 1); // Print the unknown character
		return (unknow_len);
	}

	return (printed_chars);
}
