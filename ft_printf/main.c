#include <stdio.h>
#include <limits.h>
#include "includes/ft_printf.h"

#define RESET "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"

void	test_percent_specifier(void)
{
	int	printf_length = 0;
	int	ft_printf_length = 0;

	printf(RED "\n----------- TEST: percent -----------\n\n" RESET);
	printf(BLUE "Testing:(\"%%%%\")\n" RESET);
	printf_length += printf("Real: %%\n");
	ft_printf_length += ft_printf("Mine: %%\n");
	printf(GREEN "\nLength: printf = %d, ft_printf = %d\n\n", printf_length, ft_printf_length);

}

void	test_c_specifier(void)
{
	int	printf_length = 0;
	int	ft_printf_length = 0;

	printf(RED "\n----------- TEST: %%c -----------\n\n" RESET);
	printf(BLUE "Testing:(\"%%c\", \'p\')\n" RESET);
	printf_length += printf("Real: %c\n", 'p');
	ft_printf_length += ft_printf("Mine: %c\n", 'p');
	printf(BLUE "Testing:(\"Printing character: %%c.\", \'x\')\n" RESET);
	printf_length += printf("Real: Printing character: %c.\n", 'x');
	ft_printf_length += ft_printf("Mine: Printing character: %c.\n", 'x');
	printf(GREEN "\nLength: printf = %d, ft_printf = %d\n\n" RESET, printf_length, ft_printf_length);
}

void	test_s_specifier(void)
{
	int	printf_length = 0;
	int	ft_printf_length = 0;

	printf(RED "\n----------- TEST: %%s -----------\n\n" RESET);
	printf(BLUE "Testing:(\"Printing string: %%s.\", \"Hello!\")\n" RESET);
	printf_length += printf("Real: Printing string: %s.\n", "Hello!");
	ft_printf_length += ft_printf("Mine: Printing string: %s.\n", "Hello!");
	printf(BLUE "Testing:(\"NULL string: %%s.\", NULL)\n" RESET);
	printf_length += printf("Real: NULL string: %s.\n", NULL);
	ft_printf_length += ft_printf("Mine: NULL string: %s.\n", NULL);
	printf(GREEN "\nLength: printf = %d, ft_printf = %d\n\n" RESET, printf_length, ft_printf_length);
}

void	test_d_specifier(void)
{
	int	printf_length = 0;
	int	ft_printf_length = 0;

	printf(RED "\n----------- TEST: %%d -----------\n\n" RESET);
	printf(BLUE "Testing:(\"Number: %%d.\", 42)\n" RESET);
	printf_length += printf("Real: Number: %d.\n", 42);
	ft_printf_length += ft_printf("Mine: Number: %d.\n", 42);
	printf(BLUE "Testing:(\"INT_MAX Number: %%d.\", INT_MAX)\n" RESET);
	printf_length += printf("Real: INT_MAX Number: %d.\n", INT_MAX);
	ft_printf_length += ft_printf("Mine: INT_MAX Number: %d.\n", INT_MAX);
	printf(BLUE "Testing:(\"INT_MIN Number: %%d.\", INT_MIN)\n" RESET);
	printf_length += printf("Real: INT_MIN Number: %d.\n", INT_MIN);
	ft_printf_length += ft_printf("Mine: INT_MIN Number: %d.\n", INT_MIN);
	printf(GREEN "\nLength: printf = %d, ft_printf = %d\n\n" RESET, printf_length, ft_printf_length);
}

void	test_i_specifier(void)
{
	int	printf_length = 0;
	int	ft_printf_length = 0;

	printf(RED "\n----------- TEST: %%i -----------\n\n" RESET);
	printf(BLUE "Testing:(\"Integer: %%i.\", 42)\n" RESET);
	printf_length += printf("Real: Integer: %i.\n", 42);
	ft_printf_length += ft_printf("Mine: Integer: %i.\n", 42);
	printf(BLUE "Testing:(\"INT_MAX Integer: %%i.\", INT_MAX)\n" RESET);
	printf_length += printf("Real: INT_MAX Integer: %i.\n", INT_MAX);
	ft_printf_length += ft_printf("Mine: INT_MAX Integer: %i.\n", INT_MAX);
	printf(BLUE "Testing:(\"INT_MIN Integer: %%i.\", INT_MIN)\n" RESET);
	printf_length += printf("Real: INT_MIN Integer: %i.\n", INT_MIN);
	ft_printf_length += ft_printf("Mine: INT_MIN Integer: %i.\n", INT_MIN);
	printf(GREEN "\nLength: printf = %d, ft_printf = %d\n\n" RESET, printf_length, ft_printf_length);
}

