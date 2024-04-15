#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	match(char *s1, char *s2);


void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}

int	main ()
{
int a;
char str1[50] = "adb.c";
char str2[50] = "a*b.c";

ft_putstr(str1);
ft_putchar('\n');
ft_putstr(str2);
ft_putchar('\n');
a = match(str1, str2);
printf("%d", a);
return (0);
}

