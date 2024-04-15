int	ft_atoi(char *str)
{
int	i;
int	result;
int sign;

i = 0;
result = 0;
sign = 1;
while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	i++;	
if (str[i] == '+')
	sign = 1;
if (str[i] == '-')
	sign = sign - 2;
if (str[i] == '-' || str[i] == '+')
		i++;	
while (str[i] != '\0')
	{	
		result = result * 10 + str[i] - '0';
		i++;
	}
return (result * sign);	
}
