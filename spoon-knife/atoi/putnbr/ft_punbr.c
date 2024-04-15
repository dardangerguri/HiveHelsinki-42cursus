#include <unistd.h>

void ft_putnbr(int number)
{
    int sign;
    int x;

    sign = -1;
if (number == -2147483648)
{
write(1, "-", 1);
ft_putnbr(214748364);
write(1,"8", 1);
}
else
{
if (number < 0)
{
write(1, "-", 1);
number = number * sign;
}
if (number < 10)
{
    x = number + 48;
    write(1, &x, 1);
}
if (number > 9)
{
ft_putnbr(number/10);
ft_putnbr(number % 10);
}
}
}




int main()
{
int a;

a = -23459;
ft_putnbr(a);
return (0);
}