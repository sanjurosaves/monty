#include "monty.h"

/**
 * vread - variadic read function to enable vsscanf
 * @fmt: variadic format
 * @buffer: line to process
 * Return: number of words read
 */
int vread(const char *buffer, char *fmt, ...)
{
	int rc;
	va_list arg_ptr;

	va_start(arg_ptr, fmt);
	rc = vsscanf(buffer, fmt, arg_ptr);
	va_end(arg_ptr);
	return (rc);
}
