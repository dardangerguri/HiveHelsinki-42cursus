# ft_printf
Recreate the C library printf function. Conversions that should be implemented in ft_printf are: %, c, s, p, i, d, u, x, X.
## About the project

The ft_printf is a project at Hive Helsinki (42 School) that helps us understand how printf works and helps us devlop a strong understanding of variadic functions, and character manipulation.

Variadic functions can accept a variable number of arguments, without having to specify a fixed number of parameters. These arguments are passed within functions using different techniques.

So, ft_printf takes a format string, which specifies how the output should be formatted. It contains format specifiers like %s, %d, %c.
The format string is parsed and these specifiers are extracted to then handle the arguments. If %s is the format specifier, it formats a string argument.

#### Format specifiers that ft_printf handels ####
- %%: prints a literal "%" character
- %c: writes a single character
- %s: writes a character string
- %p: writes pointer's value (address)
- %i: writes an integer in base 10
- %d: writes a decimal in (base 10) number
- %u: writes an unsigned decimal (base 10) number
- %x: writes a hexadecimal (base 16) lowercase format
- %X: writes a hexadecimal (base 16) uppercase format

In the end, ft_printf prints the formatted output and returns the number of characters printed. 

## Using this get_next_line function
`make` for it to create the libftprintf.a library! 
This is not a program, therefore, it needs another file to be compiled with. I wrote a file [main.c](`main.c`) to be able to test the ft_printf and compare it with the actual printf.

So, first you have to:
```bash
make
```
Then, the main.c and libftprintf.a shold be compiled together:
```bash
gcc main.c libftprintf.a
```
and run the program:
```bash
./a.out
```

## Testing
### Third-party tester
I tested the library with this third-party tester: 
* [printfTester](https://github.com/Tripouille/printfTester)
