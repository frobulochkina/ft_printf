#include "ft_printf.h"

char		*ft_itoa_x(unsigned int n)
{
	char			*s;
	unsigned int	n2;
	unsigned int	i;

	n2 = (n < 0 ? -n : n);
	i = ft_putnbr_i(n2) + (n < 0 ? 1 : 0);
	if (!(s = (char*)malloc(sizeof(char) * i + 1)))
	{
		free(s);
		return (NULL);
	}
	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
	}
	s[i] = '\0';
	i--;
	while (n2 > 0)
	{
		s[i] = (n2 % 10) + 48;
		n2 /= 10;
		i--;
	}
	return (s);
}

int			ft_atoi_for_ft_printf(char *str)
{
	int		number;

	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '0' || *str == '-' || *str == '\v' ||
			*str == '\f' || *str == '\r')
		str++;
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number);
}
