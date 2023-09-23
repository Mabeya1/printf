#include "main.h"

/**
 * is_printable – Assesses if a char is printable
 * @c: Char to be assessed.
 *
 * Return: 1 if c is printable, 0 if it is not
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ASCII in hexadecimal code to buffer
 * @i: Index at which to start appending.
 * @buffer: Array of chars
 * @ascii_code: ASCII CODE.
 *
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/*The hexa format code is always two digits long*/
	if (ascii_code < 0)
		ascii_code *= -1;
        /*Add the escape character*/
	buffer[i++] = '\\';
	buffer[i++] = 'x';
        /*Add the two hexadecimal digits*/
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3) ;
}

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be assessed
 *
 * Return: 1 if c is a digit, 0 if it is not
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to the specified size
 * @num: Number that should be casted.
 * @size: Number indicating the type for casting
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be assessed
 *
 * Return: 1 if c is a digit, 0 if it is not
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
