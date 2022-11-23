#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str);
int main (void)
{
int i;
char *s;

s = "   \n  -214748";
i = ft_atoi(s);

printf("%d\n", i);
}