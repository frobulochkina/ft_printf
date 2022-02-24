#include "ft_printf.h"

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void		ft_write_len2(int len2, int flag)
{
	if (flag == 0)
	{
		while (len2 > 0)
		{
			write(1, "0", 1);
			len2--;
		}
	}
	if (flag == 1)
	{
		while (len2 > 0)
		{
			write(1, " ", 1);
			len2--;
		}
	}
}

size_t		ft_putnbr_i(unsigned int len)
{
	size_t	i;

	i = 0;
	while (len >= 10)
	{
		len /= 10;
		i++;
	}
	return (i + 1);
}
