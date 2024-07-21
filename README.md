# _printf Implementation
==========================

This implementation of the `_printf` function is a custom version of the standard `printf` function in C. It takes a format string and a variable number of arguments, and prints the formatted string to the standard output.

## Includes
The implementation includes the following header files:

* `<stdio.h>` for input/output operations
* `<unistd.h>` for the `write` function
* `"main.h"` for custom function declarations
* `<stdarg.h>` for variable argument handling
* `<limits.h>` for integer limits

## Functions
The implementation consists of two functions: `print_int` and `_printf`.

### `print_int` Function
The `print_int` function takes an integer as an argument and prints it to the standard output. It handles the cases for `INT_MIN` and `INT_MAX` separately, and uses the `write` function to print the digits of the integer.

### `_printf` Function
The `_printf` function takes a format string and a variable number of arguments, and prints the formatted string to the standard output. It uses the `va_list` type to handle the variable arguments, and the `write` function to print the characters to the standard output.

The function iterates through the format string, and for each format specifier, it calls the corresponding function to print the argument. The format specifiers supported are:

* `%c` for printing a single character
* `%s` for printing a string
* `%d` or `%i` for printing an integer
* `%%` for printing a percentage sign

## Implementation Details
The implementation uses the `write` function to print characters to the standard output, which allows for more control over the output. The `print_int` function is used to print integers, and the `_printf` function is used to print the formatted string.

The implementation also handles the cases for `INT_MIN` and `INT_MAX` separately, and uses the `va_list` type to handle the variable arguments.