void	test_u_specifier(void)
{
	int	printf_length = 0;
	int	ft_printf_length = 0;

	printf(RED "\n----------- TEST: %%u -----------\n\n" RESET);
	printf(BLUE "Testing:(\"Unigned number: %%u.\", 42)\n" RESET);
	printf_length += printf("Real: Unigned number: %u.\n", 42);
	ft_printf_length += ft_printf("Mine: Unigned number: %u.\n", 42);
	printf(BLUE "Testing:(\"Unigned number: %%u.\", -42)\n" RESET);
	printf_length += printf("Real: Unigned number: %u.\n", -42);
	ft_printf_length += ft_printf("Mine: Unigned number: %u.\n", -42);
	printf(BLUE "Testing:(\"INT_MAX Unigned number: %%u.\", INT_MAX)\n" RESET);
	printf_length += printf("Real: INT_MAX Unigned number: %u.\n", INT_MAX);
	ft_printf_length += ft_printf("Mine: INT_MAX Unigned number: %u.\n", INT_MAX);
	printf(BLUE "Testing:(\"INT_MIN Unigned number: %%u.\", INT_MIN)\n" RESET);
	printf_length += printf("Real: INT_MIN Unigned number: %u.\n", INT_MIN);
	ft_printf_length += ft_printf("Mine: INT_MIN Unigned number: %u.\n", INT_MIN);
	printf(GREEN "\nLength: printf = %d, ft_printf = %d\n\n" RESET, printf_length, ft_printf_length);
}

void	test_x_specifier(void)
{
	int	printf_length = 0;
	int	ft_printf_length = 0;

	printf(RED "\n----------- TEST: %%x -----------\n\n" RESET);
	printf(BLUE "Testing:(\"Hexadecimal (lowercase) number: %%x.\", 42)\n" RESET);
	printf_length += printf("Real: Hexadecimal (lowercase) number: %x.\n", 42);
	ft_printf_length += ft_printf("Mine: Hexadecimal (lowercase) number: %x.\n", 42);
	printf(BLUE "Testing:(\"Hexadecimal (lowercase) number: %%x.\", -42)\n" RESET);
	printf_length += printf("Real: Hexadecimal (lowercase) number: %x.\n", -42);
	ft_printf_length += ft_printf("Mine: Hexadecimal (lowercase) number: %x.\n", -42);
	printf(BLUE "Testing:(\"INT_MAX Hexadecimal (lowercase) number: %%x.\", INT_MAX)\n" RESET);
	printf_length += printf("Real: INT_MAX Hexadecimal (lowercase) number: %x.\n", INT_MAX);
	ft_printf_length += ft_printf("Mine: INT_MAX Hexadecimal (lowercase) number: %x.\n", INT_MAX);
	printf(BLUE "Testing:(\"INT_MIN Hexadecimal (lowercase) number: %%x.\", INT_MIN)\n" RESET);
	printf_length += printf("Real: INT_MIN Hexadecimal (lowercase) number: %x.\n", INT_MIN);
	ft_printf_length += ft_printf("Mine: INT_MIN Hexadecimal (lowercase) number: %x.\n", INT_MIN);
	printf(GREEN "\nLength: printf = %d, ft_printf = %d\n\n" RESET, printf_length, ft_printf_length);
}

