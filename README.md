# ft_printf

Reimplementation of the printf function from the C standard library. The ft_printf function should support the following conversions: %, c, s, p, i, d, u, x, X.

## About the project

The ft_printf project provides a deep dive into the workings of the printf function, with a particular emphasis on variadic functions and character manipulation.

Variadic functions are capable of accepting a variable number of arguments, eliminating the need to specify a fixed number of parameters. These arguments are passed within functions using various techniques.

The ft_printf function utilizes a format string, which outlines the desired formatting of the output. This format string contains specifiers such as %s, %d, %c. The format string is parsed, and these specifiers are extracted to handle the corresponding arguments. For instance, if %s is the format specifier, it formats a string argument.

#### Supported format specifiers ####
- %%: Outputs a literal "%" character
- %c: Outputs a single character
- %s: Outputs a character string
- %p: Outputs a pointer's value (address)
- %i: Outputs an integer in base 10
- %d: Outputs a decimal number in base 10
- %u: Outputs an unsigned decimal number in base 10
- %x: Outputs a hexadecimal number in lowercase format (base 16)
- %X: Outputs a hexadecimal number in uppercase format (base 16)

Upon execution, ft_printf outputs the formatted string and returns the count of characters printed.

## Running the project

To run the project, first clone the repository and navigate into the project directory. Then, use the 	`make` command to compile the project.

This is not a program, therefore, it needs another file to be compiled with. I wrote a file [`main.c`](main.c) to be able to test the ft_printf and compare it with the actual printf.

To compile and run the program, follow these steps:

```bash
make
gcc main.c libftprintf.a
./a.out
```