void	test_X_specifier(void)
{
	int	printf_length = 0;
	int	ft_printf_length = 0;

	printf(RED "\n----------- TEST: %%X -----------\n\n" RESET);
	printf(BLUE "Testing:(\"Hexadecimal (uppercase) number: %%X.\", 42)\n" RESET);
	printf_length += printf("Real: Hexadecimal (uppercase) number: %X.\n", 42);
	ft_printf_length += ft_printf("Mine: Hexadecimal (uppercase) number: %X.\n", 42);
	printf(BLUE "Testing:(\"Hexadecimal (uppercase) number: %%X.\", -42)\n" RESET);
	printf_length += printf("Real: Hexadecimal (uppercase) number: %X.\n", -42);
	ft_printf_length += ft_printf("Mine: Hexadecimal (uppercase) number: %X.\n", -42);
	printf(BLUE "Testing:(\"INT_MAX Hexadecimal (uppercase) number: %%X.\", INT_MAX)\n" RESET);
	printf_length += printf("Real: INT_MAX Hexadecimal (uppercase) number: %X.\n", INT_MAX);
	ft_printf_length += ft_printf("Mine: INT_MAX Hexadecimal (uppercase) number: %X.\n", INT_MAX);
	printf(BLUE "Testing:(\"INT_MIN Hexadecimal (uppercase) number: %%X.\", INT_MIN)\n" RESET);
	printf_length += printf("Real: INT_MIN Hexadecimal (uppercase) number: %X.\n", INT_MIN);
	ft_printf_length += ft_printf("Mine: INT_MIN Hexadecimal (uppercase) number: %X.\n", INT_MIN);
	printf(GREEN "\nLength: printf = %d, ft_printf = %d\n\n" RESET, printf_length, ft_printf_length);
}


void	test_p_specifier(void)
{
	int		printf_length = 0;
	int		ft_printf_length = 0;
	int		number;
	char	character;
	void	*p;

	printf(RED "\n----------- TEST: %%p -----------\n\n" RESET);
	number = 50;
	character = 'a';
	p = NULL;
	printf(BLUE "Testing:(\"(Address of 50: %%p\", (void *)&number))\n" RESET);
	printf_length += printf("Real: Address of 50: %p\n", (void *)&number);
	ft_printf_length += ft_printf("Mine: Address of 50: %p\n", (void *)&number);
	printf(BLUE "Testing:(\"(Address of 'a': %%p\", (void *)&character))\n" RESET);
	printf_length += printf("Real: Address of 'a': %p\n", (void *)&character);
	ft_printf_length += ft_printf("Mine: Address of 'a': %p\n", (void *)&character);
	printf(BLUE "Testing:(\"(Address of NULL: %%p\", p)\n" RESET);
	printf_length += printf("Real: Address of NULL: %p\n", p);
	ft_printf_length += ft_printf("Mine: Address of NULL: %p\n", p);
	printf(GREEN "\nLength: printf = %d, ft_printf = %d\n\n" RESET, printf_length, ft_printf_length);
}

void	test_all_specifiers(void)
{
	int	printf_length = 0;
	int	ft_printf_length = 0;

	printf(RED "\n----------- TEST: ALL -----------\n\n" RESET);
	printf(BLUE "Testing:(\"%%s%%c%%s%%d%%s%%u%%s%%x\", \"Testing everything: character: \", \'a\', \", then digit: \", 42, \", unsigned number: \", -42, \", hexa number: \", 42)\n" RESET);
	printf_length += printf("Real: %s%c%s%d%s%u%s%x\n", "Testing everything: character: ", 'a', ", then digit: ", 42, ", unsigned number: ", -42, ", hexa number: ", 42);
	ft_printf_length += ft_printf("Mine: %s%c%s%d%s%u%s%x\n", "Testing everything: character: ", 'a', ", then digit: ", 42, ", unsigned number: ", -42, ", hexa number: ", 42);
	printf(GREEN "\nLength: printf = %d, ft_printf = %d\n\n" RESET, printf_length, ft_printf_length);
}

int	main(void)
{
	printf(RED "\n************************* FT_PRINTF TEST *************************\n\n" RESET);
	test_percent_specifier();
	test_c_specifier();
	test_s_specifier();
	test_d_specifier();
	test_i_specifier();
	test_u_specifier();
	test_x_specifier();
	test_X_specifier();
	test_p_specifier();
	test_all_specifiers();
	return (0);
}
